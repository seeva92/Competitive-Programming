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
inline ll gcd(ll a, ll b) {
  ll temp;
  while (b) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, a, b, p, q;
  cin >> n >> a >> b >> p >> q;
  ll aa = n / a, bb = n / b, cc = n / (a / gcd(a, b) * b);
  aa -= cc;
  bb -= cc;
  cout << (aa * p) + (bb * q) + (cc * max(p, q)) << endl;
}
