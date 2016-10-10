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
const int size = 1010;
char arr[size];
char stk[size][size];
short top[size];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int len, i, j, count, x = 0;
	bool flag = false;
	char c;
	while (scanf("%s", arr), arr[0] != 'e') {
		len = strlen(arr);
		fill(top, top + size, -1);
		for (i = 0; i < len; i++) {
			for (j = 0; j < size; j++) {
				if (top[j] == -1 ) {

					stk[j][++top[j]] = arr[i];
					break;
				}
				else if (stk[j][top[j]] >= arr[i]) {
					stk[j][++top[j]] = arr[i];
					break;
				}
			}
		}
		count = 0;
		for (i = 0; i < size; i++)
			if (top[i] != -1)
				count++;

		printf("Case %d: %d\n", ++x, count);
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
