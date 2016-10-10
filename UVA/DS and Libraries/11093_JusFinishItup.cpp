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
int main() {
	// std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int t, n, i;
	scanf("%d %d", &t, &n);
	for (int x = 1; x <= t; x++) {
		int petrol[n] = {0};
		int distance[n] = {0};
		long long int available = 0L;
		for (i = 0; i < n; i++)
			scanf("%d", &petrol[i]);

		for (i = 0; i < n; i++)
			scanf("%d", &distance[i]);



		int start = 0, end = 1;
		available = petrol[start] - distance[start];
		bool possible = true;
		while (start != end || available < 0) {
			while (start != end && available < 0) {
				available -= petrol[start] - distance[start];
				start = (start + 1) % n;
				if (start == 0) {
					possible = false;
				}
			}

			if (!possible)
				break;
			available += petrol[end] - distance[end];
			end = (end + 1) % n;
		}
		if (!possible)
			printf("Case %d: Not possible\n", x);
		else
			printf("Case %d: Possible from station %d\n", x, start + 1);


		scanf("%d", &n);
	}

}
