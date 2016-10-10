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
using namespace std;
vector<string> w1, w2;
bool visited[20];
class DoubleWeights {
public:
	int compute(int idx, int wt1, int wt2) {
		if (idx == 1) return wt1 * wt2;

		int curr = INT_MAX;
		for (int i = 0; i < int(w1[idx].size()); i++) {
			if (w1[idx][i] == '.' && w2[idx][i] == '.') continue;
			else {
				int lw = w1[idx][i] == '.' ? 0 : w1[idx][1];
				int rw = w2[idx][i] == '.' ? 0 : w2[idx][1];
				curr = min(curr, compute(i, wt1 + lw, wt2 + rw));
			}
		}
		if (curr == INT_MAX) return -1;
		return curr;
	}
	int minimalCost(vector <string> weight1, vector <string> weight2) {
		w1 = weight1; w2 = weight2;
		memset(visited, 0, sizeof visited);
		return compute(0, 0, 0);
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// }
