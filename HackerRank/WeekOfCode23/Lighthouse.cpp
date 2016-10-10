#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
char v[57][57];
string s;
int n, lf, rt, r;
bool flag, valid;
void compute() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == '*') continue;
			lf = 0, rt = n / 2;
			while (lf <= rt) {
				r = (lf + rt) / 2;
				valid = false;
				if ((i - r >= 1) && (i + r <= n) && (j - r >= 1) && (j + r <= n)) {
					flag = true; valid = true;
					for (int k = i - r; (k <= i + r) && flag; k++) {
						for (int l = j - r; (l <= j + r)  && flag; l++)
						{
							if ((r * r) >= (((i - k) * (i - k)) + ((j - l) * (j - l)))) {
								if (v[k][l] == '*') {
									valid = false;
									flag = false; break;
								}
							}
						}
					}
				}
				if (valid) {
					lf = r + 1;
					res = res < r ? r : res;
				} else rt = r - 1;
			}
		}
	}
	cout << res << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> v[i][j];
		}
	compute();
}
