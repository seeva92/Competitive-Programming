#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n, m, x, curr, i, j, ii, jj;
	int cas = 1;
	while (scanf("%d", &n) != EOF && n != 0) {
		vi arr(n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		sort(arr.begin(), arr.end());
		scanf("%d", &m);
		printf("Case %d:\n", cas++);
		while (m--) {
			curr = INT_MAX;
			scanf("%d", &x);
			i = 0, j = n - 1;
			int diff = INT_MAX;
			while (i < j  && curr != x) {
				if (diff > abs(x - (arr[j] + arr[i]))) {
					curr = arr[j] + arr[i];
					diff = abs(x - (arr[j] + arr[i]));
				}
				// printf("%d\n", curr);
				if (x < (arr[j] + arr[i]))
					j--;
				else
					i++;
			}
			printf("Closest sum to %d is %d.\n", x, curr );
		}

	}

}