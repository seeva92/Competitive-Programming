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
	int t, n, x = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n); int arr[n + 1], lis[n + 1], lds[n + 1], width[n + 1];
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

		for (int i = 0; i < n; i++) {
			scanf("%d", &lis[i]); lds[i] = lis[i];
			width[i] = lis[i];
		}
		int inc = 0, dec = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (arr[i] < arr[j] && lis[i] < lis[j] + width[i])
					lis[i] = lis[j] + width[i];
				if (arr[i] > arr[j] && lds[i] < lds[j] + width[i])
					lds[i] = lds[j] + width[i];
			}
			if (inc < lis[i]) inc = lis[i];
			if (dec < lds[i]) dec = lds[i];
		}
		if (inc >= dec)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", x++, inc, dec );
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", x++, dec, inc );
	}

}