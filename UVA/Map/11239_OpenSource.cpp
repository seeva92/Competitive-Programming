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

bool isProject() {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (isalpha(str[i])) {
			if (!isupper(str[i]))
				return false;
		}
	}
	return true;
}
bool compare(pair<string, int> p1, pair<string, int> p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second)
		return  p1.first <= p2.first;
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	string proj;
	set<string> emp;
	bool flag = false;
	map<string, set<string>> mp;
	set<string> excluded;
	while (getline(cin, str), str != "0") {
		if (str[str.size() - 1] == '\r')
			str.pop_back();

		if (str[0] >= 65 && str[0] <= 90) {
			proj = string(str);
			mp[proj] = emp;
		} else if (str == "1") {
			vector<pair<string, int>> v;
			for (auto it : mp) {
				v.push_back(make_pair(it.first, it.second.size()));
			}
			sort(v.begin(), v.end(), compare);

			for (auto it : v) {
				printf("%s %d\n", it.first.c_str(), it.second);
			}

			mp.clear();
		} else {
			set<string>::iterator stit;
			for (auto &it : mp) {
				stit = it.second.find(string(str));
				if (it.first != proj && stit != it.second.end()) {
					it.second.erase(stit);
					excluded.insert(str);
				}
			}
			if (excluded.find(str) == excluded.end()) {
				mp[proj].insert(str);
			}
		}
	}
}


