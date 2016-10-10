#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int a[1007], b[1007];
int compute(int n, int k) {
	if (n == 0) return 0;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int temp = ((b[n - 1] + i) / a[n - 1] + compute(n - 1, k - i));
		if (ans < temp) ans = temp;
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	compute(n, k);

}