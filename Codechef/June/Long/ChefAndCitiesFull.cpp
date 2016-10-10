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
const long long mod = 1e9 + 7;
const long long MAX = 1e5 + 7;
ll arr[MAX], prod[MAX];
long double digit[MAX];
long double sum = 0;
ll product = 1;

using namespace std;
inline ll inverse(ll a) {
  ll b = mod - 2;
  ll res = 1;
  while (b) {
    if (b & 1)
      res = res * a;
    a = a * a;
    res %= mod;
    a %= mod;
    b >>= 1;
  }
  return res;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Q, t, p, R;
  ll v;
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> arr[i];
  int n = sqrt(N + 0.0) + 1;
  // Precompute
  for (int i = 1; i <= n; i++) {
    product = 1;
    sum = 0.0;
    for (int j = 1; j <= N; j += i) {
      product = product * arr[j] % mod;
      sum += log10(arr[j]);
    }
    prod[i] = product;
    digit[i] = sum;
  }
  // Query

  cin >> Q;
  while (Q--) {
    cin >> t;
    if (t == 1) {
      cin >> p >> v;
      ll inv = inverse(arr[p]);
      long double sub = log10(arr[p] + 0.0);
      long double add = log10(v + 0.0);
      if (p == 1) {
        for (int i = 1; i <= n; i++) {
          prod[i] *= inv;
          prod[i] %= mod;
          prod[i] *= v;
          prod[i] %= mod;
          digit[i] -= sub;
          digit[i] += add;
        }
      } else {
        int temp = min(p - 1, n);
        for (int i = 1; i <= temp; i++) {
          if ((p - 1) % i == 0) {
            prod[i] *= inv;
            prod[i] %= mod;
            prod[i] *= v;
            prod[i] %= mod;
            digit[i] -= sub;
            digit[i] += add;
          }
        }
      }
      arr[p] = v;
    } else {
      cin >> R;
      if (R <= n) {
        int dig = (int)pow(10, digit[R] - floor(digit[R]) + 1e-11);
        if (dig == 10)
          dig = 1;
        cout << dig << " " << prod[R] << endl;
      } else {
        sum = 0.0;
        product = 1;
        for (int i = 1; i <= N; i += R) {
          product = (product * arr[i]) % mod;
          sum += log10(arr[i]);
        }
        int dig = (int)pow(10, sum - floor(sum) + 1e-11);
        if (dig == 10)
          dig = 1;
        cout << dig << " " << product << endl;
      }
    }
  }
}
