#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int compute(int s, int d) {
	int fops = 0, bops = 0;
	for (int i = s; i != d; i = (i + 1) % 10) fops++;
	for (int i = s; i != d; i = (10 + (i - 1)) % 10) bops++;
	return min(fops, bops);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int src[5], des[5];
	int total = 0;
	for (int i = 0; i < 5; i++) cin >> src[i];
	for (int i = 0; i < 5; i++) cin >> des[i];
	for (int i = 0; i < 5; i++) {
		total += compute(src[i], des[i]);
	}
	cout << total;
}
