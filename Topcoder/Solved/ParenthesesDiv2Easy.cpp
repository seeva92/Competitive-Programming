// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParenthesesDiv2Easy.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
string tmp;
int val = 0;
class ParenthesesDiv2Easy {
public:

	int getDepth(string s) {
		val = 0;
		stack<char> stk;
		int len = int(s.size());
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				stk.push(s[i]);
				if (val < (int)stk.size())
					val = (int)stk.size();
			} else {
				stk.pop();
			}

		}
		return val;
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	ParenthesesDiv2Easy p;
// 	cout << p.getDepth("(())(()((())))") << '\n';
// 	cout << p.getDepth("") << '\n';
// }
