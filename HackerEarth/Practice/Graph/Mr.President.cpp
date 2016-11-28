#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
typedef vector<long long> vi;
long long n, m, k, a, b, c;
const long long MAX = 1000007;
vector<pair<long long, pair<long long, long long>>> edges;
long long parent[MAX], rnk[MAX];
void init() {
	for (long long i = 0; i < MAX; i++ ) {
		parent[i] = i;
		rnk[i] = 0;
	}
}
long long findSet(long long i) { return parent[i] == i ? i : parent[i] = findSet(parent[i]);}
bool unionfd(long long i, long long j) {
	long long x = findSet(i); long long y = findSet(j);
	if (x != y) {
		if (rnk[x] < rnk[y]) parent[x] = y;
		else {
			parent[y] = x;
			if (rnk[x] == rnk[y]) rnk[x]++;
		}
		return true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> n >> m >> k;
	for (long long i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a < b) edges.push_back({c, {a, b}});
		else edges.push_back({c, {b, a}});
	}
	sort(edges.begin(), edges.end());
	long long c = 0; long long used = 0;
	vector<long long> wts;
	for (auto i : edges) {
		if (unionfd(i.second.first, i.second.second)) {
			used += i.first;
			wts.push_back(i.first);
			c++;
		}
	}
	if (c != n - 1) cout << -1 << '\n';
	else if (used <= k) cout << 0 << '\n';
	else {
		c = 0;
		for (long long i = int(wts.size()) - 1; i >= 0 && used > k; i--) {
			used -= wts[i];
			used += 1;
			c++;
		}
		if (used <= k) cout << c << '\n';
		else cout << -1 << '\n';
	}

}
