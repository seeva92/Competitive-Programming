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
#include <unordered_set>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, t, high = 0, x;
	int val = 0;
	unordered_set<int> st;
	deque<int> q;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		q.clear();
		high = 0; st.clear(); scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &x);
			if (st.find(x) == st.end()) {
				st.insert(x);
				q.push_back(x);
				if (st.size() > high)
					high = st.size();
			}
			else {
				while (!q.empty()) {
					val = q.front();
					st.erase(q.front());
					q.pop_front();
					if(val == x)
						break;
				}
				st.insert(x);
				q.push_back(x);
				if (st.size() > high)
					high = st.size();
			}
		}
		if (st.size() > high)
			high = st.size();
		printf("%d\n", high);
	}
}


