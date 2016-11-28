#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, M, arr[MAX];
int l, r;
string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cin >> s; N = s.size();
	for (int i = 0; i < N - 1; i++) {
		if (s[i] == s[i + 1]) arr[i] = 1;
		else arr[i] = 0;
		if (i > 0) arr[i] += arr[i - 1];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> l >> r;
		if (l - 2 >= 0)
			cout << arr[r - 2] - arr[l - 2];
		else cout << arr[r - 2];
		cout << '\n';
	}

}
