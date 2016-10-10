#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;
typedef unsigned int uint;
typedef long long LL;

#define FOR(k, a, b) for (int k(a); k < (b); ++k)
#define REP(k, a) for (int k = 0; k < (a); ++k)

uint MOD = 1e9 + 7;

uint inverse(uint a) {
  uint pow = MOD - 2;
  unsigned long long act = a, res = 1;
  while (pow) {
    if (pow & 1) {
      res *= act;
      res %= MOD;
    }
    act *= act;
    act %= MOD;
    pow >>= 1;
  }
  return res;
}

int main(int argc, char **argv) {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  int T, N, K, Z, tmp;
  vector<LL> factorial(1e5 + 2);
  factorial[0] = 1;
  FOR(i, 1, 1e5 + 2)
  factorial[i] = (factorial[i - 1] * i) % MOD;
  scanf("%d", &T);
  assert(T > 0 && T <= 10);
  while (T--) {
    Z = 0;
    scanf("%d %d", &N, &K);
    assert(N > 0 && N <= 1e5);
    assert(K > 0 && K <= 1e5);
    REP(i, N) {
      scanf("%d", &tmp);
      assert(tmp > -1e6 && tmp <= 1e6);
      if (tmp == 0)
        ++Z;
    }
    // sum binom(N,i) i=0..K
    N -= Z;
    LL res = 0;
    REP(i, min(K + 1, N + 1)) if (Z || (K + i) % 2 == 0) {
      LL tmp = factorial[N];
      tmp *= inverse(factorial[i]);
      tmp %= MOD;
      tmp *= inverse(factorial[N - i]);
      tmp %= MOD;
      res += tmp;
    }
    res %= MOD;
    printf("%lld\n", res);
  }
  return 0;
}

// #include <algorithm>
// #include <cstdio>
// #include <iomanip>
// #include <iostream>
// #include <unordered_map>
// #define vi vector<int>
// #define all(v) v.begin(), v.end()
// #define pii pair<int, int>
// #define mp make_pair
// #define ll long long
// using namespace std;
// const long long mod = 1e9 + 7;
// const int MAX = 1e5 + 7;
// ll arr[MAX], iarr[MAX];
// ll inverse(ll a) {
//   ll temp = mod - 2;
//   ll res = 1;
//   while (temp) {
//     if (temp & 1) {
//       res *= a;
//       res %= mod;
//     }
//     a *= a;
//     a %= mod;
//     temp >>= 1;
//   }
//   return res;
// }
// // Learnt factorial and factorial inverse
// void preprocess() {
//   arr[1] = 1;
//   for (ll i = 2; i < MAX; i++) {
//     arr[i] = arr[i - 1] * i;
//     arr[i] %= mod;
//   }
//   iarr[MAX - 1] = inverse(arr[MAX - 1]);
//   for (ll i = MAX - 2; i >= 0; i--) {
//     iarr[i] = iarr[i + 1] * (i + 1);
//     iarr[i] %= mod;
//   }
// }
// int main() {
// #ifndef ONLINE_JUDGE
//   freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
//   freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
// #endif
//   ios::sync_with_stdio(false);
//   cin.tie(0);
//   ll T, N, K, X;
//   preprocess();
//   cin >> T;
//   while (T--) {
//     cin >> N >> K;
//     ll Z = 0;
//     for (ll i = 0; i < N; i++) {
//       cin >> X;
//       if (X == 0)
//         Z++;
//     }
//     N -= Z;
//     ll res = 0, temp;
//     for (ll i = 0; i < min(K + 1, N + 1); i++)
//       if (Z > 0 || ((K + i) % 2 == 0)) {
//         res += ((arr[N] * ((iarr[N - i] * iarr[i]) % mod)) % mod);
//         res %= mod;
//       }
//     cout << res << endl;
//   }
// }
