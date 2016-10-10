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
const int size = 1e6 + 10;
bitset<size> mins;
bool compute(int i, int j) {
	for (int l = i; l < j && l < size; l++)
		if (mins[l] == 1)
			return true;
		else
			mins[l] = 1;
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, m, i, j, k;
	bool flag = false;
	while (scanint(n), scanint(m), n || m) {
		mins.reset();
		flag = false;

		while (n--) {
			scanint(i); scanint(j);
			if (!flag) {
				flag = compute(i, j);
			}
		}

		while (m--) {
			scanint(i); scanint(j); scanint(k);
			if (!flag) {
				while (!flag && i < size && j < size) {
					flag = compute(i, j);
					i += k; j += k;
				}
			}
		}
		if (flag)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
	}
}


// bitset <size> s, e, mins;
// bool compute(int i, int j) {
// 	if (s[i] == 1 || e[j] == 1)
// 		return true;
// 	else {
// 		s[i] = 1;
// 		e[j] = 1;
// 	}


// 	if (e[i] == 1 || mins[i] == 0)
// 		mins[i] = 1;
// 	else
// 		return true;

// 	if (s[j] == 1 || mins[j] == 0)
// 		mins[j] = 1;
// 	else
// 		return true;

// 	for (int l = i + 1; l < j && l < size; l++)
// 		if (mins[l] == 1)
// 			return true;
// 		else
// 			mins[l] = 1;
// 	return false;
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int t, n, m, i, j, k;
// 	bool flag = false;
// 	while (scanint(n), scanint(m), n || m) {
// 		s.reset(); e.reset(); mins.reset();
// 		flag = false;

// 		while (n--) {
// 			scanint(i); scanint(j);
// 			if (!flag) {
// 				flag = compute(i, j);
// 			}
// 		}

// 		while (m--) {
// 			scanint(i); scanint(j); scanint(k);
// 			if (!flag) {
// 				while (!flag && i < size && j < size) {
// 					flag = compute(i, j);
// 					i += k; j += k;
// 				}
// 			}
// 		}
// 		if (flag)
// 			printf("CONFLICT\n");
// 		else
// 			printf("NO CONFLICT\n");
// 	}


// }

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
