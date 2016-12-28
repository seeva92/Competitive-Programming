#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Median
{
public:
	int n, x;
	vector<int> arr;
	void solve() {
		cin >> n >> x;
		int val;
		for (int i = 0; i < n; i++) {
			cin >> val; arr.push_back(val);
		}
		sort(arr.begin(), arr.end());
		int cnt = 0;
		while (arr[(arr.size() - 1) / 2] != x) {
			cnt++;
			arr.push_back(x);
			sort(arr.begin(), arr.end());
		}
		cout << cnt;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Median m; m.solve();
}
