#line 5 "ParenthesesDiv2Medium.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class ParenthesesDiv2Medium {
public:
	vector <int> correct(string s) {
		vector<int> res;
		int len = int(s.size());
		stack<pair<char, int>> stk;
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				stk.push({s[i], i});
			} else {
				if (!stk.empty()) stk.pop();
				else {
					res.push_back(i);
					stk.push({'(', i});
				}
			}
		}
		int l = int(stk.size()) / 2;
		while (l--) {
			res.push_back(stk.top().second);
			stk.pop();
		}
		sort(res.begin(), res.end());
		return res;
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	ParenthesesDiv2Medium p;
// 	vector<int> v = p.correct("");
// 	for (auto it : v) cout << it << " " << endl;
// }


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
