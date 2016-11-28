#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[8] = {0};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x; arr[x]++;
	}
	int _24 = arr[4];
	int _26 = arr[2] - _24;
	int _36 = arr[3];
	if (_26 >= 0 && arr[1] == _24 + _26 + _36 && arr[2] == _24 + _26 && arr[3] == _36 && arr[4] == _24 && arr[5] == 0 && arr[6] == _26 + _36 && arr[7] == 0) {
		for (int i = 0; i < _24; i++) cout << "1 2 4\n";
		for (int i = 0; i < _26; i++) cout << "1 2 6\n";
		for (int i = 0; i < _36; i++) cout << "1 3 6\n";
	} else cout << -1;
}

