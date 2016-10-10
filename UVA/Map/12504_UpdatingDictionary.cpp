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
void print(char ch, set<string> result) {
	int i = 0;
	if (result.size() > 0) {
		printf("%c", ch);
		for (auto it : result) {
			if (i++ != 0)
				printf(",");
			printf("%s", it.c_str());
		}
		printf("\n");
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t; char str1[150], str2[150];
	scanf("%d", &t); gets(str1);
	string key, val;
	unordered_map<string, string> old, newd;
	set<string> add, rem, upd;
	unordered_map<string, string>::iterator it;
	for (int i = 0; i < t; i++) {
		gets(str1); gets(str2);
		old.clear(); add.clear(); rem.clear(); upd.clear(); newd.clear();
		char *p = strtok(str1, "{:,}");
		while (p) {
			key = string(p);
			p = strtok(0, "{:,}");
			val = string(p);
			old[key] = val;
			p = strtok(0, "{:,}");
		}
		p = strtok(str2, "{:,}");
		while (p) {
			key = string(p);
			p = strtok(0, "{:,}");
			val = string(p); newd[key] = val;
			it = old.find(key);
			if (it == old.end())
				add.insert(key);
			else if (it->second != val)
				upd.insert(key);
			p = strtok(0, "{:,}");
		}

		for (auto it : old)
			if (newd.find(it.first) == newd.end())
				rem.insert(it.first);

		if ((add.size() == 0) && (rem.size() == 0) && (upd.size() == 0)) {
			printf("No changes\n");
		} else {
			print('+', add);
			print('-', rem);
			print('*', upd);
		}
		printf("\n");
	}
}


