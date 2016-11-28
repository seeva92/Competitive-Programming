#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, X; cin >> N >> X;
	deque<pair<int, int>> dq; int x;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		dq.push_back({x, i});
	}
	for (int i = 1; i <= X; i++) {
		deque<pair<int, int>> tmp;
		pair<int, int> mx; mx.first = -1;
		for (int j = 1; j <= X && !dq.empty(); j++) {
			if (mx.first < dq.front().first) mx = dq.front();
			// cout << dq.front().first << " ";
			tmp.push_back(dq.front()); dq.pop_front();
		}
		cout << mx.second << " ";
		// cout << '\n';
		pair<int, int> tp;
		while (!tmp.empty()) {
			tp = tmp.front();
			if (tp.second != mx.second) {
				if (tp.first > 0) tp.first--;
				dq.push_back(tp);
			}
			tmp.pop_front();

		}
	}
}
