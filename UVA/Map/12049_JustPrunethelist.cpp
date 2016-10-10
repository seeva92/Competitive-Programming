#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, m, x;
	unordered_map<int, int> mp;
	mp.reserve(10000);
	int count = 0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m); count = 0; mp.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &x); mp[x]++;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &x); mp[x]--;
		}
		for (auto it : mp) {
			if (it.second < 1)
				count += (it.second * -1);
			else
				count += it.second;
		}
		printf("%d\n", count);
	}

}
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int t, n, m, x;
// 	int narr[10005], marr[10005];
// 	int count = 0;
// 	scanf("%d", &t);
// 	while (t--) {
// 		scanf("%d %d", &n, &m); count = 0;
// 		memset(narr, 0, sizeof narr); memset(marr, 0, sizeof marr);
// 		for (int i = 0; i < n; i++) {
// 			scanf("%d", &narr[i]);
// 		}
// 		for (int i = 0; i < m; i++) {
// 			scanf("%d", &marr[i]);
// 		}
// 		sort(narr, narr + n); sort(marr, marr + m);
// 		int i = 0, j = 0;

// 		while (i < n && j < m) {
// 			while (i < n && j < m && narr[i] == marr[j]) {
// 				i++; j++;
// 			}
// 			while (i < n && narr[i] < marr[j]) {
// 				count++; i++;
// 			}
// 			while (j < m && marr[j] < narr[i]) {
// 				count++; j++;
// 			}
// 		}
// 		while (i < n) {
// 			i++; count++;
// 		}
// 		while (j < m) {
// 			j++; count++;
// 		}
// 		printf("%d\n", count);
// 	}
// }

