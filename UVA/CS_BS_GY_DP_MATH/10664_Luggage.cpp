#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
char str[5000];
vector<int> v;
int dp[25][210];
int compute(int n, int W, int took) {
	if (n < 0 || W <= 0) return took;
	if (dp[n][took] != -1) return dp[n][took];
	if (v[n] > W)
		return compute(n - 1, W, took);
	return dp[n][took] = max(compute(n - 1, W - v[n], took + v[n]), compute(n - 1, W, took));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int m; scanf("%d", &m); gets(str);
	while (m--) {
		gets(str);
		char * p = strtok(str, " ");
		int x;
		long sum = 0;
		v.clear();
		while (p != NULL) {
			sscanf(p, "%d", &x); v.push_back(x);
			sum += x;
			p = strtok(NULL, " ");
		}
		// for (auto it : v) printf("%d ", it);

		if (sum % 2 != 0) printf("NO\n");
		else {
			memset(dp, -1, sizeof dp);
			if (compute(int(v.size()) - 1, sum / 2, 0) * 2 == sum)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

}