#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <deque>
#include <stack>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, s, q, qi, d;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &s, &q);
		stack<int> stk;
		deque<int> v[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &qi);
			for (int j = 0; j < qi; j++) {
				scanf("%d", &d);
				v[i].push_back(d);
			}
		}
		int mins = 0;
		int x = 0;
		for (int i = 0; i < n; i = (i + 1) % n) {
			while (!stk.empty()) {
				if (stk.top() == (i + 1)) {
					stk.pop(); mins += 1;
				}
				else if (v[i].size() < q) {
					v[i].push_back(stk.top());
					stk.pop();
					mins += 1;
				} else
					break;
			}

			while (v[i].size() > 0 && stk.size() < s) {
				stk.push(v[i].front());
				v[i].pop_front();
				mins += 1;
			}

			for (x = 0; x < n && v[x].size() == 0 && stk.size() == 0; x++);
			if (x == n)
				break;
			mins += 2;
		}
		printf("%d\n", mins);
	}
}
