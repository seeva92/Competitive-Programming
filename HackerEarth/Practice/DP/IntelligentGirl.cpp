#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[10007] = {0};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++)
		if ((s[i] - '0') % 2 == 0)
			arr[i] = 1;
	for (int i = 1; i < s.size(); i++) arr[i] += arr[i - 1];
	for (int i = 0; i < s.size(); i++)
		if (i - 1 >= 0) cout << arr[s.size() - 1] - arr[i - 1] << " ";
		else cout << arr[s.size() - 1] << " ";
}
