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
vector<deque<int>> result;
deque<int> q;

void compute(int n, int j) {

	int len = sqrt(n);
	for (int k = j; k <= len; k++) {
		if (n % k == 0) {
			q.push_back(k);
			compute(n / k, k);
			q.pop_back();
		}
	}
	q.push_back(n);
	result.push_back(q);
	q.pop_back();
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, i, j, x;
	result.reserve(2000);
	while (scanf("%d", &n), n != 0) {
		result.clear();
		q.clear();

		compute(n, 2);
		cout << (result.size() - 1) << '\n';
		for (int i = 0, len = result.size() - 1; i < len; i++, printf("\n"))
			for (int j = 0, len1 = result[i].size(); j < len1 && result[i][j] > 1; j++) {
				if (j > 0)
					printf(" ");
				printf("%d", result[i][j]);
			}
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
