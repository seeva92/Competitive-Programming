#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
double X1, X2, Y1, Y2, v1, v2, Y12, Y22;
int t;
double eps = 1;

double findMin( double low,  double high) {
	double res = 1e18;
	while (low <= high) {
		double mid1 = low + (high - low) / 3.0;
		double mid2 = high - (high - low)  / 3.0;
		double t1 = (sqrt((X1 - mid1) * (X1 - mid1) + ( -Y1) * ( -Y1)) / v1) + (sqrt((X2 - mid1) * (X2 - mid1) + ( -Y2) * ( -Y2)) / v2);
		double t2 = (sqrt((X1 - mid2) * (X1 - mid2) + ( -Y1) * ( -Y1)) / v1) + (sqrt((X2 - mid2) * (X2 - mid2) + ( -Y2) * ( -Y2)) / v2);

		// cout << fixed << setprecision(7) << mid << " " << midpv << " " << midv << " " << midnv << '\n';
		if (low == high) {
			double t3 = (sqrt((X1 - low) * (X1 - low) + ( -Y1) * ( -Y1)) / v1) + (sqrt((X2 - low) * (X2 - low) + ( -Y2) * ( -Y2)) / v2);
			res = min(res, t3);
			break;
		}
		if (t1 < t2) {
			high = mid2 - 1;
			res = min(res, t1);
		}
		else if (t1 > t2) {
			res = min(res, t2);
			low = mid1 + 1;
		} else  {
			low = mid1 + 1;
			high = mid2 - 1;
			res = min(res, t1);
		}
	}
	return res;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cout << setprecision(5) << fixed << eps << '\n';
	cin >> t;
	int a1, b1, a2, b2;
	while (t--) {
		cin >> a1 >> b1 >> a2 >> b2 >> v1 >> v2;
		if (a1 == a2) {
			X1 = a1, Y1 = b1, X2 = a2, Y2 = b2;
			cout << setprecision(5) << fixed << (sqrt((X1 - X1) * (X1 - X1) + (0 - Y1) * (0 - Y1)) / v1) + (sqrt((X2 - X2) * (X2 - X2) + (0 - Y2) * (0 - Y2)) / v2);
		}
		else if (a1 > a2) {
			X1 = a2, Y1 = b2, X2 = a1, Y2 = b1; swap(v1, v2);
			cout << setprecision(5) << fixed << findMin(X1, X2);
		}
		else {
			X1 = a1, Y1 = b1, X2 = a2, Y2 = b2;
			cout << setprecision(5) << fixed << findMin(X1, X2);
		}
		cout << '\n';
	}
}

// X1 = -1000000000, Y1 = -20, X2 = 1000000000, Y2 = 20;
// v1 = 40, v2 = 5;
// Y12 = -Y1 * -Y1;
// Y22 = -Y2 * -Y2;
// cout << fixed << eps << '\n';
// cout << findMin(3, 10);
// for ( double i = X1; i <= X2; i = i + .10) {

// cout << i << " " << (sqrt((X1 - i) * (X1 - i) + (0 - Y1) * (0 - Y1)) / v1) + (sqrt((X2 - i) * (X2 - i) + (0 - Y2) * (0 - Y2)) / v2) << '\n';
// }
