#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, s, t;
int arr[MAX];
void compute() {
	int temp = s;
	int c = 0;
	while (s != t) {
		if (arr[s] == temp) {cout << "-1"; return;}
		s = arr[s];
		c++;
	}
	cout << c;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> t;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	compute();
}
