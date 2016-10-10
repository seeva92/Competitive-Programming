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
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	map<set<int>, int> mp;
// 	int a1[] = {100, 101, 102, 103, 488};
// 	int a2[] = {100, 200, 300, 101, 102};
// 	int a3[] = {103, 102, 101, 488, 100};
// 	set<int> s1, s2, s3;
// 	for (int i = 0; i < 5; i++) {
// 		s1.insert(a1[i]); s2.insert(a2[i]);
// 		s3.insert(a3[i]);
// 	}
// 	for (auto it : s1) {
// 		cout << it << " ";
// 	}
// 	for (auto it : s2) {
// 		cout << it << " ";
// 	}
// 	for (auto it : s3) {
// 		cout << it << " ";
// 	}
// 	mp[s1]++; mp[s2]++; mp[s3]++;
// 	for (auto it : mp) {
// 		for (auto it1 : it.first) {
// 			cout << it1 << " ";
// 		}
// 		cout << it.second << '\n';
// 	}

// }
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int x;
	map<set<int>, int> mp;
	set<int> tmp;

	while (n) {
		mp.clear(); tmp.clear();
		for (int i = 0; i < n; i++) {
			tmp.clear();
			for (int j = 0; j < 5; j++) {
				scanf("%d", &x);
				tmp.insert(x);
			}
			mp[tmp]++;
		}
		int high = -1;
		int count = 1;
		for (auto it : mp) {
			if (it.second > high) {
				high = it.second; count = 1;
			} else if (it.second == high) {
				count++;
			}
		}

		printf("%d\n", count * high);
		scanf("%d", &n);
	}
}


