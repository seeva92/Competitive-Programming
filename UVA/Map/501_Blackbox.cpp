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
	int k, m, n, x;

	scanf("%d", &k);
	multiset<int>::iterator it;
	while (k--) {
		multiset<int> st;
		scanf("%d %d", &m, &n);
		int arr[m + 2] = {0};
		for (int i = 1; i <= m; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);
			for (int j = st.size() + 1; j <= x; j++) {
				st.insert(arr[j]);

				if (j == 1) {
					it = st.begin();
				} else {
					if (arr[j] < *it)
						--it;
				}
			}
			if (i == 1)
				printf("%d\n", *it);
			else {
				++it;
				printf("%d\n", *it);
			}

		}
		if (k != 0)
			printf("\n");
	}
}


