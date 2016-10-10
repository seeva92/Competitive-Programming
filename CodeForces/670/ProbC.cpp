#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int known[200007], audio[200007], subs[200007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n;
	map<int, int> kc, ac, sc;
	for (int i = 0; i < n; i++) {cin >> known[i]; kc[known[i]]++;}
	cin >> m;
	int maxa = 0;
	for (int i = 0; i < m; i++) {
		cin >> audio[i];
		if (kc[audio[i]] > maxa) maxa = kc[audio[i]];
	}
	for (int i = 0; i < m; i++) cin >> subs[i];
	int result = -1, maxs = 0;
	for (int i = 0; i < m; i++) {
		if (maxa == kc[audio[i]]) {
			if (result == -1) result = i + 1;
			if (kc[subs[i]] > maxs) {
				maxs = kc[subs[i]]; result = i + 1;
			}
		}
	}
	cout << result << endl;
}