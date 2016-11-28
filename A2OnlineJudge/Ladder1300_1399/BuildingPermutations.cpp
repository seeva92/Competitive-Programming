#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[3 * MAX], N, found[3 * MAX];
vector<ll> others, actual;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(found, 0, sizeof found);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (1 <= arr[i] && arr[i] <= N && found[arr[i]] == 0) found[arr[i]] = 1;
		else others.push_back(arr[i]);
	}
	sort(others.begin(), others.end());
	for (int i = 1; i <= N; i++) {
		if (found[i] == 0) actual.push_back(i);
	}
	ll cnt = 0; int len = others.size();
	for (int i = 0; i < len; i++) {
		// cout << others[i] << " " << actual[i] << '\n';
		cnt += abs(others[i] - actual[i]);
	}
	cout << cnt;
}
