#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 7;
using namespace std;
int N;
pair<int, int> eggs[MAX];
pair<int, int> arr[MAX];
typedef vector<int> vi;
class PaintingEggs
{

public:
	void solve();
};
void PaintingEggs::solve() {
	cin >> N;
	ll ft = 0, st = 0;
	for (int i = 0; i < N; i++) {
		cin >> eggs[i].first >> eggs[i].second;
		arr[i].first = abs(eggs[i].first - eggs[i].second);
		arr[i].second = i;
		ft += eggs[i].first; st += eggs[i].second;
	}
	sort(arr, arr + N, greater<pair<int, int>>());
	ll ls = 0, rs = 0;
	string res;
	if (ft > st) {
		rs += eggs[arr[0].second].second;
		res.push_back('G');
	}
	else {
		ls += eggs[arr[0].second].first;
		res.push_back('A');
	}
	for (int i = 1; i < N; i++) {
		if (abs(ls + eggs[arr[i].second].first - rs) < abs(rs + eggs[arr[i].second].second - ls)) {
			ls += eggs[arr[i].second].first;
			res.push_back('A');
		} else {
			rs += eggs[arr[i].second].second;
			res.push_back('G');
		}
	}
	if (abs(ls - rs) <= 500) cout << res;
	else cout << "-1";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	PaintingEggs p; p.solve();
}
