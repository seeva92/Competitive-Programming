#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m, curr = 0, x, res = INT_MIN;
	cin >> n >> m;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> x;
		while ((curr + x > m) && (!q.empty())) {
			curr -= q.front();
			q.pop();
		}
		if (curr + x <= m) {
			q.push(x);
			curr += x;
			if (res < curr) res = curr;
		}

	}
	cout << res << endl;

}