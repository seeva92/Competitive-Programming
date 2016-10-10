#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
ll arr[2007];
int n;
// ll dp[2007][2007];
int mem[2007][2007];
// ll compute(int i, int j, int a) {
// 	if (i > j || i == n || j < 0) return 0;
// 	if (dp[i][j] != -1) return dp[i][j];
// 	ll f = (arr[i] * a) + compute(i + 1, j, a + 1);
// 	ll b = (arr[j] * a) + compute(i, j - 1, a + 1);
// 	dp[i][j] = f > b ? f : b;
// 	return dp[i][j];
// }
/*int solve( int a , int b )
{
  	int &ans = interval[a][b] ;
	if( ans )
		return ans ;
	if( a == b )
		return n * treats[a] ;
	int age = a + n - b ;
	ans = max( age * treats[a] + solve( a + 1 , b ) , age * treats[b] + solve( a , b - 1 ) ) ;
	return ans ;

}*/
int compute(int n) {
	for (int i = 0; i < n; i++ ) mem[i][i] = n * arr[i];
	int f, b, a;
	for (int i = n - 2; i >= 0; i--)
		for (int j = i + 1; j < n; j++) {
			a = n + i - j;
			f = arr[i] * a + mem[i + 1][j];
			b = arr[j] * a + mem[i][j - 1];
			mem[i][j] = f > b ? f : b;
		}
	return mem[0][n - 1];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	// memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << compute(n) << endl;

}