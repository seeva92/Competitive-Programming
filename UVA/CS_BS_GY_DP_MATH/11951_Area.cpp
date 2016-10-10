#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
long arr[110][110];
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	long t, n, m, K;
	int x = 1;
	scanf("%ld", &t);
	while (t--) {
		scanf("%ld %ld %ld", &n, &m, &K);

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				scanf("%ld", &arr[i][j]);
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			}
		int max_plot = INT_MIN, area = 0; long max_cost = 0, curr = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = i; k < n; k++)
					for (int l = j; l < m; l++) {
						curr = arr[k][l];
						if (i > 0) curr -= arr[i - 1][l];
						if (j > 0) curr -= arr[k][j - 1];
						if (i > 0 && j > 0) curr += arr[i - 1][j - 1];
						area = (l - j + 1) * (k - i + 1);
						if (curr <= K) {
							if (max_plot < area) {
								max_plot = area;
								max_cost = curr;
							} else if (max_plot == area) {
								max_cost = curr < max_cost ? curr : max_cost;
							}
						}
					}
		printf("Case #%d: %d %ld\n", x++, max_plot == INT_MIN ? 0 : max_plot, max_cost);

	}
}