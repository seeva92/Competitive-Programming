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
int edges[(1 << 16) + 10];
int sum[(1 << 16) + 10];
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
	while (c < 33)
		c = getchar_unlocked();
	while (c >= 33)
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
	while (c < 33)
		c = getchar_unlocked();
	while (c >= 33 && c != '\n' && c != '\r')
	{
		str[i] = c;
		c = getchar_unlocked();
		i = i + 1;
	}

	str[i] = '\0';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n;

	while (cin >> n) {
		int count = 1 << n;
		for (int i = 0; i < count; i++)
			// scanint(edges[i]);
			cin >> edges[i];
		for (int i = 0; i < count; i++) {
			sum[i] = 0;
			for (int j = 0; j < n; j++) {
				sum[i] += edges[(i ^ (1 << j))];
			}
		}

		int total = INT_MIN;
		for (int i = 0; i < count; i++)
			for (int j = 0; j < n; j++) {
				if (total < (sum[i] + sum[i ^ (1 << j)]))
					total = (sum[i] + sum[i ^ (1 << j)]) ;
			}

		// printf("%d\n", total);
		cout << total << '\n';
	}

}

