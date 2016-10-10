#include <climits>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const long long mod = (long long)1e9;
using namespace std;
ll arr[100007];
ll Rarr[100007];
int t, p, f, R, N, Q;
ll query() {
  ll total = 1;
  for (int i = 1; i <= N; i += R) {
    total = (total * arr[i]) % mod;
  }
  return total;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> arr[i];
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> p >> f;
      arr[p] = f;
    } else {
      cin >> R;
      cout << query() << endl;
    }
  }
}
