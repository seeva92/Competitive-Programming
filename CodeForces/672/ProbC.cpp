#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
ll x[100007], y[100007];
pair<double, int> adis[100007], bdis[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	ll ax, ay, bx, by, tx, ty, n;
	cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
	double total = 0.0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		double dx = x[i] - tx; double dy = y[i] - ty;
		double dis = sqrt((dx * dx) + (dy * dy));
		total += (dis * 2.0);

		dx = x[i] - bx; dy = y[i] - by;
		bdis[i] = {sqrt((dx * dx) + (dy * dy)) - dis, i};
		dx = x[i] - ax; dy = y[i] - ay;
		adis[i] = {sqrt((dx * dx) + (dy * dy)) - dis, i};
	}
	cout << setprecision(12) << fixed;
	sort(adis, adis + n); sort(bdis, bdis + n);
	double ans = min(total + adis[0].first, total + bdis[0].first);
	for (int i = 0; i < min(2, (int)n); i++)
		for (int j = 0; j < min(2, (int)n); j++) {
			if (adis[i].second == bdis[j].second) continue;
			ans = min(ans, total + adis[i].first + bdis[j].first);
		}
	cout << ans << endl;

}