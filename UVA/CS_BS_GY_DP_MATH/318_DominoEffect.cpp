#include <bits/stdc++.h>
#define ON 1
#define OFF 0
#define DONE -1
#define vi vector<int>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n, m, v1, v2, sec,tmp;
	while (scanf("%d %d", &n, &m) && (n || m)) {
		vector<pair<int, int>> v[n + 1];
		vector<int> fwd(n + 1), state(n + 1); state.assign(n + 1, OFF);
		while (m--) {
			scanf("%d %d", &v1, &v2, &sec);
			v[v1].push_back(make_pair(sec, v2)); v[v2].push_back(make_pair(sec, v1));
		}
		
	}

}