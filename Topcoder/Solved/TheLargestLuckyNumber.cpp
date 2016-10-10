// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheLargestLuckyNumber.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class TheLargestLuckyNumber {
public:
	int find(int n) {
		string str; int len = 0, j;
		for (int i = n; i >= 0; i--) {
			str = to_string(i); len = str.size();
			for (j = 0; j < len; j++) {
				if (!(str[j] == '4' || str[j] == '7')) break;
			}
			if (j == len) return i;
		}
	}
};
