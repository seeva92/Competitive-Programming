// BEGIN CUT HERE

// END CUT HERE
#line 5 "MultiplicationTable2Easy.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class MultiplicationTable2Easy {
public:
	string isGoodSet(vector <int> table, vector <int> t) {
		sort(t.begin(), t.end());
		int n = sqrt(int(table.size()));
		for (size_t i = 0; i < t.size(); i++)
			for (size_t j = 0; j < t.size(); j++) {
				if (!binary_search(t.begin(), t.end(), table[t[i] * n + t[j]]))
					return "Not Good";
			}
		return "Good";
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	int arr[] = {1, 1, 2, 3,
// 	             1, 0, 2, 3,
// 	             3, 3, 0, 3,
// 	             2, 2, 2, 0
// 	            };
// 	int brr[
// 	vector<int> v (arr,arr+16);
// 	vector<int> t
// } 1
