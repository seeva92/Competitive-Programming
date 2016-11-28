#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX], N;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N; int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == i) cnt++;
	}
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (arr[i] == i) continue;
		if (i == arr[arr[i]]) {cnt += 2; flag = true; break;}
		else flag = false;
	}
	if (flag) cout << cnt << '\n';
	else cout << cnt + 1 << '\n';
}
