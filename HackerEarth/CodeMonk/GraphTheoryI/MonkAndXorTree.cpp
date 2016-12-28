#include <iostream>
// #include <algorithm>
// #include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, K;
vector<int> v[MAX];
int val[MAX];
int cnt[30 * MAX];
ll res = 0;
void dfs(int i, int p, int xr) {
	xr ^= val[i];
	res += cnt[xr ^ K];
	cnt[xr]++;

	for (auto j : v[i]) {
		if (j != p) {
			dfs(j, i, xr);
		}
	}
	cnt[xr]--;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	int x;
	for (int i = 1; i < N; i++) {
		cin >> x;
		v[x - 1].push_back(i);
		v[i].push_back(x - 1);
	}
	memset(cnt, 0, sizeof cnt);
	res = 0;
	cnt[0] = 1;
	dfs(0, -1, 0);
	cout << res;
}
