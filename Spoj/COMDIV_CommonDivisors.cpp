#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 7;
bitset<MAX> bs;
vi v;
void init() {
	bs.set(); bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX; i++ ) {
		if (bs[i]) {
			for (int j = i * 2; j < MAX; j += i)
				bs[j] = 0;
			v.push_back(i);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int len = v.size();
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int g = __gcd(a, b);
		if (g == 1) cout << "1\n";
		else {
			int result = 1;
			for (int i = 0; g && (i < len) && (v[i] <= g); i++) {
				int cnt = 0;
				while (g % v[i] == 0) {
					cnt++;
					g /= v[i];
				}
				result *= (cnt + 1);
			}
			if (g > 1) result *= 2;
			cout << result << '\n';
		}
	}
}
