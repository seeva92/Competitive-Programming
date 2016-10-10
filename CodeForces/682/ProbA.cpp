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
  ll n, m;
  cin >> n >> m;
  ll l = min(n, m), r = max(n, m);
  ll res = 0;
  for (ll i = 1; i <= l; i++) {
    ll temp = (i / 5 + 1) * 5;
    ll diff = temp - i;
    if (1 <= diff && diff <= r) {
      res++;
      res += (r - diff) / 5;
    }
  }
  cout << res << endl;
}
