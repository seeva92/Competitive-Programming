#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N;
class SerejaAndBottles
{
public:
	int x[107], y[107], ans[107];

	SerejaAndBottles() {
		memset(ans, 0, sizeof ans);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (i != j && y[i] == x[j]) ans[j] = 1;
			}
		int cnt = 0;
		for (int i = 0; i < N; i++) if (!ans[i]) cnt++;
		cout << cnt;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	SerejaAndBottles s;
}
