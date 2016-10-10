#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int n, m;
	string str = " knights may be placed on a ";
	while (cin >> n >> m, n || m) {
		if (n == 0 || m == 0)
			cout << 0 << str << n << " row " << m << " column board.\n";
		else if (n == 1 || m == 1)
			cout << max(n, m) << str << n << " row " << m << " column board.\n";
		else if (n == 2 && m == 2)
			cout << 4 << str << n << " row " << m << " column board.\n";
		else if (n == 2 || m == 2) {
			cout << (max(n, m) % 2 == 0 ? (n * m) / 2+ (max(n,m)%4==0 ? 0 : 2) : (n * m) / 2 + 1) << str << n << " row " << m << " column board.\n";;
		}
		else {
			cout << ((n * m) % 2 == 0 ? (n * m) / 2 : (n * m + 1) / 2) << str << n << " row " << m << " column board.\n";;
		}
	}
}