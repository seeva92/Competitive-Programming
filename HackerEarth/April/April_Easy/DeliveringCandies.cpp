#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<long long>
#define pi pair<long long,long long>
#define vii vector<pi>
using namespace std;
#define INF 1e18
long long K[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	long long n, m, s; cin >> n >> m >> s;
	long long u, v, w;
	for (long long i = 1; i <= n; i++) cin >> K[i];
	vii g[n + 1];
	for (long long i = 1; i <= m; i++) {
		cin >> u >> v >> w; g[u].push_back(mp(v, w));
		g[v].push_back(mp(u, w));
	}
	vi dist(n + 1, INF); dist[s] = 0;
	priority_queue<pi, vii, greater<pi>> p; p.push(mp(0, s));
	while (!p.empty()) {
		pi t = p.top(); p.pop();
		long long ft = t.first, st = t.second;
		if (ft > dist[st]) continue;
		for (size_t i = 0; i < g[st].size(); i++) {
			pi pr = g[st][i];
			if (dist[st] + pr.second < dist[pr.first]) {
				dist[pr.first] = dist[st] + pr.second;
				p.push(pi(dist[pr.first], pr.first));
			}
		}
	}
	// for (int i = 1; i <= n; i++) cout << dist[i] << " " << endl;
	long long sum = 0, prod_sum = 0;
	for (int i = 1; i <= n; i++)
		if (dist[i] != INF)
			sum += K[i], prod_sum += (K[i] * dist[i]);

	for (int i = 1; i <= n; i++)
		if (dist[i] != INF) {
			long long i_s = (sum - K[i]) * dist[i];
			long long s_j = (prod_sum - (dist[i] * K[i]));
			cout << i_s + s_j << " ";
		}else cout<<0<<" ";

}