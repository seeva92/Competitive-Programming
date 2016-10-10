#line 5 "ConsecutiveNumbers.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class ConsecutiveNumbers {
public:
	vector <int> missingNumber(vector <int> numbers) {
		sort(numbers.begin(), numbers.end());
		// int diffCount = 0;
		// bool diffFlag = false;
		vector<int> res;
		int n = numbers.size();
		for (int i = 1; i < n; i++) {
			if (abs(numbers[i] - numbers[i - 1]) == 1) continue;
			if (abs(numbers[i] - numbers[i - 1]) == 2) {
				res.push_back(numbers[i] - 1);
			} else {
				res.clear();
				return res;
			}
		}

		if (int(res.size()) > 1) {
			res.clear();
		} else if (int(res.size()) == 0) {
			if (numbers[0] - 1 > 0 ) res.push_back(numbers[0] - 1);
			if (numbers[numbers.size() - 1] + 1 > 0) res.push_back(numbers[numbers.size() - 1] + 1);

		}
		return res;
	}
};
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
// 	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
// #endif
// }


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
