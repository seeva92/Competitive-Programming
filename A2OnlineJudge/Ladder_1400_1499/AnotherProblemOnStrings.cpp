#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class AnotherProblemOnStrings
{
	int k; string s;
	deque<ll> dq;
public:
	void compute() {
		int i;
		ll start = 0;
		int len = s.size();
		for (i = 0; i < len && int(dq.size() < k); i++) {
			if (s[i] == '1') dq.push_back(i);
		}
		for (; i < len && s[i] == '0'; i++ );
		ll cnt = 0;
		if (int(dq.size()) != k) { cout << '0'; return;}
		if (!dq.empty()) cnt += (dq.front() - start + 1) * ((i - 1) - dq.back() + 1);
		else cnt += (((i - 1) - start + 1) * (1LL) * ((i - 1) - start + 2)) / 2LL;

		for (; i < len;) {
			if (!dq.empty()) {
				start = dq.front() + 1;
				dq.pop_front();
				dq.push_back(i);
				i++;
				for (; i < len && s[i] == '0'; i++ );
				cnt += (dq.front() - start + 1) * ((i - 1) - dq.back() + 1 );
			} else {
				if (s[i] == '1') { i++; continue; }
				start = i;
				for (; i < len && s[i] == '0'; i++ );
				cnt += (((i - 1) - start + 1) * (1LL) * ((i - 1) - start + 2)) / 2LL;
			}
		}
		cout << cnt;
	}
	void solve() {
		cin >> k >> s;
		compute();

	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	AnotherProblemOnStrings a; a.solve();
}
