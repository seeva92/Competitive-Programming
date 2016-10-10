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
	int n;
	deque<int> d;
	while (scanf("%d", &n), n != 0) {
		d.clear();
		for (int i = 1; i <= n; i++)
			d.push_back(i);
		printf("Discarded cards:");
		while (d.size() >= 2) {
			if (d.size() == n)
				printf(" %d", d.front());
			else if (d.size() > 1)
				printf(", %d", d.front());
			d.pop_front();
			d.push_back(d.front());
			d.pop_front();
		}
		printf("\n");
		printf("Remaining card: %d\n", d.front());
	}
}
