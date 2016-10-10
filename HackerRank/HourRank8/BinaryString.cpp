#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int n; string str;
bool hasit(string temp) {
	return (temp.find("010") != string::npos);
}
int compute(int n, string temp) {
	if (hasit(temp)) return 0;
	if (n == 0) return INT_MAX - 1;

	int l = compute(n - 1, temp);
	int r = 0;
	if (temp[n - 1] == '0') {
		temp[n - 1] = '1';
		r = 1 + compute(n - 1, temp);
		return min(l, r);
	} else {
		temp[n - 1] = '0';
		r = 1 + compute(n - 1, temp);
	}
	return min(l, r);
}
int main() {
// #ifndef ONLINE_JUDGE
	// freopen("/home/shiva/Learning/1.txt", "r", stdin);
	// freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> str;
	// cout << compute(n, str);
	int total = 0; bool flag = true;
	int idx = -1, prev = -5;
	for (int i = 0; i < n; i++) {
		idx = (int)str.find("010", idx + 1);
		if (idx == -1) break;
		else {
			if (prev + 2 == idx) {
				if (!flag) {
					total++; flag = true;
				} else flag = !flag;
			} else {
				total++; flag = true;
			}
		}

		prev = idx;
	}
	cout << total << endl;

}