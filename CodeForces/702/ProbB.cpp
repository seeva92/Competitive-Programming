#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const long long INF = 1e10;
using namespace std;
map<long long, int> mp;
vector<long long> powers;
void init() {
	for (long long i = 2; (i << 1) < INF; i <<= 1) {
		powers.push_back(i);
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
	int n, x; cin >> n;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		for (auto j : powers) {
			if (x < j)
				total += mp[j - x];
		}
		mp[x]++;
	}

	cout << total << '\n';


}
