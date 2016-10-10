// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParenthesesDiv2Hard.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class ParenthesesDiv2Hard {
public:
	int minSwaps(string s, vector <int> L, vector <int> R) {
		int len = int(L.size());
		for (int i = 0; i < len; i++)
			if ((R[i] - L[i] + 1) % 2 != 0) return -1;
		int tl = 0, tr = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') tl++;
			else tr++;

		}
		int count = 0;
		vector<pair<int, int>> S;
		for (int i = 0; i < len; i++) {
			stack<char> stk;
			int l = 0, r = 0;
			for (int j = L[i]; j <= R[i]; j++) {
				if (s[j] == '(')
					stk.push(s[j]);
				else {
					if (!stk.empty()) stk.pop();
					else r++;
				}
			}
			l = int(stk.size());
			tl -= l;
			tr -= r;
			if (l == r) count++;
			else {
				S.push_back({l, r});
			}
		}

		for (int i = 0; i < len; i++) {
			for (auto it : S) {
				
			}
		}
		return count;
	}
};
int main() {
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
}
