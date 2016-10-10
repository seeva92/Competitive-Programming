// BEGIN CUT HERE

// END CUT HERE
#line 5 "DivFreed2.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[100007][17];
int mod = (int(1e9)) + 7;
class DivFreed2 {

public:
	int count(int n, int k) {
		dp[1][0] = 1;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= k; j++) {
				sum += dp[j][i - 1];
				sum %= mod;
			}
			for (int j = 1; j <= k; j++) {
				int sum2 = 0;
				for (int z = j + j; z <= k; z += j) {
					sum2 += dp[z][i - 1]; sum2 %= mod;
				}
				dp[j][i] = sum - sum2;
				dp[j][i] += mod;
				dp[j][i] %= mod;
			}
		}

		int res = 0;
		for (int i = 1; i <= k; i++) {
			res += dp[i][n]; res %= mod;
		}
		return res;
	}
};
// int main() {
// 	freopen("/home/shiva/zearning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// }
