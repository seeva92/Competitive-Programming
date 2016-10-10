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
#include <queue>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
struct task {
	int dur;
	int i;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int c, n, t, m;
	int dur;
	char str[10];
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d %d", &n, &t, &m);
		deque<int> left, right;
		for (int i = 0; i < m; i++) {
			scanf("%d %s", &dur, &str);
			task tsk;
			tsk.dur = dur;
			if (str[0] == 'l') {
				tsk.i = i;
				left.push_back(tsk);
			}
			else {
				right.push_back(tsk);
			}
		}
		queue<int> boat;
		vector<int> res(m);

		bool side = false;
		int mins = 0;
		while (left.size() != 0 || right.size() != 0) {
			while (!boat.empty())
				boat.pop();
			if (!side) {
				if (!left.empty() && !right.empty() && left.front() > right.front()) {

				}
				if (!left.empty {
				if (mins < tasks.front().dur)
						mins = tasks.front().dur;
					mins += t;
					side = !side; continue;
				}
				while ((!tasks.empty()) && (!tasks.front().flag) && (boat.size() < n)) {
				if (boat.empty()) {
						mins = mins < tasks.front().dur ? mins + (tasks.front().dur - mins) : mins;
						boat.push(tasks.front().dur); tasks.pop_front();
					} else if (mins >= tasks.front().dur) {
						boat.push(tasks.front().dur); tasks.pop_front();
					} else
						break;
				}

			} else {
				if (!(tasks.front().flag)) {
					if (mins < tasks.front().dur)
						mins = tasks.front().dur;
					mins += t;
					side = !side; continue;
				}
				while ((!tasks.empty()) && (tasks.front().flag) && (boat.size() < n)) {
					if (boat.empty()) {
						mins = mins < tasks.front().dur ? mins + (tasks.front().dur - mins) : mins;
						boat.push(tasks.front().dur); tasks.pop_front();
					} else if (mins >= tasks.front().dur) {
						boat.push(tasks.front().dur); tasks.pop_front();
					} else
						break;
				}
			}
			//Adding t minutes
			side = !side;
			mins += t;

		}
		while (!boat.empty()) {
			printf("%d\n", mins);
			boat.pop();
		}

		if (c != 0)
			printf("\n");

	}

}
