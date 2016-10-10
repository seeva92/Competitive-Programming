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
#include <queue>
#include <deque>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
struct job {
	int priority, pos;
};
struct Comp {
	bool operator()(job a, job b) {
		if (a.priority < b.priority)
			return true;
		else if (a.priority == b.priority) {
			return a.pos <= b.pos;
		}
		return false;
	}
};
bool isgreater(deque<job> p, int priority) {
	while (!p.empty()) {
		if (p.front().priority > priority)
			return true;
		p.pop_front();
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, t, m;
	scanf("%d", &t);
	while (t--) {
		// priority_queue<job, vector<job>, Comp> p;
		deque<job> p;
		scanf("%d %d", &n, &m);
		int j;
		for (int i = 0; i < n; i++) {
			scanf("%d", &j);
			job jb; jb.priority = j; jb.pos = i;
			p.push_back(jb);
		}
		int mins = 0;

		while (!p.empty()) {
			if (!isgreater(p, p.front().priority)) {
				++mins;
				if (p.front().pos == m) {
					printf("%d\n", mins);
					break;
				}
				p.pop_front();
			}
			else {
				p.push_back(p.front());
				p.pop_front();
			}
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
