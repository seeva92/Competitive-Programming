#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
string s;
int p[MAX];
void compute() {
	int len = int(s.size());
	int arr[257]; memset(arr, 0, sizeof arr);
	for (int i = 0; i < len; i++) arr[int(s[i])]++;
	int c = 0;
	for (int i = 0; i < 257; i++)
		if (arr[i] != 0) c++;
	cout << c << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s;
		compute();
	}
}
