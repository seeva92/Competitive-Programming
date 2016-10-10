#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <climits>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
bitset<10007> bs;
void init() {
  bs.set(); bs[0] = bs[1] = 0;
  int len = sqrt(10007) + 10;
  for (int i = 2; i <= len; i++)
    for (int j = i * 2; j <= 10006; j += i )
      bs[j] = 0;
}
ll t, a, b;
int dp[10][10][10][10];
ll compute(ll i, ll j, ll k, ll l) {
  ll res = (i * 1000) + (j * 100) + (k * 10) + l;
  // cout << res << endl;
  if (res == b) return 0;
  if (i > 9 || j > 9 || k > 9 || l > 9 || res > b) return INT_MAX;
  if (dp[i][j][k][l] != -1) return dp[i][j][k][l];

  ll I = bs[res] + compute(i + 1, j, k, l);
  ll J = bs[res] + compute(i, j + 1, k, l);
  ll K = bs[res] + compute(i, j, k + 1, l);
  ll L = bs[res] + compute(i, j, k, l + 1);
  return dp[i][j][k][l] = min(min(I, J), min(K, L));
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  cin >> t;
  while (t--) {
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << compute(a / 1000, (a / 100) % 10, (a / 10) % 10, a % 10) << endl;;
  }
}
