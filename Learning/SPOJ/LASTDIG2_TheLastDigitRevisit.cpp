#include <bits/stdc++.h>
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int arr[10] = {0}; int t; cin >> t;
	long long b;
	string a;
	for (int x = 0; x < t; x++) {
		memset(arr, 0, sizeof arr);
		cin >> a >> b;
		if (b == 0) {cout << 1 << endl; continue;}

		int aa = int(a[int(a.size()) - 1]) - 48;
		int res = aa;
		int c = 0;
		vector<int> v;
		while (!arr[res]) {
			v.push_back(res); arr[res] = 1;
			res = (res * aa) % 10;
			c++;
		}
		cout << v[(b - 1) % c] << endl;
	}
}
