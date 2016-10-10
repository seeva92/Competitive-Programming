// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleString.cpp"
#include <bits/stdc++.h>
using namespace std;
class DoubleString {
public:
	string check(string s) {
		int len = int(s.size());
		if (len % 2 != 0) return "not square";
		for(int i=0,j=len/2;i<(len/2) && j<(len);i++,j++){
			if(s[i]!=s[j]) return "not square";
		}
		return "square";
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	DoubleString d;
// 	cout<<d.check("wowowo");
// }
