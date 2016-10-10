#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int alpha[26];
char str[7];
int i, len;
bool flag = false;
map<string, int> mp[5];
string letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
string temp = "";
map<string, int> result;
void compute() {
	for (i = 0; i < 26; i++)
		mp[0][letters[i]] = i + 1;

	int idx = 27;
	for (i = 1; i <= 4; i++) {
		for (map<string, int>::iterator it = mp[i - 1].begin(); it != mp[i - 1].end(); it++) {
			temp = it->first;
			len = temp.length();
			for (char j = temp[len - 1] + 1; j <= 'z'; j++) {
				mp[i][(temp + j)] = idx++;
			}
		}
	}
	for (i = 0; i <= 4; i++) {
		for (map<string, int>::iterator it = mp[i].begin(); it != mp[i].end(); it++) {
			result[it->first] = it->second;
		}
	}

	// for (map<string, int>::iterator it = result.begin(); it != result.end(); it++) {
	// 	cout << it->first << " " << it->second << '\n';
	// }


}
void efficient() {
	queue<string> q;
	for (i = 0; i < 26; i++)
		q.push(letters[i]);
	int count = 1;
	string s;
	while (!q.empty()) {
		s = q.front();
		q.pop();
		result[s] = count++;
		if (s.size() == 5)
			continue;

		for (char j = s[s.size() - 1] + 1; j <= 'z'; j++)
			q.push(s + j);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	efficient();
	while (scanf("%s", &str) != EOF) {
		printf("%d\n", result[string(str)]);
	}
}


