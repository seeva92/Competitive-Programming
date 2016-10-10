#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
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
	ios::sync_with_stdio(false);
	double eps = 1e-9;
	cin.tie(0);
	int a, b, n, x, y;
	double distance, v;
	cin >> a >> b; cin >> n;
	bool flag = false;
	double res = 1e12;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> v;
		distance = sqrt(double((x - a) * (x - a)) + double((y - b) * (y - b))) / v;
		if (res >= (distance + eps))
			res = distance;
	}
	cout << setprecision(7) << fixed << res;
}
