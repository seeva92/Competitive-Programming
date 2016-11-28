#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[100007];
int avail[100007];
set<int> st[100007];
vector<pair<int, int>> v;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(avail, 0, sizeof avail);
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		set<int> sti;
		int len = sqrt(arr[i]);
		for (int j = 1; j <= len; j++ ) {
			if (arr[i] % j == 0) {
				sti.insert(j);
				sti.insert(arr[i] / j);
			}
		}
		st[i] = sti;
	}
	for (int i = 0; i < N; i++) {
		for (auto j : st[i]) {
			if (j <= M) cout << j << " ";
		}
		cout << '\n';
	}
	cout << cnt << '\n';
}
