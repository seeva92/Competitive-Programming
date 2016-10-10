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
	int t;
	cin >> t;
	int a, b, c, i;
	int ladder[101] = {0};
	int snake[101] = {0};
	while (t--) {
		cin >> a >> b >> c;
		int player[a] = {0};
		int roll;
		int s, l;

		memset(ladder, 0, sizeof ladder);
		memset(snake, 0 , sizeof snake);
		fill(player, player + a, 1);

		for (i = 0; i < b; i++) {
			cin >> s >> l;
			if (s < l)
				ladder[s] = l;
			else
				snake[s] = l;
		}
		// for (i = 0; i < a; i++)
		// 	cout << player[i] << " ";
		// cout << '\n';
		bool won = false;
		int j = 0;
		for (i = 0; i < c; i++, j = (j + 1) % a) {
			cin >> roll;
			if (!won) {
				player[j] = player[j] + roll;
				if (player[j] > 100) {
					player[j] = 100;
				} else {
					if (ladder[player[j]] != 0)
						player[j] = ladder[player[j]];
					else if (snake[player[j]] != 0)
						player[j] = snake[player[j]];
				}
				if (player[j] == 100) {
					won = true;
				}
			}

		}

		for (i = 0; i < a; i++)
			cout << "Position of player " << i + 1 << " is " << player[i] << ".\n";
	}
}