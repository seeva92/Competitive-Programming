#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <sstream>
using namespace std;
int main() {
	// std::ios_base::sync_with_stdio(false);
	//freopen("1.txt", "r", stdin);
	stringstream ss;
	int n, b, h, w;
	string str;
	while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
		int price, capacity;
		int minValue = INT_MAX;
		for (int i = 0; i < h; i++) {
			scanf("%d", &price);
			for (int j = 0; j < w; j++) {
				scanf("%d", &capacity);
				if (n <= capacity && (n * price <= b))
					minValue = min(minValue, (n * price));
			}
		}
		if (minValue != INT_MAX)
			cout << minValue << '\n';
		else
			cout << "stay home" << '\n';
	}

	return 0;
}