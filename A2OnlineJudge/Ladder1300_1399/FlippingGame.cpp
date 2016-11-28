#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, arr[107];
int l, r;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int curr = 0; l = 1, r = 1;
	int res = 0, resl, resr;
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] == 0) { curr++;}
		else curr--;
		r++;
		if (res < curr) {
			flag = true;
			res = curr;
			resl = l;
			resr = r;
		}
		if (curr < 0) {
			curr = 0; l = i + 1; r = i + 1;
		}
	}
	if (flag) {
		for (int i = resl; i < resr; i++) arr[i] = 1 - arr[i];
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) if (arr[i]) cnt++;
	if (res == 0)
		cout << cnt - 1;
	else cout << cnt;
}
