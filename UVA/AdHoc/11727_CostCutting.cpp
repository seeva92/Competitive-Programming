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
	std::ios_base::sync_with_stdio(false);
	//freopen("1.txt", "r", stdin);
	int t;
	cin >> t;
	int a, b, c;
	int mx, mn;
	for (int i = 1; i <= t; i++) {
		cin >> a >> b >> c;
		mx = max(a, max(b, c));
		mn = min(a, min(b, c));
		if (a != mx && a != mn)
			cout << "Case " << i << ": " << a << '\n';
		else if (b != mx && b != mn)
			cout << "Case " << i << ": " << b << '\n';
		else
			cout << "Case " << i << ": " << c << '\n';
	}
	return 0;
}