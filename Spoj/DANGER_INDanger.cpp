#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	while (cin >> str && !str.empty()) {
		if (str == "00e0") break;
		stringstream ss;
		ss << str;
		char e;
		ll x, z;
		ss >> x >> e >> z;
		for (int i = 1; i <= z; i++) x *= 10;
		ll n = log2(x);
		ll m = pow(2, n);
		cout << (1 + ((x - m) * 2)) << '\n';
	}
}
