#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll a, b, c;
int sdigits(int x) {
	int s = 0;
	while (x > 0) {
		s += (x % 10); x /= 10;
	}
	return s;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> c;
	vector<int> v;
	for (int i = 1; i <= 81; i++) {
		int x = b * pow(double(i), double(a)) + c;
		if (sdigits(x) == i && x < 1000000000) v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto i : v) cout << i << " ";
}
