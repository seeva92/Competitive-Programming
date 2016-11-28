#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long N, Q, I, X, Y, L[100007], R[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> R[i];
		if (i != 0) {
			R[i] += L[i - 1];
			L[i] += R[i - 1];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> I >> X >> Y;
		if (I == 1) {
			if (X - 1 == 0) {
				if ((Y - 1) % 2 == 0) cout << L[Y - 1];
				else cout << R[Y - 1];
			}
			else {
				if (((Y - 1) - (X - 1) + 1) % 2 == 0)
					cout << R[Y - 1] - R[X - 2];
				else cout << L[Y - 1] - R[X - 2];
			}
		} else {
			if (X - 1 == 0) {
				if ((Y - 1) % 2 == 0) cout << R[Y - 1];
				else cout << L[Y - 1];
			}
			else {
				if (((Y - 1) - (X - 1) + 1) % 2 == 0)
					cout << L[Y - 1] - L[X - 2];
				else cout << R[Y - 1] - L[X - 2];
			}
		}
		cout << '\n';
	}
}
