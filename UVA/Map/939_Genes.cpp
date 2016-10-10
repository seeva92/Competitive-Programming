#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
string dom = "dominant";
string rec = "recessive";
string non = "non-existent";
char str1[25], str2[25];
map<string, string> gmap;
multimap<string, string> cpmap;
map<string, string> result;

string findgene(string person) {
	if (gmap.find(person) != gmap.end())
		return gmap[person];

	pair<multimap<string,string>::iterator,multimap<string,string>::iterator> ret = cpmap.equal_range(person);
	multimap<string,string>::iterator it1 = ret.first;

	string p1 = findgene(it1->second);
	string p2 = findgene(next(it1)->second);
	// cout<<p1<<" "<<p2<<'\n';
	if (p1 == p2)
		return p1;
	else if ((p1 == dom && p2 == rec) || (p2 == dom && p1 == rec))
		return dom;
	else if ((p1 == dom && p2 == non) || (p1 == non && p2 == dom))
		return rec;
	else if ((p1 == rec && p2 == non) || (p2 == rec && p1 == non))
		return non;
}
void compute() {
	for (auto it : result) {
		if (it.second == "")
			result[it.first] = findgene(it.first);
		printf("%s %s\n", (it.first).c_str(),result[it.first].c_str());
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n;

	scanf("%d", &n);

	while (n--) {
		scanf("%s %s", &str1, &str2);
		if ((strcmp(str2, dom.c_str()) == 0) || (strcmp(str2, rec.c_str()) == 0) || (strcmp(str2, non.c_str()) == 0)) {
			gmap[str1] = str2;
			result[str1] = str2;
		} else {
			cpmap.insert(make_pair(str2, str1));
			result[str1] = ""; result[str2] = "";
		}
	}
	// for(auto it: gmap)
	// 	cout<<it.first<<" "<<it.second<<'\n';
	// for(auto it:result)
	// 	cout<<it.first<<" "<<it.second<<'\n';
	compute();
}


