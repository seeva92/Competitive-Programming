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
	char c; int n;
	bool arr[110]; memset(arr, 0, sizeof arr);
	int val[110];
	arr[0] = true;
	int cnt = 1, plus = 1, minus = 0;
	while (cin >> c) {
		if (c == '=') break;
		if (c == '+') {arr[cnt++] = true; plus++;}
		else if (c == '-') { arr[cnt++] = false; minus++;}
	}
	for (int i = 0; i < (plus + minus); i++) val[i] = 1;
	cin >> n;
	int add = n - plus + minus;
	bool pos = (add >= 0);
	if (add < 0) add = -add;
	for (int i = 0; i < cnt; i++) {
		if (arr[i] == pos) {
			int diff = n - val[i];
			diff = min(diff, add);
			val[i] += diff;
			add -= diff;
		}
	}
	bool possible = (add == 0);
	if (possible) {
		cout << "Possible" << endl;
		cout << val[0];
		for (int i = 1; i < cnt; i++) {
			if (arr[i]) cout << " + ";
			else cout << " - ";
			cout << val[i];
		}
		cout << " = " << n << endl;

	} else cout << "Impossible" << endl;

}
