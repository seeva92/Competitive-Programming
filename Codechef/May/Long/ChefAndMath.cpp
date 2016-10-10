#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
vector<ll> facts;
const ll mod = 1e9 + 7;
void init() {
	facts.push_back(1);
	facts.push_back(2);
	for (int i = 2; facts[i - 1] <= (int)INT_MAX; i++) {
		facts.push_back(facts[i - 1] + facts[i - 2]);
	}
}
ll compute(ll K, ll X, int N) {
	if (K == 0 && X == 0) return 1;
	if (K == 0 || N == 0 || X < 0) return 0;
	ll c = compute(K, X, N - 1);
	if (facts[N - 1] <= X && X <= (K * facts[N - 1]))
		c = (c + compute(K - 1, X - facts[N - 1], N)) % mod;
	return c;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	ll Q, X, K; cin >> Q;
	while (Q--) {
		cin >> X >> K;
		cout << compute(K, X, int(facts.size())) << endl;
	}

}