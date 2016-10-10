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
int hexa[7][7];
bool compute(int &a, int &b, int &c, int &d, int &e, int &f, int &g) {
	for (a = 0; a < 6; a++)
		for (b = 0; b < 6; b++)
			for (c = 0; c < 6; c++)
				for (d = 0; d < 6; d++)
					for (e = 0; e < 6; e++)
						for (f = 0; f < 6; f++)
							for (g = 0; g < 6; g++) {
								if ((hexa[0][(a + 6) % 6] == hexa[6][(g + 3) % 6]) &&
								        (hexa[0][(a + 1) % 6] == hexa[2][(c + 4) % 6]) &&
								        (hexa[0][(a + 2) % 6] == hexa[4][(e + 5) % 6]) &&
								        (hexa[0][(a + 3) % 6] == hexa[1][(b + 6) % 6]) &&
								        (hexa[0][(a + 4) % 6] == hexa[5][(f + 1) % 6]) &&
								        (hexa[0][(a + 5) % 6] == hexa[3][(d + 2) % 6])) {
									if ((hexa[6][(g + 2) % 6] == hexa[2][(c + 5) % 6]) &&
									        (hexa[6][(g + 4) % 6] == hexa[3][(d + 1) % 6]) &&
									        (hexa[1][(b + 1) % 6] == hexa[4][(e + 4) % 6]) &&
									        (hexa[1][(b + 5) % 6] == hexa[5][(f + 2) % 6]) &&
									        (hexa[3][(d + 3) % 6] == hexa[5][(f + 6) % 6]) &&
									        (hexa[2][(c + 3) % 6] == hexa[4][(e + 6) % 6])) {
										return true;
									}

								}
							}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	char c;
	while (true) {
		memset(&hexa[0][0], 0, sizeof hexa);
		for (int i = 0; i < 7; i++) {
			if (c = getchar_unlocked(), c == EOF) {
				return 0;
			}
			else {
				for (int j = 0; j < 6; j++) {
					hexa[i][j] = c - '0';
					c = getchar_unlocked();
				}
			}
		}
		getchar_unlocked(); getchar_unlocked();
		bool flag = false;
		int a, b, c, d, e, f, g;
		flag = compute(a, b, c, d, e, f, g);
		char str[] = "AGCDBFE";
		int arr[] = {a, g, c, e, b, f, d};
		if (flag) {
			printf("PEG   HEX   POSITION\n");
			printf("---   ---   --------\n");
			for (int i = 0; i < 7; i++) {
				printf("%2d%6c     ", i, str[i]);
				int j = 0;
				for (int k = arr[i] % 6; j < 6; j++, k = (k + 1) % 6) {
					// printf(" I: %d K : %d ", (str[i] - 'A'), k);
					printf("%d", hexa[(str[i] - 'A')][k]);
				}
				printf("\n");
			}
		} else {
			printf("No solution possible\n");
		}
		for (int i = 0; i < 36; i++)
			printf("*");
		printf("\n");
		// for (int i = 0; i < 7; i++, cout << '\n')
		// 	for (int j = 0; j < 6; j++)
		// 		cout << hexa[i][j];
	}
}
inline void scanint(int &x)
{
	register int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for (; ((c < 48 || c > 57) && c != '-' && c != EOF); c = getchar_unlocked());
	if (c == EOF) {
		x = -1; return;
	}
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
