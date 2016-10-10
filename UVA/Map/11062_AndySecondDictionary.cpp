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
	string tmp; tmp.reserve(100);
	char str[250];
	int i, len; tmp.clear();
	set<string> st;
	while (gets(str)) {
		len = strlen(str);
		if (!tmp.empty() && tmp[tmp.size() - 1] == '-')
			tmp.pop_back();

		for (i = 0; i < len; i++) {
			if (str[i] >= 65 && str[i] <= 90) {

				tmp += tolower(str[i]);
			}
			else if (str[i] >= 97 && str[i] <= 122) {
				tmp += str[i];
			}
			else if (str[i] == '-')
				tmp += str[i];
			else if (!tmp.empty()) {
				st.insert(tmp);
				tmp.clear();
			}
		}
		if (!tmp.empty() && tmp[tmp.size() - 1] != '-') {
			st.insert(tmp);
			tmp.clear();
		}
	}


	for (auto it : st)
		printf("%s\n", it.c_str());
}


