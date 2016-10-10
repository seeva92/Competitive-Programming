#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
#include <climits>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
const int MAX = 1e4 + 7;
int t, n;
int A[MAX], B[MAX], C[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> B[i];
		for (int i = 0; i < n; i++) cin >> A[i];
		set<int> st;
		st.insert(A[0]);
		st.insert(A[0] + B[0]);
		if (n > 1) {
			st.insert(A[0] + B[1]);
			st.insert(A[0] + B[1] + B[0]);
		}
		int res = INT_MIN;
		for (auto it : st) {
			for (int i = 0; i < n; i++) C[i] = B[i];
			int x, y, z;
			bool flag = true;
			for (int i = 0; i < n && flag ; i++) {

				x = y = z = 0;

				if (i - 1 >= 0) {
					x = B[i - 1]; B[i - 1] = 0;
				}
				if (i + 1 != n) {
					if (A[i] + x == it) continue;
				}

				y = B[i];
				if (A[i] + x + y == it) {
					B[i] = 0;
					continue;
				}
				if (i + 1 != n) {
					if (i + 1 < n) {
						z = B[i + 1];
					}
					if (A[i] + x + z == it) {B[i + 1] = 0; continue;}

					if (A[i] + x + y + z == it) {
						B[i] = 0;
						if (i + 1 < n) B[i + 1] = 0;
						continue;
					}
				}

				flag = false;
			}
			if (flag) {
				res = max(res, it);
			}
			for (int i = 0; i < n; i++) B[i] = C[i];
		}
		if (res == INT_MIN) cout << "-1\n";
		else cout << res << '\n';
	}
}
