#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n, m, s;
	char x;
	while (scanf("%d %d %d", &n, &m, &s) != EOF && (n || m || s)) {
		char board[n + 1][m + 1];
		for (int i = 0; i < n ; i++) scanf("%s", &board[i]);

		int ii, jj; char orient; bool flag = false;
		for (int i = 0; i < n && !flag; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == 'N' || board[i][j] == 'S' || board[i][j] == 'L' || board[i][j] == 'O') {
					ii = i; jj = j; orient = board[i][j]; flag = true; break;
				}
		int count = 0;
		for (int i = 0; i < s; i++) {
			scanf(" %c", &x);
			// printf("Before %c %d %d\n", orient, ii, jj);
			switch (x) {
			case 'D':
				switch (orient) {
				case 'N': orient = 'L'; break;
				case 'S': orient = 'O'; break;
				case 'L': orient = 'S'; break;
				case 'O': orient = 'N'; break;
				} break;
			case 'E':
				switch (orient) {
				case 'N': orient = 'O'; break;
				case 'S': orient = 'L'; break;
				case 'L': orient = 'N'; break;
				case 'O': orient = 'S'; break;
				}
				break;
			}
			if (x == 'F') {
				switch (orient) {
				case 'N': if (ii > 0 && (board[ii - 1][jj] != '#')) --ii; break;
				case 'S': if (ii < (n - 1) && (board[ii + 1][jj] != '#')) ++ii; break;
				case 'L': if (jj < (m - 1) && (board[ii][jj + 1] != '#')) ++jj; break;
				case 'O': if (jj > 0 && (board[ii][jj - 1] != '#')) --jj; break;
				}
			}
			if (board[ii][jj] == '*') {
				count++; board[ii][jj] = '.';
			}
			// printf("After %c %d %d\n", orient, ii, jj);
		}
		printf("%d\n", count);
	}
}