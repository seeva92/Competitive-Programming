#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
vector<long long> prices;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n;
	long long prev = 0, x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		prices.push_back(x + prev); x = prev;
	}
	sort(prices.begin(), prices.end());
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << upper_bound(prices.begin(), prices.end(), x) - prices.begin() << '\n';
	}

}
