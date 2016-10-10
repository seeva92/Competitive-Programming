#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n, m, x, y, val;
	scanf("%d %d", &n, &m);
	vector<pii> v[n];
	vector<int> dist(n, INT_MAX);
	vector<int> parent(n, -1);
	while (m--) {
		scanf("%d %d %d", &x, &y, &val);
		v[x - 1].push_back(make_pair(val, y - 1)); v[y - 1].push_back(make_pair(val, x - 1));
	}
	dist[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> p;
	p.push(mp(0, 0));
	while (!p.empty()) {
		pii pr = p.top();
		int f = pr.first, s = pr.second; p.pop();
		if (f == dist[s]) {
			for (int i = 0; i < int(v[s].size()); i++) {
				if (dist[v[s][i].second] > (f + v[s][i].first)) {
					dist[v[s][i].second] = f + v[s][i].first;
					parent[v[s][i].second] = s;
					p.push(mp(dist[v[s][i].second], v[s][i].second));
				}
			}
		}
	}
}