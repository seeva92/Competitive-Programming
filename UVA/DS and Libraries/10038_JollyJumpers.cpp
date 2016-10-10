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
int arr[(int)1e6];
int main() {
	// std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int n, x;
	while (scanf("%d", &n) == 1) {
		memset(arr, 0, sizeof arr);
		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> x; v.push_back(x);
		}

		if ((int)v.size() == 1) {
			cout << "Jolly" << '\n'; continue;
		}
		int result;
		for (int i = 0; i < (int)v.size(); i++) {
			result = abs(v[i] - v[i - 1]);
			if (result >= 1 && result <= n - 1)
				arr[result] = 1;
		}

		int i;
		for (i = 1; i < n; i++)
			if (arr[i] != 1)
				break;

		if (i == n) {
			cout << "Jolly" << '\n';
		} else {
			cout << "Not jolly" << '\n';
		}

	}
}