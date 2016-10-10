#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i & 1) printf("I hate");
		else printf("I love");
		if (i != n) printf(" that ");
	}
	printf(" it");
}
