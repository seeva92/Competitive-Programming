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
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
int stk[1010];
int n, x, i, coach = 1, top = -1;

bool compute() {
	while (coach <= n) {
		if (top != -1) {
			if (stk[top] == x) {
				top--; return true;
			}
		} else if (x == coach) {
			coach++;
			return true;
		}
		stk[++top] = coach++;
	}
	if (coach > n) {
		if (stk[top] == x) {
			top--; return true;
		} else
			return false;
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	bool flag = true;
	while (scanint(n), n != 0) {
		while (scanint(x), x != 0) {
			coach = 1;
			top = -1;
			flag = true;
			memset(stk, 0, sizeof stk);

			if (flag)
				flag = compute();
			for (i = 1; i < n; i++) {
				scanint(x);
				if (flag)
					flag = compute();
			}
			if (flag)
				printf("Yes\n");
			else
				printf("No\n");
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
