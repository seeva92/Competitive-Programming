#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cmath>
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
	cin.tie(0);
	int n;
	while (cin >> n && n != 0) {
		cout << int(log2(n)) << '\n';
	}
}


// 1 2 3 4 5 6 7 8 9 10

// 1    2
// 1   2 3   4 5 6 7  8 9 10

// day     given
// 	1      1
// 	2      2 3   back- 1
// 	3      8,9,10  back - 2,3
// 	4      4,5,6,7  back- 8,9,10
// 	5      2,3,8,9,10 back - 4,5,6,7
// 	6      1
// 	7      4,5,6,7 back - 8,9,10
// 	8      8,9,10 back - 2,3
// 	9      2,3 back - 1
// 	10      1