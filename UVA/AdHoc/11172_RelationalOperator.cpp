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
	// freopen("1.txt", "r", stdin);
	int t;
	cin >> t;
	int a, b;
	while (t--) {
		cin >> a >> b;
		if (a < b)
			cout << "<" << '\n';
		else if (a > b)
			cout << ">" << '\n';
		else
			cout << "=" << '\n';
	}
	return 0;
}