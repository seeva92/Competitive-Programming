#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("E:\\1.txt", "r", stdin);
  freopen("E:\\2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, x;
  cin >> n;
  int a = INT_MAX, b = INT_MIN;
  for (size_t i = 0; i < n; i++) {
    cin >> x;
    if (a > x)
      a = x;
    if (b < x)
      b = x;
  }
}
