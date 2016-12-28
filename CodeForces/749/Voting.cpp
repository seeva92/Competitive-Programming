#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[2 * MAX];
set<int> dt, rt;
class Voting
{
public:
	void solve() {
		memset(arr, 0, sizeof arr);
		int n; cin >> n;
		string s; cin >> s;
		for (int i = 0; i < n; i++ ) {
			if (s[i] == 'D') dt.insert(i);
			else rt.insert(i);
		}

		while (dt.size() && rt.size()) {
			set<int> ndt, nrt;
			while (dt.size() && rt.size()) {
				int dv = *(dt.begin()), rv = *(rt.begin());
				if (dv < rv) {
					ndt.insert(dv); dt.erase(dv);
					auto tmp = rt.upper_bound(dv);
					if (tmp != rt.end()) {
						rt.erase(tmp);
					} else {
						nrt.erase(nrt.begin());
					}
				} else {
					nrt.insert(rv); rt.erase(rv);
					auto tmp = dt.upper_bound(rv);
					if (tmp != dt.end()) {
						dt.erase(tmp);
					} else {
						ndt.erase(ndt.begin());
					}
				}
			}
			while (dt.size() && nrt.size()) {
				int dv = *(dt.begin());
				dt.erase(dv);
				ndt.insert(dv);
				nrt.erase(nrt.begin());
			}

			while (rt.size() && ndt.size()) {
				int rv = *(rt.begin());
				rt.erase(rv);
				nrt.insert(rv);
				ndt.erase(ndt.begin());
			}
			dt = ndt;
			rt = nrt;
		}

		if ((int)dt.size() == 0) cout << 'R';
		else cout << 'D';
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Voting v; v.solve();
}
