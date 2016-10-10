#include <cstdio>
#include <algorithm>
#include <cstring>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int arr[107][107];
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int t, h, w;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &h, &w);
		memset(arr, 0, sizeof arr);
		int i, j;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				scanf("%d", &arr[i][j]);
		int left = 0, right = 0;
		for (i = 1; i < h; i++)
			for (j = 0; j < w; j++) {
				left = right = 0;
				if (j - 1 >= 0) left = arr[i - 1][j - 1];
				if (j + 1 < w) right = arr[i - 1][j + 1];
				arr[i][j] += max(left, max(right, arr[i - 1][j]));
			}
		int total = 0;
		for (i = 0; i < w; i++)
			if (total < arr[h - 1][i]) total = arr[h - 1][i];
		printf("%d\n", total);
	}

}

T  D
T1 D1
T1 D3
T1 D2
T2 D2
T2 D1
T2 D3
T3 D1
T3 D2
T3 D3

T1 D3
T2 D1
T3 D2