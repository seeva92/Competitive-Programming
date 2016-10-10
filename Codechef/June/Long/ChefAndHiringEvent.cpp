#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t, k;
  cin >> t;
  while (t--) {
    cin >> k;
    k = k - 1;
    ll res = 0;
    ll i = 1;
    while (k) {
      res += 2 * (k % 5) * i;
      k /= 5;
      i *= 10;
    }
    cout << res << endl;
  }
}
