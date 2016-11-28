#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int MAX = 1E5 + 7;
using namespace std;
int arr[MAX], ass[MAX], N;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ass[i] = 1;
	}
	arr[0] = -mod; arr[N + 1] = -mod;
	bool flag = false;
	ass[0] = ass[N + 1] = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] > arr[i - 1]) ass[i] = ass[i - 1] + 1;
		else if (arr[i] < arr[i - 1]) { ass[i] = max(ass[i], 1); }
	}
	for (int i = 1; i <= N; i++) cout << ass[i] << " "; cout << '\n';

	for (int i = N; i >= 1; i--) {
		if (arr[i] > arr[i + 1]) ass[i] = max(ass[i], ass[i + 1] + 1);
		else if (arr[i] < arr[i + 1]) { ass[i] = max(ass[i], 1); }
	}
	for (int i = 1; i <= N; i++) cout << ass[i] << " "; cout << '\n';
	long long tot = 0;
	for (int i = 1; i <= N; i++) tot += ass[i];
	cout << tot;
}
