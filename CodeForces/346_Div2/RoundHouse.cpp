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
	int n, a, b;
	cin >> n >> a >> b;
	int arr[n + 1];
	if (b > 0) {
		for (int i = 1; i <= b; i++) {
			++a;
			if (a > n) a = 1;
		}
	} else {
		b = abs(b);
		for (int i = 1; i <= b; i++) {
			--a;
			if (a == 0) a = n;
		}
	}
	cout << a << endl;
}