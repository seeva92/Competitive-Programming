#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long T, L, R;
int digits[20];
string s;
long long DP[20][200][2000];
int len;
// long long gcd(long long a, long long b) {
// 	if(a==0 || b)
// 	return b == 0 ? a : gcd(b, a % b);
// }
long long solve(int i, int dsum, int sqdsum) {
	if (i == -1) return (__gcd(dsum, sqdsum) == 1);;
	if (DP[i][dsum][sqdsum] != -1) return DP[i][dsum][sqdsum];

	long long ans = 0;
	for (int cdigit = 0; cdigit <= 9; cdigit++) {
		ans += solve(i - 1, dsum + cdigit, sqdsum + (cdigit * cdigit));
	}
	DP[i][dsum][sqdsum] = ans;
	return ans;
}
long long iter(int idx, int tight, int dsum, int sqdsum) {
	if ( idx == len ) return (__gcd(dsum, sqdsum) == 1);
	long long ans = 0;
	if (tight) {
		for (int i = 0; i <= s[idx] - 49; i++)
			ans += iter(idx + 1, 0, dsum + i, sqdsum + (i * i));
		ans += iter(idx + 1, 1, dsum + (s[idx] - 48), sqdsum + ((s[idx] - 48) * (s[idx] - 48)));
	} else {
		ans += solve(len - idx - 1, dsum, sqdsum);
	}
	return ans;
}
long long compute(long long num) {
	s = to_string(num);
	len = s.size();

	return iter(0, 1, 0, 0);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(DP, -1, sizeof DP);
	cin >> T;
	while (T--) {
		cin >> L >> R;
		// cout << ;
		cout << compute(R) - compute(L - 1) << '\n';
	}
}
