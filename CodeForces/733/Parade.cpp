#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
const int MAX = 100007;
int L[MAX], R[MAX], N;
int lt = 0, rt = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i] >> R[i];
		lt += L[i]; rt += R[i];
	}
	int res = abs(lt - rt);
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		if (res < abs((lt - L[i] + R[i]) - (rt - R[i] + L[i]))) {
			res = abs((lt - L[i] + R[i]) - (rt - R[i] + L[i]));
			idx = i;
		}
	}
	cout << idx << '\n';
}
