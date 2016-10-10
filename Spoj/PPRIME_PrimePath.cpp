#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <bitset>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
bitset<10007> bs, v;
void init() {
    bs.set(); bs[0] = bs[1] = 0;
    int len = sqrt(10007) + 10;
    for (int i = 2; i <= len; i++) {
        if (bs[i]) {
            for (int j = i * 2; j <= 10006; j += i )
                bs[j] = 0;
        }
    }
}
ll t, a, b;
int digit[4];
void update(ll x) {
    int i = 3;
    while (x > 0) {
        digit[i--] = x % 10;
        x /= 10;
    }
}
ll convert() {
    ll result = 0;
    for (int i = 0, j = 1000; i <= 3; i++, j /= 10)
        result = result + (digit[i] * j);
    return result;
}
ll compute() {
    v.reset();
    queue<pair<ll, ll>> q; q.push({a, 1});
    bool flag = false;
    while (!q.empty()) {
        ll res = q.front().first, lvl = q.front().second; q.pop();
        if (v[res]) {
            continue;
        }
        v[res] = 1;
        if (res == b) return lvl - 1;
        for (int i = 0; i <= 3; i++) {
            update(res);
            for (int j = 0; j <= 9; j++) {
                digit[i] = j;
                ll temp = convert();
                if (temp >= 1000 && bs[temp])
                    q.push({temp, lvl + 1});
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
    freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll result = compute();
        ll result = memoise(b / 1000, (b / 100) % 10, (b / 10) % 10, b % 10);
        if (result >= 0) cout << result << endl;
        else cout << "Impossible" << endl;
    }
}
