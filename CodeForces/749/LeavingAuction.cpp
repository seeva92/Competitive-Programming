#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[2 * MAX];
vector<int> bids[2 * MAX];
map<int, int> mbid;
set<int> st;
int quer[2 * MAX];
class LeavingAuction
{
	int n, a, b, q, k;
public:
	void solve() {
		memset(arr, 0, sizeof arr);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b;
			bids[a].push_back(b);
			arr[a] = b;
		}
		for (int i = 1; i < 2 * MAX; i++) {
			if (arr[i]) {
				st.insert(arr[i]);
				mbid[arr[i]] = i;
			}
		}

		cin >> q;
		while (q--) {
			cin >> k;
			for (int i = 1; i <= k; i++) {
				cin >> quer[i];
				if (arr[quer[i]]) {
					st.erase(arr[quer[i]]);
				}

			}
			if (st.empty()) {
				cout << "0 0" << '\n';
			} else {
				int winbid = *(st.rbegin()); st.erase(winbid);
				int idx = mbid[winbid];
				cout << idx << " ";
				if (st.empty()) {
					cout << *(bids[idx].begin()) << '\n';
				} else {
					int seconmax = *(st.rbegin());
					cout << *upper_bound(bids[idx].begin(), bids[idx].end(), seconmax) << '\n';
				}

				st.insert(winbid);
			}

			for (int i = 1; i <= k; i++) {
				if (arr[quer[i]]) {
					st.insert(arr[quer[i]]);
				}
			}
		}

	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LeavingAuction l; l.solve();
}
