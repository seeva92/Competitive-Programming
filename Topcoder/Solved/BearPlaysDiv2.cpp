#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
map<vector<int>, bool> mp;
bool dp[1507][1507];
class BearPlaysDiv2
{
	int c = 0;
public:
	//My soln
	bool compute(int A, int B, int C, int id) {
		if (c == 10000) return false;
		c++;

		if (mp.count({A, B, C})) return mp[ {A, B, C}];

		if ((A == B) && (B == C)) return true;

		bool flag = false;
		if (!flag && A > 0 && B > 0 && id != 0) {
			if (A < B && B - A > 0) flag |= compute(A + A, B - A, C, 0);
			else if (B < A && A - B > 0) flag |= compute(A - B, B + B, C, 0);
		}
		if (!flag && A > 0 && C > 0 && id != 1) {
			if (A < C && C - A > 0) flag |= compute(A + A, B, C - A, 1);
			else if (C < A && A - C > 0) flag |= compute(A - C, B, C + C, 1);
		}
		if (!flag && B > 0 && C > 0 && id != 2) {
			if (B < C && C - B > 0) flag |= compute(A, B + B, C - B, 1);
			else if (C < B && B - C > 0) flag |= compute(A, B - C, C + C, 1);
		}
		return mp[ {A, B, C}] = flag;
	}
	//Editorial Soln
	void compute(vector<int> v) {
		if (dp[v[0]][v[1]]) return;
		dp[v[0]][v[1]] = 1;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (v[i] < v[j]) {
					vector<int> v1 = {v[i] * 2, v[j] - v[i], v[0 + 1 + 2 - j - i]};
					compute(v1);
				}
			}
	}
	string equalPiles(int A, int B, int C) {
		// mp.clear();
		// bool flag = compute(A, B, C, -1);
		// return flag ? "possible" : "impossible";
		memset(dp, 0, sizeof dp);
		int sum = A + B + C;
		if (sum % 3 == 0) {
			compute({A, B, C});
			return dp[sum / 3][sum / 3] ? "possible" : "impossible";
		}
		return "impossible";
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	BearPlaysDiv2 b;
	cout << b.equalPiles(225, 500, 475) << '\n';
}
