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
	int t, n, m;
	char c;
	cin >> t;
	int count = 0;
	while (t--) {
		cin >> c >> n >> m;
		switch (c) {
		case 'r':
		case 'Q':
			cout << min(n, m) << '\n';
			break;
		case 'k':
			cout << ((n * m) % 2 == 0 ? (n * m) / 2 : (n * m) / 2 + 1) << '\n';
			break;
		case 'K':
			cout << (n % 2 == 0 ? n / 2 : n / 2 + 1)*(m % 2 == 0 ? m / 2 : m / 2 + 1) << '\n';
			break;
		}
	}
}