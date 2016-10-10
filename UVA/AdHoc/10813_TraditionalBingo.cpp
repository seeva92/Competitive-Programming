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
#include <map>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int t, i, j;
	cin >> t;
	while (t--) {
		int arr[5][5];
		map<int, pair<int, int>> mp;
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				if (i == 2 && j == 2)
					arr[i][j] = -1;
				else {
					cin >> arr[i][j];
					mp[arr[i][j]] = make_pair(i, j);
				}

		int x;
		map <int, pair<int, int>>::iterator it;
		bool won = false; int at = 0;
		for (int k = 0; k < 75; k++) {
			cin >> x;
			if (!won) {
				it = mp.find(x);
				if (it != mp.end())
					arr[(it->second).first][(it->second).second] = -1;

				for (i = 0; i < 5; i++) {
					for (j = 0; j < 5 && arr[j][i] == -1; j++);
					if (j == 5) {
						won = true; at = k + 1;
					}
				}

				for (i = 0; i < 5; i++) {
					for (j = 0; j < 5 && arr[i][j] == -1; j++);
					if (j == 5) {
						won = true; at = k + 1;
					}
				}

				for (i = 0, j = 0; i < 5 && j < 5 && arr[i][j] == -1; i++, j++);
				if (i == 5 && j == 5) {
					won = true; at = k + 1;
				}

				for (i = 0, j = 4; i < 5 && j >= 0 && arr[i][j] == -1; i++, j--);
				if (i == 5 && j == -1) {
					won = true; at = k + 1;
				}
			}
		}
		cout << "BINGO after " << at << " numbers announced\n";
	}
}