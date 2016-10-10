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
#include <list>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
inline void scanint(int &);
inline void scanstring(char *);
inline void scanline(char *);
char line[100010];
struct Pos {
	int start, end;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int len = 0, len1 = 0, i = 0, j = 0;
	int start, idx;
	while (scanstring(line), line[0] != '\0') {
		len = strlen(line);
		i = 0;
		j = -1;
		start = 0;
		idx = 0;
		map<int, Pos> mp;
		bool flag = true;
		while (idx < len) {
			start = idx;
			for (; idx < len && line[idx] != ']' && line[idx] != '['; idx++);

			if (start < idx) {
				if (flag)
					mp[i++] = Pos{start, idx - 1};
				else
					mp[j--] = Pos{start, idx - 1};
			}

			for (; idx < len && (line[idx] == '[' || line[idx] == ']'); idx++);
			if (line[idx - 1] == ']') {
				flag = true;
			} else if (line[idx - 1] == '[') {
				flag = false;
			}
		}

		for (map <int, Pos>::iterator it = mp.begin() ; it != mp.end(); it++) {
			j = it->second.end;
			for (i = it->second.start; i <= j; i++)
				putchar_unlocked(line[i]);
		}
		putchar_unlocked('\n');
	}



}
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int len = 0, len1 = 0, i = 0, j = 0;

// 	while (scanstring(line), line[0] != '\0') {
// 		len = strlen(line);
// 		i = 0;

// 		list<char> v;
// 		list<char>::iterator it = v.begin();
// 		for (i = 0; i < len; i++) {
// 			if (line[i] == ']') {
// 				it = v.end();
// 			} else if (line[i] == '[') {
// 				it = v.begin();
// 			} else {
// 				v.insert(it, line[i]);
// 			}
// 		}

// 		for (it = v.begin() ; it != v.end(); it++) {
// 			putchar_unlocked(*it);
// 		}
// 		putchar_unlocked('\n');
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int len = 0, len1 = 0, i = 0, j = 0;

// 	while (scanstring(line), line[0] != '\0') {
// 		len = strlen(line);
// 		i = 0;

// 		deque<string> v;
// 		string str;
// 		bool flag = true;
// 		while (i < len) {
// 			while (i < len && (line[i] != '[' && line[i] != ']'))
// 				str.push_back(line[i++]);

// 			if (flag)
// 				v.push_back(str);
// 			else
// 				v.push_front(str);
// 			str = "";
// 			if (line[i] == ']') {
// 				flag = true;
// 			} else if (line[i] == '[') {
// 				flag = false;
// 			}
// 			i++;

// 		}
// 		len = (int)v.size();
// 		for (i = 0; i < len; i++) {
// 			len1 = v[i].size();
// 			for (j = 0; j < len1; j++) {
// 				putchar_unlocked(v[i][j]);
// 			}
// 		}
// 		putchar_unlocked('\n');
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
