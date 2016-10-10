// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomSort.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class RandomSort {
	map <vector<int>, double> mp;
public:
	double compute(vector<int> arr) {
		if (mp.count(arr)) return mp[arr];
		double &ans = mp[arr];
		int len = int(arr.size());
		int total = 0;
		for (int i = 0; i < len; i++)
			for (int j = i + 1; j < len; j++) {
				if (arr[i] > arr[j]) {
					swap(arr[i], arr[j]);
					ans += 1 + compute(arr);
					swap(arr[i], arr[j]);
					total++;
				}
			}

		if (total == 0) ans = 0;
		else ans = ans / total;

		return ans ;

	}
	double getExpected(vector <int> permutation) {
		mp.clear();
		return compute(permutation);
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
}
