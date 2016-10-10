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
#include <deque>
#include <unordered_map>
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
	int t, m, k, x = 1;
	char str[10];
	unordered_map<int, int> teamMap(2000);
	int num;
	while (scanf("%d", &t), t != 0) {
		teamMap.clear();
		for (int i = 1; i <= t; i++) {
			scanf("%d", &m);
			for (int j = 1; j <= m; j++) {
				scanf("%d", &k);
				teamMap[k] = i;
			}
		}
		vector<int> d[t + 5];
		vector<int> o;
		printf("Scenario #%d\n", x); ++x;
		int f = 0;
		while (scanf("%s", &str), str[0] != 'S') {
			scanf("%d", &k);

			if (str[0] == 'E') {
				num = teamMap[k];
				if (d[num].size() == 0) {
					o.push_back(num);
				}
				d[num].push_back(k);
			} else {
				num = o[f];
				printf("%d\n", d[num][0]);
				d[num].erase(d[num].begin());
				if (d[num].size() == 0)
					f++;
			}
		}
		printf("\n");
	}
}


inline void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-' && c != EOF); c = getchar_unlocked());
	if (c == '-') {neg = 1; c = getchar_unlocked();}
	for (; c > 47 && c < 58; c = getchar_unlocked()) {x = (x << 1) + (x << 3) + c - 48;}
	if (neg) x = -x;
}
inline void scanstring(char *str)
{
	register char c = 0;
	register int i = 0;
	while (c < 33 && c != EOF)
		c = getchar_unlocked();
	while (c != EOF && c >= 33)
	{
		str[i] = c;
		c = getchar_unlocked();
		i = i + 1;
	}

	str[i] = '\0';
}
inline void scanline(char *str)
{
	register char c = 0;
	register int i = 0;
	while (c < 33 && c != EOF)
		c = getchar_unlocked();
	while (c != EOF && c >= 32 && c != '\n' && c != '\r')
	{
		str[i] = c;
		c = getchar_unlocked();
		i = i + 1;
	}

	str[i] = '\0';
}
