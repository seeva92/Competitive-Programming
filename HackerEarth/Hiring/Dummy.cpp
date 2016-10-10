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
#include <stack>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
int k, len;

int n;
void compute(int i, string src, string des, string stk, string str, string path) {
	if (i == (2 * des.length())) {
		if (str == des) {
			len = path.length();
			for (k = 0; k < len; k++) {
				putchar_unlocked(path[k]);
			} putchar_unlocked('\n');
		}
		return;
	}
	if (src.length() > 0)
		compute(i + 1, src.substr(1, src.length() - 1), des, stk + src[0], str, path + (i == 0 ? "i" : " i"));
	if (stk.length() > 0 && stk[stk.length() - 1] == des[str.length()])
		compute(i + 1, src, des, stk.substr(0, stk.length() - 1), str + stk[stk.length() - 1], path + " o");
}

// void compute(int i, int j, char stk[], int s, char str[], char path[], int k) {
// 	cout << stk << " " << str << " " << path << '\n';

// 	if (i == 2 * n) {
// 		int x;
// 		for (x = 0; x < n && str[x] == des[x]; x++);
// 		if (x == n) {
// 			for (x = 0; x < k; x++)
// 				putchar_unlocked(path[x]);
// 			putchar_unlocked('\n');
// 		}
// 	}
// 	if (i < n) {
// 		stk[j] = src[i];
// 		if (k == 0) {
// 			path[k] = 'i';
// 			compute(i + 1, j + 1, stk, s, str, path, k + 1);
// 		}
// 		else {
// 			path[k] = ' '; path[k + 1] = 'i';
// 			compute(i + 1, j + 1, stk, s, str, path, k + 2);
// 		}
// 	}
// 	if (i-1 > 0 && stk[i-1] == des[s]) {
// 		str[s] = stk[i - 1]; path[k] = ' '; path[k + 1] = 'o';
// 		compute(i + 1, j - 1, stk, s + 1, str, path, k + 2);
// 	}
// }
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	char stk[1000], str[1000], path[1000];
	char src[1000], des[1000];
	while (scanstring(src), scanstring(des), src[0] != '\0') {
		memset(stk, '\0', sizeof stk);
		memset(str, '\0', sizeof str);
		memset(path, '\0', sizeof path);
		n = strlen(src);
		putchar_unlocked('['); putchar_unlocked('\n');
		if (n == strlen(des)) {
			compute(0, string(src), string(des), string(stk), string(str), string(path));
		}
		putchar_unlocked(']'); putchar_unlocked('\n');

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
