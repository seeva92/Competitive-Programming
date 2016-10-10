#include <cstdio>
using namespace std;
int arr[2500], lis[2500], lds[2500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int t, x, val;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		for (int i = 0; i < x; i++) {
			scanf("%d", &arr[i]);
		}
		lis[0] = lds[0] = 1;
		int ans = 0;
		for (int i = x - 1; i >= 0; i--) {
			lis[i] = lds[i] = 1;
			for (int j = i + 1; j < x; j++) {
				if (arr[j] < arr[i] && lis[j] + 1 > lis[i])
					lis[i] = lis[j] + 1;
				if (arr[j] > arr[i] && lds[j] + 1 > lds[i])
					lds[i] = lds[j] + 1;
			}

		}
		for (int i = 0; i < x; i++)
			if (ans < (lis[i] + lds[i] - 1)) ans = lis[i] + lds[i] - 1;

		printf("%d\n", ans);
	}


}
/*#include<algorithm>
#include<cstdio>

using namespace std;

int A[2500], Ma[2500], Mb[2500];
int N, T;

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &A[i]);

		for (int i = N - 1; i >= 0; i--) {
			Ma[i] = 1;
			for (int j = i + 1; j < N; j++) {
				if (A[i] < A[j]) {
					Ma[i] = max(Ma[j] + 1, Ma[i]);
				}
			}
		}
		for (int i = N - 1; i >= 0; i--) {
			Mb[i] = 1;
			for (int j = i + 1; j < N; j++) {
				if (A[i] > A[j]) {
					Mb[i] = max(Mb[j] + 1, Mb[i]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans = max(ans, Ma[i] + Mb[i] - 1);
		}
		printf("%d\n", ans);
	}
}*/