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
#include <stack>
#include <queue>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int t;
	cin >> t;
	int idx = 1;
	while (t--) {
		string str;
		stack<pair<int, char>> st;
		stack<char> ch;
		for (int i = 0; i < 52; i++) {
			cin >> str;
			// cout<<str;
			if (str[0] >= '0' && str[0] <= '9')
				st.push(make_pair(str[0] - '0', str[0]));
			else
				st.push(make_pair(10, str[0]));
			ch.push(str[1]);
		}
		vector<pair<int, char>> v;
		vector<char> p;
		for (int i = 0; i < 25; i++) {
			v.push_back(st.top()); st.pop();
			p.push_back(ch.top()); ch.pop();
		}

		int Y = 0;
		int X = 0;
		for (int j = 0; j < 3 && !st.empty(); j++) {
			X = st.top().first;
			Y += X;
			st.pop();
			ch.pop();
			for (int k = 0; k < (10 - X) && !st.empty(); k++) {
				st.pop(); ch.pop();
			}
		}

		while (!st.empty()) {
			v.push_back(st.top()); st.pop();
			p.push_back(ch.top()); ch.pop();
		}
		// for(size_t i = 0;i<v.size();i++)
		// cout<<v[i]<<" "<<p[i]<<'\n';
		cout << "Case " << idx << ": " << v[(int)v.size() - Y].second << p[(int)v.size() - Y] << '\n';
		idx++;

	}
}