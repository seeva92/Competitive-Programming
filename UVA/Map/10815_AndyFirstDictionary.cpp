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
char str[250];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int len = 0, i;
	string tmp; tmp.reserve(100);
	set<string> st;
	while (gets(str)) {
		len = strlen(str); tmp.clear();
		for (i = 0; i < len; i++) {
			if (str[i] >= 65 && str[i] <= 90) {
				tmp += tolower(str[i]);
			} else if (str[i] >= 97 && str[i] <= 122) {
				tmp += str[i];
			} else if (!tmp.empty()) {
				st.insert(tmp); tmp.clear();
			}
		}
		if(i==len && !tmp.empty()){
			st.insert(tmp); tmp.clear();
		}
	}
	for (auto it : st)
		printf("%s\n", it.c_str());
}


