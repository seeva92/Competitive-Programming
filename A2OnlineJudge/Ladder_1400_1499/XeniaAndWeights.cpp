#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[15], aIdx = 0;
map<vector<int>, int> mp;
vector<int> lres, rres;
class XeniaAndWeights
{
public:
	bool compute(int m, int lt, int rt, vector<int> wlt, vector<int> wrt, int lastWt, bool flag) {
		if (m == 0) {
			lres = wlt; rres = wrt;
			return mp[ {m, lt, rt}] = true;
		}
		if (mp.count({m, lt, rt})) return mp[ {m, lt, rt}];
		bool res = false;
		for (int i = 0; i < aIdx; i++) {
			if (flag) {
				if (!res && (arr[i] != lastWt) && (lt + arr[i] > rt)) {
					wlt.push_back(arr[i]);
					res |= compute(m - 1, lt + arr[i], rt, wlt, wrt, arr[i], !flag);
					if (!res) wlt.pop_back();
				}
			} else {
				if (!res && (arr[i] != lastWt) && (rt + arr[i] > lt)) {
					wrt.push_back(arr[i]);
					res |= compute(m - 1, lt, rt + arr[i], wlt, wrt, arr[i], !flag);
					if (!res) wrt.pop_back();
				}
			}

		}
		return mp[ {m, lt, rt}] = res;
	}
	void solve() {
		string s;
		int m;
		cin >> s >> m;
		for (int i = 1; i <= s.size(); i++) {
			if (s[i - 1] == '1')
				arr[aIdx++] = i;
		}
		if (compute(m, 0, 0, {}, {} , 0, true)) {
			cout << "YES\n";
			int i;
			for (i = 0; i < lres.size() && i < rres.size(); i++) {
				if (i != 0) cout << " ";
				cout << lres[i] << " " << rres[i];
			}
			for (; i < lres.size(); i++) {
				if (i != 0) cout << " ";
				cout << lres[i];
			}
			for (; i < rres.size(); i++) {
				if (i != 0) cout << " ";
				cout << rres[i];
			}
		} else cout << "NO\n";
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	XeniaAndWeights x; x.solve();
}
