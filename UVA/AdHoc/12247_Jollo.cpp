#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
bool choose(vector<int> st, int val) {
	for (int i = 0; i < (int)st.size(); i++)
		if (val == st[i])
			return true;
	return false;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int x;
	int ps[3];
	int pn[3];
	while (true) {
		int idx = 0;
		std::vector<int> v;
		while (idx < 3) {
			cin >> ps[idx++]; v.push_back(ps[idx - 1]);
		}
		idx = 0;
		while (idx < 2) {
			cin >> pn[idx++]; v.push_back(pn[idx - 1]);
		}
		if (ps[0] == 0)
			break;
		sort(ps, ps + 3);
		sort(pn, pn + 2);



		idx = 3;
		int count = 0;
		int nextcard = INT_MAX;
		int maxvalue = max(ps[2], pn[1]) + 1;
		maxvalue = maxvalue > 52 ? 52 : maxvalue;
		for (int i = maxvalue; i >= 1; i--) {
			if (choose(v, i))
				continue;
			// cout<<i<<" ";
			pn[2] = i;
			bool flag = true;
			do {
				count = 0;
				for (int j = 0; j < 3; j++) {
					if (ps[j] < pn[j])
						count++;
				}
				if (count < 2) {
					flag = false;
					break;
				}
			} while (next_permutation(ps, ps + 3));
			sort(ps, ps + 3);
			if (flag) {
				nextcard = min(nextcard, pn[2]);
			}
		}
		if (nextcard != INT_MAX)
			cout << nextcard << '\n';
		else
			cout << -1 << '\n';


	}
}