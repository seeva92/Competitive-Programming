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
int arr[5][5], brr[5][5];
bool done() {
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			if (arr[i][j] == 1)
				return false;
	return true;
}
int main() {
	// std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	char c;
	while (t--) {
		memset(arr, 0, sizeof arr);
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++) {
				scanf(" %c", &c); arr[i][j] = c - '0';
			}

		int k = 0;
		while (!done()) {
			memset(brr, 0, sizeof brr);
			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++) {
					brr[i][j] = (arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j]) % 2;
				}
			for (int i = 1; i <= 3; i++)
				for (int j = 1; j <= 3; j++)
					arr[i][j] = brr[i][j];
			k++;
		}
		printf("%d\n", k - 1);

	}
}