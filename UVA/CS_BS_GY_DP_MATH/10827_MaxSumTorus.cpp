#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int arr[500][500];
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int t, n; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < (n << 1); i++) {
			for (int j = 0; j < (n << 1); j++) {
				if (i < n && j < n) {
					scanf("%d", &arr[i][j]);
					arr[i + n][j] = arr[i][j + n] = arr[i + n][j + n] = arr[i][j];
				}
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			}
		}
		int max_value = INT_MIN, curr = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = i; k < (i + n); k++)
					for (int l = j; l < (j + n); l++) {
						curr = arr[k][l];
						if (i > 0) curr -= arr[i - 1][l];
						if (j > 0) curr -= arr[k][j - 1];
						if (i > 0 && j > 0) curr += arr[i - 1][j - 1];
						max_value = curr > max_value ? curr : max_value;
					}
		printf("%d\n", max_value);
	}
}