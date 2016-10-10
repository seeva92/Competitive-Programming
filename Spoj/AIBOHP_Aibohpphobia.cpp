#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
string s, r;
int arr[6107][6107];
int lcs()
{
	memset(arr, 0, sizeof arr);
	int len = int(s.size());
	int res = 0;
	for (int i = 0; i <= len; i++)
		for (int j = 0; j <= len; j++) {
			if (i == 0 || j == 0) arr[i][j] = 0;
			else if (s[i - 1] == r[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			} else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
		}
	return arr[len][len];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(arr, 0, sizeof arr);
		cin >> s; r = s; reverse(r.begin(), r.end());
		cout << int(s.size()) - lcs() << endl;
	}

}