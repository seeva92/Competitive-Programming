#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;
const ll MAX = 1e6 + 7;
using namespace std;
typedef vector<ll> vi;
ll N;
ll arr[MAX];
ll nG[MAX], pG[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	stack<pair<ll, ll>> nstk, pstk;
	for (ll i = 1; i <= N; i++) cin >> arr[i];

	for (ll i = 1, j = N; i <= N && j >= 1; i++, j--) {
		if (nstk.empty()) nstk.push({arr[i], i});
		else {
			while (!nstk.empty() && nstk.top().first < arr[i]) {
				nG[nstk.top().second] = i;
				nstk.pop();
			}
			nstk.push({arr[i], i});
		}
		if (pstk.empty()) pstk.push({arr[j], j});
		else {
			while (!pstk.empty() && pstk.top().first < arr[j]) {
				pG[pstk.top().second] = j;
				pstk.pop();
			}
			pstk.push({arr[j], j});
		}
	}
	while (!nstk.empty()) { nG[nstk.top().second] = -1; nstk.pop();}
	while (!pstk.empty()) { pG[pstk.top().second] = -1; pstk.pop();}
	for (ll i = 1; i <= N; i++) cout << nG[i] + pG[i] << ' ';

}
