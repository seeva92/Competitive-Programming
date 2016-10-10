#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		int arr[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
			}
		int max_value = INT_MIN, curr = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = i; k < n; k++)
					for (int l = j; l < n; l++) {
						curr = arr[k][l];
						if (i > 0) curr -= arr[i - 1][l];
						if (j > 0) curr -= arr[k][j - 1];
						if (i > 0 && j > 0) curr += arr[i - 1][j - 1];
						max_value = max(max_value, curr);
					}
		printf("%d\n", max_value);
	}
}