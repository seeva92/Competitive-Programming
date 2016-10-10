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
	int t; cin >> t;
	while (t--) {
		int a; string b; cin >> a >> b;
		if (a == 0) {cout << b << endl; continue;}
		int ib = 0;
		for (auto i : b)
			ib = (ib * 10 + (i - '0')) % a;
		while (ib) {
			int temp = a % ib;
			a = ib;
			ib = temp;
		}
		cout << a << endl;
	}

}