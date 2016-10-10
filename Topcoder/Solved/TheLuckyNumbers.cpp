// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheLuckyNumbers.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class TheLuckyNumbers {
public:
	vector<long long> v;
	int count(int a, int b) {
		int cn = 0;
		v.push_back(4); v.push_back(7);
		for (int i = 0; i < int(v.size()); i++) {
			// cout << v[i] << endl;
			if (v[i] >= (long long)a && v[i] <= (long long)b) cn++;
			if (v[i] > (long long)1000000000) break;
			v.push_back(v[i] * 10 + 4);
			v.push_back(v[i] * 10 + 7);
		}
		return cn;
	}
};
// 44 47 74 77 444 447 474 477 744 747 774 777
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
// 	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
// #endif
// 	TheLuckyNumbers t;
// 	cout << t.count(1, 1000000000);
// }
