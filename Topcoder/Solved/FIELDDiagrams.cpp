#line 5 "FIELDDiagrams.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class FIELDDiagrams {
public:
	long long countDiagrams(int fieldOrder) {
		int n = fieldOrder;
		ll dp[n + 1][n + 1];
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			ll sum = 0;
			for (int j = 0; j <= i; j++) {
				sum += dp[i - 1][j];
				dp[i][j] = sum;
			}
		}
		ll res = 0;
		for (int i = 0; i <= n; i++) res += dp[n][i];
		return res - 1;
	}
};
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
// 	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
// #endif
// 	FIELDDiagrams f;
// 	cout << f.countDiagrams(5);
// }


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
