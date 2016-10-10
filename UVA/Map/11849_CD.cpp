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
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, m, nm, i, j;
	while (scanf("%d %d", &n, &m), n || m) {
		int jack[n], jill[m];
		int count = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &jack[i]);

		for (j = 0; j < m; j++)
			scanf("%d", &jill[j]);

		i = 0, j = 0;
		while (i < n && j < m) {
			while (i < n && jack[i] < jill[j])
				i++;
			while (j < m && jack[i] > jill[j])
				j++;
			while (i < n && j < m && jack[i] == jill[j]) {
				i++; j++; count++;
			}
		}
		printf("%d\n", count);
	}


}


