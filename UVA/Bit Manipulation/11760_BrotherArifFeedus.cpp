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
#include <bitset>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
bitset < int(1e4 + 10) > rows, columns;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, r, c;
	int i, j;
	int x = 1;
	while (scanint(r), scanint(c), scanint(n), r || c || n) {
		rows.reset(); columns.reset();
		while (n--) {
			scanint(i); scanint(j);
			rows[i] = 1; columns[j] = 1;
		}
		scanint(i); scanint(j);
		printf("Case %d: ", x++);
		if (rows[i] == 0 && columns[j] == 0)
			printf("Escaped again! More 2D grid problems!\n");
		else if (i - 1 >= 0 && rows[i - 1] == 0 && columns[j] == 0)
			printf("Escaped again! More 2D grid problems!\n");
		else if (j - 1 >= 0 && rows[i] == 0 && columns[j - 1] == 0)
			printf("Escaped again! More 2D grid problems!\n");
		else if (i + 1 < r && rows[i + 1] == 0 && columns[j] == 0)
			printf("Escaped again! More 2D grid problems!\n");
		else if (j + 1 < c && rows[i] == 0 && columns[j + 1] == 0)
			printf("Escaped again! More 2D grid problems!\n");
		else
			printf("Party time! Let's find a restaurant!\n");
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
