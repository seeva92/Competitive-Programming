#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cstring>
int arr[1010][1010], Farr[1010][1010];
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int t;

	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(arr, 0, sizeof arr); memset(Farr, 0, sizeof Farr);
		vector<unordered_map<int, int>> row(n), col(m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
				row[i][arr[i][j]]++;
				col[j][arr[i][j]]++;
			}

		int max_val = INT_MIN;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				Farr[i][j] = row[i][arr[i][j]] + col[j][arr[i][j]] - 1;

		for (int i = 0; i < n; i++, printf("\n"))
			for (int j = 0; j < m; j++)
				printf("%d ", Farr[i][j]);

	}
}