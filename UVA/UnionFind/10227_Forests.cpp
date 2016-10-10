#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int test, t, p; scanf("%d", &test);
	int pcount;
	string str;
	cin.ignore();
	getline(cin, str);

	while (test--) {
		getline(cin, str); sscanf(str.c_str(), "%d %d", &pcount, &t);
		vector<int> people[pcount + 1];
		set<set<int>> result;
		while (getline(cin, str), !str.empty()) {
			sscanf(str.c_str(), "%d %d", &p, &t);
			people[p].push_back(t);

		}
		for (int i = 1; i <= pcount; i++) {
			result.insert(set<int>(people[i].begin(), people[i].end()));
		}
		printf("%d\n", result.size());
		if (test != 0) printf("\n");

	}

}