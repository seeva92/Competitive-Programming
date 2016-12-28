#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class ColorStripe
{
	int n, k;
public:
	void k2compute(string s) {
		vector<char> ft, st;
		for (int i = 0; i < n; i++) {
			if (ft.empty() || ft.back() == 'B') ft.push_back('A');
			else if (ft.back() == 'A') ft.push_back('B');
		}
		for (int i = 0; i < n; i++) {
			if (st.empty() || st.back() == 'A') st.push_back('B');
			else if (st.back() == 'B') st.push_back('A');
		}
		int lt = 0, rt = 0;
		for (int i = 0; i < n; i++) {
			if (ft[i] != s[i]) lt++;
			if (st[i] != s[i]) rt++;
		}
		if (lt <= rt) {
			cout << lt << '\n'; for (auto i : ft) cout << i;
		} else {
			cout << rt << '\n'; for (auto i : st) cout << i;
		}
	}
	inline int getchr(int l, int r) {
		for (int i = 0; i < k; i++) if (i != l && i != r) return i;
		return r;
	}
	void solve() {
		string s;
		cin >> n >> k >> s;
		if (n == 1) { cout << 0 << "\n" << s; return; }
		if (k == 2) {
			k2compute(s); return;
		}

		vector<string> v;
		for (int i = 0; i < n;) {
			string t; int j;
			for (j = i; j < n && s[i] == s[j]; j++) t.push_back(s[i]);
			i = j;
			v.push_back(t);
			// cout << t << '\n';
		}
		int ilen = v.size();
		int cnt = 0;
		for (int i = 0; i < ilen; i++) {
			int jlen = v[i].size();
			if (jlen == 1) continue;
			char c;
			if (jlen % 2 == 0) {
				if (i + 1 < ilen) c = (char)('A' + getchr(v[i][0] - 'A', v[i + 1][0] - 'A'));
				else c = (char)('A' + getchr(v[i][0] - 'A', -1));
			} else {
				c = (char)('A' + (((v[i][0] - 'A') + 1) % k));
			}
			for (int j = 1; j < jlen; j += 2) {
				v[i][j] = c;
				cnt++;
			}
		}
		cout << cnt << '\n';
		for (auto i : v) cout << i;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ColorStripe C; C.solve();
}
