#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	long long j, s, m;
	cin >> j >> s >> m;
	m = m - j;
	if ((m <= 0) || (m <= s) || ((m / s) % 2 != 0))  cout << "Unlucky Chef" << endl;
	else {
		cout << "Lucky Chef" << endl;
	}

}