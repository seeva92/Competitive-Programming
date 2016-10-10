#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>
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
  ll n;
  cin >> n;
  ll x = 1234567, y = 123456, z = 1234;
  bool flag = false;
  for (ll i = 0; i * x <= n; i++) {
    for (ll j = 0; (i * x + j * y) <= n; j++) {
      ll temp = n - (i * x + j * y);
      if (temp % z == 0) {
        flag = true;
        break;
      }
    }
    if (flag)
      break;
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
