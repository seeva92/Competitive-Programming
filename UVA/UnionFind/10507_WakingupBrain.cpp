#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, m, years; char conn[5];
	while (scanf("%d", &n) != EOF) {
		set<int> awaken;
		scanf("%d", &m); scanf("%s", &conn);
		awaken.insert(conn[0] - 'A'); awaken.insert(conn[1] - 'A'); awaken.insert(conn[2] - 'A');
		vector<int> v[26];
		while (m--) {
			scanf("%s", conn); v[conn[0] - 'A'].push_back(conn[1] - 'A');
			v[conn[1] - 'A'].push_back(conn[0] - 'A');
		}
		years = 0;
		bool flag = false; int nocurr;
		while ((int)awaken.size() != n) {
			vector<int> woke;
			for (int i = 0; i < 26; i++) {
				nocurr = 0;
				if (awaken.find(i) == awaken.end()) {
					for (int j = 0; j < (int)v[i].size(); j++) {
						if (awaken.find(v[i][j]) != awaken.end()) nocurr++;
					}
				}
				if (nocurr >= 3) woke.push_back(i);
			}
			for (auto it : woke)
				awaken.insert(it);
			if ((int)woke.size() < 1) { break;}
			years++;
		}
		if ((int)awaken.size() == n) printf("WAKE UP IN, %d, YEARS\n", years);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}
}