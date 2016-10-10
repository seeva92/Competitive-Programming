#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int arr[10007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		int s = -1, e = -1;
		bool flag = true;
		int i;
		for (i = 1; (i < n) && (arr[i] < arr[i + 1]); i++);
		s = i;
		for (; (i < n) && (arr[i] > arr[i + 1]); i++);
		e = i;
		for (int j = s, k = e; j <= k; j++, k--) swap(arr[j], arr[k]);
		for (i = 1; (i < n) && (arr[i] < arr[i + 1]); i++);
		if (i == n && s != e) cout << s << " " << e << endl;
		else cout << "-1 -1" << endl;
	}


}