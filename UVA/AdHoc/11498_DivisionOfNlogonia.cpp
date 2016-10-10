#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
	// cout << "Get ready folks";
	std::ios::sync_with_stdio(false);
	int k;
	//freopen("1.txt", "r", stdin);
	while (1) {
		cin >> k;
		if (k == 0)
			break;
		int n, m, x, y;
		cin >> n >> m;
		while (k--) {
			cin >> x >> y;
			if (x > n && y > m)
				cout << "NE" << '\n';
			else if (x < n && y < m)
				cout << "SO" << '\n';
			else if (x < n && y > m)
				cout << "NO" << '\n';
			else if (x > n && y < m)
				cout << "SE" << '\n';
			else if (x == n || y == m)
				cout << "divisa" << '\n';
		}
	}

	return 0;
}