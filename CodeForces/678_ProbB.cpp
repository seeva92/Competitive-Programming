#include <climits>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
inline bool get(int temp) {
  if ((temp % 400 == 0) || ((temp % 4 == 0) && (temp % 100 != 0)))
    return true;
  return false;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int val = 1;
  for (int year = 2016; year > 1000; year--) {
    if (get(year)) {
      val = (7 + val - (366 % 7)) % 7;
    } else {
      val = (7 + val - (365 % 7)) % 7;
    }
  }
  for (int year = 1001; year <= n; year++) {
    val += get(year) + 365;
    val %= 7;
  }
  int res = val;
  int isleap = get(n);
  int j = n + 1;
  while (1) {
    val += get(j) + 365;
    val %= 7;
    if (val == res && isleap == get(j)) {
      cout << j << endl;
      break;
    }
    ++j;
  }
}
