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
void warbegins(string str[], string des[], int r, int c, char home, char away, int j, int k) {
	if (k - 1 >= 0 && str[j][k - 1] == away)
		des[j][k - 1] = home;
	if (k + 1 < c && str[j][k + 1] == away)
		des[j][k + 1] = home;
	if (j - 1 >= 0 && str[j - 1][k] == away)
		des[j - 1][k] = home;
	if (j + 1 < r && str[j + 1][k] == away)
		des[j + 1][k] = home;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int t, r, c, n, i, j, k;
	cin >> t;
	while (t--) {
		cin >> r >> c >> n;
		if (r == 0 || c == 0)
			continue;
		string str[r];
		for (i = 0; i < r; i++)
			cin >> str[i];

		string des[r];
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				des[i].push_back('-');

		for (i = 0; i < n; i++) {
			for (j = 0; j < r; j++) {
				for (k = 0; k < c; k++) {
					if (str[j][k] == 'R') {
						warbegins(str, des, r, c, 'R', 'S', j, k);
					} else if (str[j][k] == 'S') {
						warbegins(str, des, r, c, 'S', 'P', j, k);
					} else {
						warbegins(str, des, r, c, 'P', 'R', j, k);
					}

				}
			}
			//Source
			// for (j = 0; j < r; j++)
			// 	cout << str[j] << endl;
			// //Destination
			// for (j = 0; j < r; j++)
			// 	cout << des[j] << endl;

			for (j = 0; j < r; j++)
				for (k = 0; k < c; k++)
					if (des[j][k] != '-') {
						str[j][k] = des[j][k]; des[j][k] = '-';
					}
		}

		for (i = 0; i < r; i++, cout << '\n')
			for (j = 0; j < c; j++)
				cout << str[i][j];

		if (t != 0)
			cout << '\n';
	}
}