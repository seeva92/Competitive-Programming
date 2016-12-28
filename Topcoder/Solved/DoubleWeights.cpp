// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleWeights.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <climits>
typedef long long ll;
const ll MAX = 1e5 + 7;
using namespace std;
vector<string> w1, w2;
bool visited[20];
ll wt1[50][50], wt2[50][50], dp[50], dpw1[50], dpw2[50];
class DoubleWeights {
	int len;
public:
	// int compute(int idx, int wt1, int wt2) {
	// 	if (idx == 1) return wt1 * wt2;

	// 	int curr = INT_MAX;
	// 	for (int i = 0; i < int(w1[idx].size()); i++) {
	// 		if (w1[idx][i] == '.' && w2[idx][i] == '.') continue;
	// 		else {
	// 			int lw = w1[idx][i] == '.' ? 0 : w1[idx][1];
	// 			int rw = w2[idx][i] == '.' ? 0 : w2[idx][1];
	// 			curr = min(curr, compute(i, wt1 + lw, wt2 + rw));
	// 		}
	// 	}
	// 	if (curr == INT_MAX) return -1;
	// 	return curr;
	// }
	int compute() {
		memset(dpw1, 0, sizeof dpw1); memset(dpw2, 0, sizeof dpw2);
		for (int i = 0; i < len; i++) dp[i] = MAX; dp[0] = 0;

		for (int k = 0; k < len - 1; k++)
			for (int i = 0; i < len; i++) {
				for (int j = 0; j < len; j++) {
					if (dp[i] == MAX) continue;
					if ((dpw1[i] + wt1[i][j]) * (dpw2[i] + wt2[i][j]) < dp[j]) {
						dp[j] = (dpw1[i] + wt1[i][j]) * (dpw2[i] + wt2[i][j]);
						dpw1[j] = dpw1[i] + wt1[i][j];
						dpw2[j] = dpw2[i] + wt2[i][j];
					}
				}
			}
		if (dp[1] != MAX) return dp[1];
		return -1;
	}
	int minimalCost(vector <string> weight1, vector <string> weight2) {
		// w1 = weight1; w2 = weight2;
		// memset(visited, 0, sizeof visited);
		// return compute(0, 0, 0);
		len = weight1.size();
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++) {
				if (weight1[i][j] == '.') {
					wt1[i][j] = MAX;
					wt2[i][j] = MAX;
				} else {
					wt1[i][j] = weight1[i][j] - '0';
					wt2[i][j] = weight2[i][j] - '0';
				}
			}
		return compute();
		// return 0;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	DoubleWeights d;
	cout << d.minimalCost({"..", ".."}, {"..", ".."}); cout << '\n';
	cout << d.minimalCost({".62", "6.1", "21."}, {".33", "3.1", "31."}); cout << '\n';
	cout << d.minimalCost({"..14", "..94", "19..", "44.."}, {"..94", "..14", "91..", "44.."}); cout << '\n';
	cout << d.minimalCost({"..14", "..14", "11..", "44.."}, {"..94", "..94", "99..", "44.."}); cout << '\n';
	cout << d.minimalCost({".4...1", "4.1...", ".1.1..", "..1.1.", "...1.1", "1...1."}, {".4...1", "4.1...", ".1.1..", "..1.1.", "...1.1", "1...1."}); cout << '\n';
}
