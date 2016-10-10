#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int x;
	cout << 1 << endl;
	cout << 2 << " " << 1 << " " << 2 << endl;
	cout << 2 << " " << 3 << " " << 4 << endl; fflush(stdout);
	cin >> x;
	if (x == 0) {
		cout << 2 << endl;
		cout << 5 << endl; fflush(stdout);
	} else if (x > 0) {
		cout << 1 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 1 << " " << 2 << endl; fflush(stdout);
		cin >> x;
		if (x > 0) cout << 2 << endl << 1 << endl;
		else cout << 2 << endl << 2 << endl;
		fflush(stdout);
	} else {
		cout << 1 << endl;
		cout << 1 << " " << 3 << endl;
		cout << 1 << " " << 4 << endl; fflush(stdout);
		cin >> x;
		if (x > 0) cout << 2 << endl << 3 << endl;
		else cout << 2 << endl << 4 << endl;
	}

}