#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int t;
	long long n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		long long req = (n * (n + 1)) / 2;
		if (k == req)
			cout << 0 << endl;
		else if (k < req) {
			cout << (req - k) << endl;
		} else {
			if (k % req > 0)
				cout << req - (k % req) << endl;
			else
				cout << (k % req) << endl;
		}

	}

}