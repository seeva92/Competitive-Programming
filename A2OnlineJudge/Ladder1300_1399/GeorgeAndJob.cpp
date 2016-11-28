#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, M, K;
ll arr[5007], dp[5007][5007], x;
class GeorgeAndJob
{
public:
	GeorgeAndJob() {
		cin >> N >> M >> K;
		memset(arr, 0, sizeof arr);
		for (int i = 0; i < N; i++) {
			cin >> x;
			arr[i + 1] = arr[i] + x;
		}

		compute();
	}
	void compute() {
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= K; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j > 0 && i - M >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - M][j - 1] + (arr[i] - arr[i - M]));
				}
			}
		}

		cout << dp[N][K];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	GeorgeAndJob g;
}
