#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, M;
struct dance {
	int x, y, z;
};
dance d[MAX];
int vis[MAX];
void ass(int x, int y, int z) {
	switch (vis[z]) {
	case 1: vis[x] = 2; vis[y] = 3; break;
	case 2: vis[x] = 1; vis[y] = 3; break;
	case 3: vis[x] = 1; vis[y] = 2; break;
	}
}
void compute() {
	for (int i = 0; i < M; i++) {
		if (!vis[d[i].x] && !vis[d[i].y] && !vis[d[i].z]) {
			vis[d[i].x] = 1; vis[d[i].y] = 2; vis[d[i].z] = 3;
		} else if (!vis[d[i].x] && !vis[d[i].y]) ass(d[i].x, d[i].y, d[i].z);
		else if (!vis[d[i].x] && !vis[d[i].z]) ass(d[i].x, d[i].z, d[i].y);
		else if (!vis[d[i].y] && !vis[d[i].z]) ass(d[i].y, d[i].z, d[i].x);
		else if (!vis[d[i].x]) vis[d[i].x] = 6 - (vis[d[i].y] + vis[d[i].z]);
		else if (!vis[d[i].y]) vis[d[i].y] = 6 - (vis[d[i].x] + vis[d[i].z]);
		else if (!vis[d[i].z]) vis[d[i].z] = 6 - (vis[d[i].y] + vis[d[i].x]);
	}
	for (int i = 1; i <= N; i++) cout << vis[i] << " ";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis, 0, sizeof vis);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> d[i].x >> d[i].y >> d[i].z;
	}
	compute();
}
