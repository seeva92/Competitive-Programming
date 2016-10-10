#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int colors[150], n, t;
bool visit[150];
int compute(set<int> a, set<int> b, set<int> c) {
	for (auto it : b)
		a.erase(it);
	for (auto it : c)
		a.erase(it);
	return *(a.begin());
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--) {
		memset(colors, 0, sizeof colors);
		memset(visit, 0, sizeof visit);
		cin >> n;
		set<int> cset;
		for (int i = 0; i < (n - 1); i++) {
			cin >> colors[i];
			cset.insert(i);
		}
		sort(colors, colors + (n - 1));
		for (int i = 0; i < (n - 1); i++)
			cout << colors[i] << " ";
		cout << '\n';
		vector<int> v[n + 1];
		set<int> colored[n + 1];
		int x, y;
		for (int i = 1; i <= (n - 1); i++) {
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int res = INT_MIN;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) colored[j].clear();
			colored[i].insert(-1);

			int c = -1, d = 1;
			queue<int> q; q.push(i);

			int total = 0;
			while (!q.empty()) {
				x = q.front();
				if (visit[x]) { q.pop(); continue;}
				visit[x] = true;
				for (auto it : v[x]) {
					if (!visit[it]) {
						int tmp = compute(cset, colored[x], colored[it]);
						colored[x].insert(tmp);
						colored[it].insert(tmp);
						total += colors[tmp];
						q.push(it);
					}
				}
			}
			if (res < total) res = total;
		}

		cout << res << endl;

	}

}