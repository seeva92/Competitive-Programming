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
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	string line, str1, str2, str;
	stringstream ss;
	map<string, string> dict;
	map<string, string>::iterator it;
	while (getline(cin, line), line != "") {
		ss << line; ss >> str1; ss >> str2;
		dict[str2] = str1;
		ss.clear();
	}
	while (cin >> str1) {
		it = dict.find(str1);
		if(it != dict.end())
			printf("%s\n",it->second.c_str());
		else
			printf("eh\n");
	}
}


