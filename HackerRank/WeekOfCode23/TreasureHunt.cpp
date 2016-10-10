#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	double x, y, a, b; cin >> x >> y >> a >> b;
	double a1, b1; a1 = -b; b1 = a;
	double det = (a * b1) - (a1 * b);
	double detA = (x * b1) - (a1 * y);
	double detB = (a * y) - (x * b);
	// cout << det << " " << detA << " " << detB << '\n';
	cout << fixed << setprecision(12)  << detA / det << '\n';
	cout << fixed << setprecision(12) << detB / det << '\n';



}
// 7.0 + 7.0
// 17.5
// 7.5
// 3.5 * (5) - (1.5)*(5) = 10
// 150 - 7.5 = 10
// ka + na1 = x
// kb + nb1 = y

// 5k - 5n = 10
// 4k + 4k = 20

// 20-(-20) = 40
// 40 -(-100) = 140
// 100 - 40 =

// 5k - 5n = 10
//           4k + 4n = 20

//                     20k - 20n = 40
//                                 20k + 20n = 400
//                                         40k = 440
//                                                 k = 11
//                                                         55 - 5n = 10
//                                                                 45 = 5n
//                                                                         n = 9
// 1
// 2 1
// 4 2
// 6 3
// 8 4

// 5 = 1k - 1n
// 3 = 1k + 1n
// 8 = 2k k = 4;
// 5 - 4 = -n
// 1 = -n;
// n = -1;
// k = 4;

// 1 -1
// 1 1

// 1 5
// 1 3

// k - n = 5
// k = 5 + n
// a = 1 b = 1, a1 = -1, b1 = 1
// 1k - 1n = 5
// 1k + 1n = 3
