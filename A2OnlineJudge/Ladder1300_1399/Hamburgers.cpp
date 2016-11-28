#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll nb, ns, nc, pb, ps, pc, r, cb = 0, cs = 0, cc = 0;
string s;
void bscompute() {
	ll low = 0, high = 1e13, mid;
	while (low < high) {
		mid = (low + high + 1) / 2;
		ll tot = 0;
		tot += (max(0LL, (mid * cb) - nb) * pb);
		tot += (max(0LL, (mid * cs) - ns) * ps);
		tot += (max(0LL, (mid * cc) - nc) * pc);
		if (tot <= r) {
			low = mid;
		} else high = mid - 1;
	}
	cout << low << '\n';
}
void compute() {
	ll cnt = 0;
	//Existing
	if (!cb) nb = 0; if (!cs) ns = 0; if (!cc) nc = 0;
	while ((nb != 0 || ns != 0 || nc != 0) && r > 0) {
		if (cb) {
			if (nb >= cb) nb -= cb;
			else if (r >= (pb * (cb - nb))) {
				r -= (pb * (cb - nb));
				nb = 0;
			}
			else break;
		}
		if (cs) {
			if (ns >= cs) ns -= cs;
			else if (r >= (ps * (cs - ns))) {
				r -= (ps * (cs - ns));
				ns = 0;
			}
			else {
				break;
			}
		}
		if (cc) {
			if (nc >= cc) nc -= cc;
			else if (r >= (pc * (cc - nc))) {
				r -= (pc * (cc - nc));
				nc = 0;
			}
			else {
				break;
			}
		}
		// cout << r << " " << nb << " " << ns << " " << nc << '\n';
		cnt++;
	}
	// cout << cnt;
	ll tot = (pb * cb) + (ps * cs) + (pc * cc);
	cout << cnt + (r / tot);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	cin >> nb >> ns >> nc; cin >> pb >> ps >> pc;
	cin >> r;
	for (auto i : s) {
		switch (i) {
		case 'B': cb++; break;
		case 'S': cs++; break;
		case 'C': cc++; break;
		}
	}
	bscompute();
	cout << (-1) % mod;
}

