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
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int n, m, i, j, count = 1;
	char c;
	cin >> n >> m;
	while (true) {
		int arr[n][m];
		memset(arr, 0, sizeof arr);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				cin >> c;
				if (c == '*')
					arr[i][j] = -1;
			}


		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (arr[i][j] != -1) {
					if (i - 1 >= 0 && arr[i - 1][j] == -1)
						arr[i][j]++;
					if (i - 1 >= 0 && j - 1 >= 0 && arr[i - 1][j - 1] == -1)
						arr[i][j]++;
					if (i - 1 >= 0 && j + 1 < m && arr[i - 1][j + 1] == -1)
						arr[i][j]++;
					if (j - 1 >= 0 && arr[i][j - 1] == -1)
						arr[i][j]++;
					if (j + 1 < m && arr[i][j + 1] == -1)
						arr[i][j]++;
					if (i + 1 < n && arr[i + 1][j] == -1)
						arr[i][j]++;
					if (i + 1 < n && j - 1 >= 0 && arr[i + 1][j - 1] == -1)
						arr[i][j]++;
					if (i + 1 < n && j + 1 < m && arr[i + 1][j + 1] == -1)
						arr[i][j]++;
				}
				// for (int k = 0; k < n; k++, cout << '\n')
				// 	for (int l = 0; l < m; l++)
				// 		if (arr[k][l] == -1)
				// 			cout << '*';
				// 		else
				// 			cout << arr[k][l];
			}
		}

		cout << "Field #" << count << ":\n"; count++;
		for (i = 0; i < n; i++, cout << '\n')
			for (j = 0; j < m; j++)
				if (arr[i][j] == -1)
					cout << '*';
				else
					cout << arr[i][j];

		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cout << '\n';
	}
}