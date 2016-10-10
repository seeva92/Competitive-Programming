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
string str;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	getline(cin, str);
	stringstream ss; ss << str;

	int n;
	ss >> n;

	getline(cin, str);
	vector<string> v(10000);
	map<string, int> mp;
	string temp;
	while (n--) {
		mp.clear();
		v.clear();
		int NN = 0;
		while (getline(cin, str), !str.empty()) {
			v[NN++] = str;
		}
		int N = NN / 2;

		for (int i = 0; i < NN; i++)
			for (int j = i + 1; j < NN; j++) {
				mp[v[i]+v[j]]++;
				mp[v[j]+v[i]]++;
			}

		string out;
		int m = -1;
		for(auto it: mp){
			if(it.second>m){
				m = it.second; out = it.first;
			}
		}
		cout<<out<<'\n';
		if(n!=0)
			cout<<'\n';
	}
}



