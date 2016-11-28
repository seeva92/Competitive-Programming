#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
long long n, m, arr[MAX], W, H, PW, PH, Ans;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> m; for (int i = 0; i < m; i++) {
		cin >> W >> H;
		Ans = max(Ans + PH, arr[W]); cout << Ans << '\n';
		PW = W, PH = H;
	}

}
