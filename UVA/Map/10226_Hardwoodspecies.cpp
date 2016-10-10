#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n;
	string str;
	cin >> n;
	cin.ignore();
	getline(cin, str);
	// cout<<str<<'\n';
	int count;
	while (n--) {

		count = 0;
		map<string, int> treemp;
		while (getline(cin, str), str != "") {
			// cout<<str<<"\n";
			treemp[str]++;
			count++;
			if (cin.eof())
				break;
		}
		for (auto it : treemp) {
			printf("%s %0.4f\n", it.first.c_str(), (double(it.second) / double(count)) * 100);
		}
		// return 0;
		if (n != 0)
			printf("\n");
	}
}


