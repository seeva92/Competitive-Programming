#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
int box[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q, x;
	cin >> n; for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> q >> x;
	int res = 0, idx = 0;;
	string s;
	stack<int> stk; int cnt = -1;
	for (int i = 0; i < q; i++) {
		cin >> s;
		if (s == "Harry") { res += arr[idx]; stk.push(arr[idx++]);}
		else { res -= stk.top(); stk.pop(); }
		if (cnt == -1 && res == x) cnt = stk.size();
	}
	cout << cnt;
}

