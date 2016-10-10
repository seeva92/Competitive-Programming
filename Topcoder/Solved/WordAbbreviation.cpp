// BEGIN CUT HERE

// END CUT HERE
#line 5 "WordAbbreviation.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class WordAbbreviation {
public:
	vector <string> getAbbreviations(vector <string> words) {
		vector<string> result;
		set<string> st[57];
		int n = words.size();

		for (int i = 0; i < n; i++) {
			int len = words[i].size();
			for (int j = 1; j <= len; j++) {
				// cout << words[i].substr(0, j) << '\n';
				st[i].insert(words[i].substr(0, j));
			}
		}

		// string temp;
		for (int i = 0; i < n; i++) {
			for (auto temp : st[i]) {
				int k = 0;
				for (k = 0; k < n; k++) {
					if (i == k) continue;
					if (st[k].find(temp) != st[k].end())
						break;
				}
				if (k == n) {
					result.push_back(temp);
					break;
				}
			}
		}

		// for (auto word : result) {
		// cout << word << endl;
		// }
		return result;
	}
};
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
// 	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
// #endif
// 	WordAbbreviation w;

// 	vector<string> v {"abc", "def", "ghi"};
// 	w.getAbbreviations(v);

// }
