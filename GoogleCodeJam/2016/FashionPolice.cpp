#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
struct day {
	int j, p, s;
};
int JP[13][13];
int PS[13][13];
Int JS[13][13];
deque<day> compute(int J, int P, int S, int K, deque<day> res) {
	if (J < 1 || P < 1 || S < 1) return res;
	deque<day> all, df, ds, dt;
	vector<pair<int, deque<day>>> arr;
	if (JP[J][P] + 1 <= K && PS[P][S] + 1 <= K && JS[J][S] + 1 <= K) {
		day d;
		d.j = J - 1, d.p = P - 1, d.s = S - 1;
		JP[J][P] ++; JP[P][J]++; PS[P][S]++; PS[S][P]++; JS[J][S]++; JS[S][J]++;
		res.push_back(d);
		all = compute(J - 1, P - 1, S - 1, K, res);
		arr.push_back(int(all.size()), all);
	} else {
		df = compute(J, P - 1, S - 1, K, res);
		arr.push_back(int(df.size()), df);
		ds = compute(J - 1, P - 1, S, K, res);
		arr.push_back(int(ds.size()), ds);
		dt = compute(J - 1, P, S - 1, K, res);
		arr.push_back(int(dt.size()), dt);
	}
	sort(arr.begin(), arr.end(), greater<pair<int, deque<day>>>());
	return arr[0].second;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int T, J, P, S, K;
	cin >> T;
	while (T--) {
		cin >> J >> P >> S >> K;
		deque<day> res;
		res = compute(J + 1, P + 1, S + 1, K, res);
	}


}