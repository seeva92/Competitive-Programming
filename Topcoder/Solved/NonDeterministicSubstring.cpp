// BEGIN CUT HERE

// END CUT HERE
#line 5 "NonDeterministicSubstring.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class NonDeterministicSubstring {
public:
	long long ways(string A, string B) {
		if (A.size() < B.size()) return 0;
		int len = int(A.size()); int len1 = int(B.size());
		long long res = 0;
		unordered_map<string, int> mp;
		for (int i = 0; i < len; i++) {
			int j, k;
			string temp = "";
			for (k = i, j = 0; j < len1 && k < len; j++, k++) {
				if (B[j] == '?') {temp += A[k]; continue;}
				else if (A[k] == B[j]) {temp += A[k]; continue;}
				else break;
			}
			if ((j == len1) && (!mp[temp])) {
				mp[temp]++;
				res++;
			}
		}
		return res;
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	NonDeterministicSubstring n;
// 	cout << n.ways("00010001",
// 	               "??") << endl;
// }
