#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;

long long arr[100100];
long long fact[100100];
long long num[100100];
long long mod = 1e9 + 7;
long long multiply(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a % mod;
    long long mid = multiply(a, b / 2);
    mid = (mid * mid) % mod;
    if (b % 2 == 1)
        mid = (mid * a) % mod;
    return mid;
}
long long f(int n, long long k) {
    if (n == 0) return 1;
    if (k == 0) return 0;
    if (k == 1) return 1;
    if (n == 1) return k % mod;
    return (num[n - 2] * multiply(fact[n - 1], mod - 2)) % mod;
}

int main() {
// #ifndef ONLINE_JUDGE
    // freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
    // freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
// #endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int N, x;
        long long M;
        memset(fact, 0, sizeof fact);
        memset(num, 0, sizeof num);
        scanf("%d %d %ld", &N, &x, &M);
        for (int i = 1; i <= N; i++) {
            scanf("%ld", &arr[i]);
            arr[i] = arr[i] % mod;
        }

        fact[0] = 1;
        for (int i = 1; i <= x; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        long long K = M % mod;
        num[0] = K;
        for (int i = 1; i <= x; i++) {
            num[i] = (num[i - 1] * (K + i)) % mod;
        }

        long long ans = arr[x];
        for (int i = 1; i < x; i++) {
            ans += (arr[x - i] * 1ll * f(i + 1, M)) % mod;
            ans %= mod;
        }
        printf("%ld\n", ans);
    }

}
// #include <iostream>
// #include <math.h>
// #include <map>
// #include <vector>
// #include <stdlib.h>
// #include <memory.h>
// #include <time.h>
// #include <string.h>
// #include <iostream>
// #include <stdio.h>
// #include <algorithm>
// #include <set>
// #include <cassert>

// using namespace std;

// long long mas[111111];
// long long mod = 1e9 + 7;
// long long fact[111111];
// long long dd[111111];

// long long bin_pow(long long b, long long s) {
//     if (s == 0) return 1;
//     if (s == 1) return b % mod;
//     long long d = bin_pow(b, s / 2);
//     d = (d * d) % mod;
//     if (s % 2 == 1)
//         d = (d * b) % mod;
//     return d;
// }



// int main() {
//     ios::sync_with_stdio(0);
//     int t;
//     cin >> t;
//     while (t -- > 0) {
//         int n, c;
//         long long k;
//         cin >> n >> c >> k;// c++;
//         for (int i = 1; i <= n; ++i) {
//             cin >> mas[i];
//             mas[i] %= mod;
//         }

//         fact[0] = 1;
//         for (int i = 1; i <= c; ++i)
//             fact[i] = (fact[i - 1] * i) % mod;

//         dd[0] = k % mod;
//         long long K = k % mod;
//         for (int i = 1; i <= c; ++i)
//             dd[i] = (dd[i - 1] * (K + i)) % mod;


//         long long ans = mas[c];
//         for (int i = 1; i < c; ++i) {
//             ans += (mas[c - i] * 1ll * f(i + 1, k)) % mod;
//             ans %= mod;
//         }
//         cout << ans << "\n";
//     }
//     return 0;
// }