// BEGIN CUT HERE

// END CUT HERE
#line 5 "Istr.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Istr {
public:
	int count(string s, int k) {
		int arr[26] = {0};
		for (size_t i = 0; i < s.size(); i++)
			arr[s[i] - 'a']++;
		vector<int> v;
		for (int i = 0; i < 26; i++) if (arr[i]) v.push_back(arr[i]);
		for (int i = 0; i < k; i++) {
			sort(v.begin(), v.end());
			if (v[v.size() - 1])
				v[v.size() - 1]--;
		}
		int total = 0;
		for (size_t i = 0; i < v.size(); i++)
			total += (v[i] * v[i]);
		return total;
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// }
