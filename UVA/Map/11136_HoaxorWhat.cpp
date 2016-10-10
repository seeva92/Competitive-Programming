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
	register long n, x, k, total;
	register long low, high, i, j;
	map<long, int> bills;
	map<long, int>::iterator first = bills.begin();
	map<long, int>::iterator last = bills.begin();
	while (scanf("%ld", &n), n != 0) {
		bills.clear();
		total = 0;
		for (i = 0; i < n; i++) {
			scanf("%ld", &k);
			for (j = 0; j < k; j++) {
				scanf("%ld", &x);
				bills[x]++;
			}
			first = bills.begin(); last = prev(bills.end());

			total += (last->first - first->first);

			if (first->first == last->first) {
				if (first->second > 2)
					bills[first->first] -= 2;
				else
					bills.erase(first->first);
			}
			else {
				if (first->second > 1)
					bills[first->first]--;
				else
					bills.erase(first->first);

				last = prev(bills.end());
				if (last->second > 1)
					bills[last->first]--;
				else
					bills.erase(last->first);
			}
		}
		printf("%ld\n", total);

	}
}


