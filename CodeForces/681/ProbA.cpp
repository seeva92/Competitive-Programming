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
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, b, f;
  cin >> n;
  string str;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    cin >> str >> b >> f;
    if (b >= 2400 && b < f)
      flag = true;
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}
