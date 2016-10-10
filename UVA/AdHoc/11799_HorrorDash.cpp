#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <climits>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	int t, n, x;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int result = INT_MIN;
		for (int j = 1; j <= n; j++) {
			cin >> x;
			result = max(result, x);
		}
		cout << "Case " << i << ": " << result << '\n';
	}
	return 0;
}