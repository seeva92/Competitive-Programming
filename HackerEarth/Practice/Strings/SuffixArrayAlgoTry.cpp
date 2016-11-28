#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string s; int len;
int sa[MAX], tmpsa[MAX];
int rnk[MAX], tmprnk[MAX];
int Phi[MAX], LCP[MAX], PLCP[MAX];
int cnt[307];
void computeLCP() {
	Phi[sa[0]] = -1;
	for (int i = 1; i < len; i++) Phi[sa[i]] = sa[i - 1];
	int L = 0;
	for (int i = 0; i < len; i++) {
		if (Phi[i] == -1) { PLCP[i] = 0;}
		while (s[i + L] == s[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (int i = 0; i < len; i++) LCP[i] = PLCP[sa[i]];
	for (int i = 0; i < len; i++) cout << LCP[i] << " ";
}
pair<int, int> stringMatching(string P) {
	int plen = P.size();
	int low = 0, mid, high = len - 1; int lres = -1, hres = -1;
	while (low < high) {
		mid = (low + high) >> 1;
		int res = s.compare(sa[mid], plen, P);
		if (res >= 0) high = mid;
		else low = mid + 1;
	}
	if (s.compare(sa[low], plen, P) != 0) return { -1, -1};
	lres = low;

	low = 0, high = len - 1;
	while (low < high) {
		mid = (low + high) >> 1;
		int res = s.compare(sa[mid], plen, P);
		if (res > 0) high = mid;
		else low = mid + 1;
	}
	if (s.compare(sa[high], plen, P) != 0) high--;
	hres = high;
	return {lres, hres};
}
void countSort(int k) {
	memset(cnt, 0, sizeof cnt);
	int sum = 0;
	int cntLen = 300;
	for (int i = 0; i < len; i++) cnt[i + k < len ? rnk[i + k] : 0]++;
	for (int i = 0; i <= cntLen; i++) {
		int t = cnt[i]; cnt[i] = sum; sum += t;
	}
	for (int i = 0; i < len; i++) {
		tmpsa[cnt[sa[i] + k < len ? rnk[sa[i] + k] : 0]++] = sa[i];
	}
	for (int i = 0; i < len; i++) sa[i] = tmpsa[i];

}
void compute() {
	for (int i = 0; i < len; i++) rnk[i] = s[i];
	for (int i = 0; i < len; i++) sa[i] = i;
	for (int k = 1; k < len; k <<= 1) {
		countSort(k); countSort(0);
		int r = 0;
		tmprnk[sa[0]] = r;
		for (int i = 1; i < len; i++) {
			tmprnk[sa[i]] = rnk[sa[i]] == rnk[sa[i - 1]] && rnk[sa[i] + k] == rnk[sa[i - 1] + k] ? r : ++r;
		}
		for (int i = 0; i < len; i++) rnk[i] = tmprnk[i];
		cout << k << "\n";
		for (int i = 0; i < len; i++) cout << s.substr(sa[i]) << "\n";
		cout << '\n';
		if (rnk[sa[len - 1]] == len - 1) break;
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
	len = s.length();
	compute();
	auto x = stringMatching("SIVA");
	if (x.first != -1 && x.second != -1) {
		for (int i = x.first; i <= x.second; i++)
			cout << s.substr(sa[i]) << '\n';
	}
	computeLCP();
}
