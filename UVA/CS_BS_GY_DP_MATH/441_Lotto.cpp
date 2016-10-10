#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int k, i, arr[15];
int a, b, c, d, e, f;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	scanf("%d", &k);
	while (k != 0) {
		for (i = 0; i < k; i++) scanf("%d", &arr[i]);
		for (a = 0; a < k; a++)
			for (b = a + 1; b < k; b++)
				for (c = b + 1; c < k; c++)
					for (d = c + 1; d < k; d++)
						for (e = d + 1; e < k; e++)
							for (f = e + 1; f < k; f++)
								printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
		scanf("%d", &k);
		if (k) printf("\n");
	}

}