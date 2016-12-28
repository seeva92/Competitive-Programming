#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class FixingTypos
{
	string s, res;
	vector<int> cnt;
	int cIdx = 0;
public:
	void preprocess() {
		int len = s.size();
		for (int i = 0; i < len; ) {
			int j;
			for (j = i; j < len && s[i] == s[j]; j++);
			res.push_back(s[i]);
			cnt[cIdx++] = j - i;
			i = j;
		}
		compute();
	}
	void compute() {
		for (int i = 0; i < cIdx; i++) {
			if (cnt[i] > 2) {
				cnt[i] = 2;
			}
			if (i > 0) {
				if (cnt[i - 1] > 1 && cnt[i] > 1) {
					cnt[i] = 1;
				}
			}
		}
		for (int i = 0; i < cIdx; i++) {
			for (int j = 0; j < cnt[i]; j++) cout << res[i];
		}
	}
	void solve() {
		cnt.assign(200006, 0);
		cin >> s;
		preprocess();
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	FixingTypos f; f.solve();
}
