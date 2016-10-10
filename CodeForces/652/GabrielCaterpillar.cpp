#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int h1, h2, a, b;
	cin >> h1 >> h2 >> a >> b;
	int h = h2 - h1;
	if (h <= (8 * a))
		cout << 0 << endl;
	else if (b >= a) {
		cout << -1 << endl;
	} else {
		h -= 8 * a;
		int diff = (a - b) * 12;
		cout <<  (h + diff - 1) / diff << endl;
	}

}