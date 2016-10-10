// BEGIN CUT HERE

// END CUT HERE
#line 5 "ReplacingDigit.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class ReplacingDigit {
public:
	int maxlength(vector<string> & A) {
		int val = INT_MIN;
		for (auto it : A)
			if (val < (int)it.size()) val = (int)it.size();

		return val;
	}
	int getSum(vector<string> & v) {
		int total = 0;
		string::size_type sz;
		for (auto it : v)
			total += atoi(it.c_str());
		return total;
	}
	int getMaximumStockWorth(vector <int> A, vector <int> D) {
		sort(A.begin(), A.end(), greater<int>());

		vector<string> v;
		for (auto it : A) v.push_back(to_string(it));

		int maxlen = maxlength(v);
		int lenD = int(D.size());
		int lenA = int(A.size());
		for (int l = 0; l < maxlen; l++) {
			for (int k = 0; k < lenA; k++) {
				if (l < (int)v[k].size()) {
					for (int i = 9; i >= 1; i--) {
						if (D[i - 1] > 0) {
							if (int(v[k][l] - '0') < i) {
								v[k][l] = (char)(i + '0');
								D[i - 1]--;
								break;
							}
						}
					}
				}
			}
		}
		return getSum(v);
	}
};
int main() {
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
	ReplacingDigit r;
	vector<int> v {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
	vector<int> v1 {11, 2, 8, 10, 7, 6, 3, 1, 3};
	cout << r.getMaximumStockWorth(v, v1) << endl;
}
