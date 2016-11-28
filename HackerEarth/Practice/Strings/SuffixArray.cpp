#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string s;
int ra[MAX], sa[MAX], tra[MAX], tsa[MAX];
int cnt[300];
int N;
pair<int, int> stringMatching(string P) {
	int l = 0, r = N - 1, mid;
	int lower = -1, higher = -1;
	int len = P.length();
	while (l < r) {
		mid = (l + r) / 2;
		int res = s.compare(sa[mid], len, P);
		if (res >= 0) r = mid;
		else l = mid + 1;
	}
	if (s.compare(sa[l], len, P) != 0) {return { -1, -1};}
	lower = l;
	l = 0, r = N - 1;
	while (l < r) {
		mid = (l + r) / 2;

		int res = s.compare(sa[mid], len, P);
		if (res > 0) r = mid;
		else l = mid + 1;
	}
	if (s.compare(sa[r], len, P) != 0) r--;
	higher = r;

	return {lower, higher};
}
void countSort(int k) {
	memset(cnt, 0, sizeof cnt);
	int maxi = max(300, N); int sum = 0;
	for (int i = 0; i < N; i++) cnt[i + k < N ? ra[i + k] : 0]++;
	for (int i = 0; i < maxi; i++) {
		int t = cnt[i]; cnt[i] = sum; sum += t;
	}
	for (int i = 0; i < N; i++)
		tsa[cnt[sa[i] + k < N ? ra[sa[i] + k] : 0]++] = sa[i];

	for (int i = 0; i < N; i++) sa[i] = tsa[i];
}
void compute() {
	for (int i = 0; i < N; i++) ra[i] = s[i];
	for (int i = 0; i < N; i++) sa[i] = i;
	for (int k = 1; k < N; k <<= 1) {
		cout << "Before " << k << '\n';
		for (int i = 0; i < N; i++) cout << s.substr(sa[i]) << " " << ra[sa[i]] << " " << ra[sa[i] + k] << '\n';
		countSort(k);
		countSort(0);
		cout << "After " << k << '\n';
		for (int i = 0; i < N; i++) cout << s.substr(sa[i]) << " " << ra[sa[i]] << " " << ra[sa[i] + k] << '\n';
		tra[sa[0]] = 0; int rnk = 0;
		for (int i = 1; i < N; i++) tra[sa[i]] = ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k] ? rnk : ++rnk;
		for (int i = 0; i < N; i++) ra[i] = tra[i];
		if (ra[sa[N - 1]] == N - 1) break;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s; s.push_back('$');
	N = s.length();
	compute();
	auto fnd = stringMatching("SIVA");
	if (fnd.first != -1 && fnd.second != -1) {
		for (int i = fnd.first; i <= fnd.second; i++)
			cout << s.substr(sa[i], 4) << '\n';
	}
}
