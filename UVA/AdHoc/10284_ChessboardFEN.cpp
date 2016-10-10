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
void fillQueen(bool attack[][9], string board[], int i, int j) {
	attack[i][j] = true;
	// cout << i << " " << j << '\n';

	for (int k = i + 1; k <= 7 && board[k][j] == '-'; k++)
		attack[k][j] = true;
	for (int k = j + 1; k <= 7 && board[i][k] == '-'; k++)
		attack[i][k] = true;
	for (int k = i - 1; k >= 0 && board[k][j] == '-'; k--)
		attack[k][j] = true;
	for (int k = j - 1; k >= 0 && board[i][k] == '-'; k--)
		attack[i][k] = true;
	int ii = i + 1, jj = j + 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii++][jj++] = true;
	}
	ii = i - 1, jj = j - 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii--][jj--] = true;
	}
	ii = i - 1, jj = j + 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii--][jj++] = true;
	}
	ii = i + 1, jj = j - 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii++][jj--] = true;
	}
}
void fillRook(bool attack[][9], string board[], int i, int j) {
	attack[i][j] = true;
	// cout << i << " " << j << '\n';


	for (int k = i + 1; k <= 7 && board[k][j] == '-'; k++)
		attack[k][j] = true;
	for (int k = j + 1; k <= 7 && board[i][k] == '-'; k++)
		attack[i][k] = true;
	for (int k = i - 1; k >= 0 && board[k][j] == '-'; k--)
		attack[k][j] = true;
	for (int k = j - 1; k >= 0 && board[i][k] == '-'; k--)
		attack[i][k] = true;

}
void fillBishop(bool attack[][9], string board[], int i, int j) {
	attack[i][j] = true;
	int ii = i + 1, jj = j + 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii++][jj++] = true;
	}
	ii = i - 1, jj = j - 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii--][jj--] = true;
	}
	ii = i - 1, jj = j + 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii--][jj++] = true;
	}
	ii = i + 1, jj = j - 1;
	while (ii >= 0 && ii <= 7 && jj >= 0 && jj <= 7 && board[ii][jj] == '-') {
		attack[ii++][jj--] = true;
	}
}
void fillKing(bool attack[][9], string board[], int i, int j) {
	attack[i][j] = true;
	// cout << i << " " << j << '\n';
	if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == '-')
		attack[i - 1][j - 1] = true;
	if (i - 1 >= 0 && board[i - 1][j] == '-')
		attack[i - 1][j] = true;
	if (i - 1 >= 0 && j + 1 <= 7 && board[i - 1][j + 1] == '-')
		attack[i - 1][j + 1] = true;
	if (j - 1 >= 0 && board[i][j - 1] == '-')
		attack[i][j - 1] = true;
	if (j + 1 <= 7 && board[i][j + 1] == '-')
		attack[i][j + 1] = true;
	if (i + 1 <= 7 && j - 1 >= 0 && board[i + 1][j - 1] == '-')
		attack[i + 1][j - 1] = true;
	if (i + 1 <= 7 && board[i + 1][j] == '-')
		attack[i + 1][j] = true;
	if (i + 1 <= 7 && j + 1 <= 7 && board[i + 1][j + 1] == '-')
		attack[i + 1][j + 1] = true;
}
void fillKnight(bool attack[][9], string board[], int i, int j) {
	attack[i][j] = true;
	// cout << i << " " << j << '\n';

	if (i + 1 <= 7) {
		if (j + 2 <= 7 && board[i + 1][j + 2] == '-')
			attack[i + 1][j + 2] = true;
		if (j - 2 >= 0 && board[i + 1][j - 2] == '-')
			attack[i + 1][j - 2] = true;
	}
	if (i - 1 >= 0) {
		if (j + 2 <= 7 && board[i - 1][j + 2] == '-')
			attack[i - 1][j + 2] = true;
		if (j - 2 >= 0 && board[i - 1][j - 2] == '-')
			attack[i - 1][j - 2] = true;
	}
	if (j + 1 <= 7) {
		if (i + 2 <= 7 && board[i + 2][j + 1] == '-')
			attack[i + 2][j + 1] = true;
		if (i - 2 >= 0 && board[i - 2][j + 1] == '-')
			attack[i - 2][j + 1] = true;
	}
	if (j - 1 >= 0) {
		if (i + 2 <= 7 && board[i + 2][j - 1] == '-')
			attack[i + 2][j - 1] = true;
		if (i - 2 >= 0 && board[i - 2][j - 1] == '-')
			attack[i - 2][j - 1] = true;
	}
}
void fillPawn(bool attack[][9], string board[], bool flag, int i, int j) {
	attack[i][j] = true;

	if (flag) {
		if (i + 1 <= 7) {
			if (j + 1 <= 7 && board[i + 1][j + 1] == '-')
				attack[i + 1][j + 1] = true;
			if (j - 1 >= 0 && board[i + 1][j - 1] == '-')
				attack[i + 1][j - 1] = true;
		}
	} else {
		if (i - 1 >= 0) {
			if (j + 1 <= 7 && board[i - 1][j + 1] == '-')
				attack[i - 1][j + 1] = true;
			if (j - 1 >= 0 && board[i - 1][j - 1] == '-')
				attack[i - 1][j - 1] = true;
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	string str;

	while (getline(cin, str)) {
		string board[9];
		bool attack[9][9] = {false};

		int len = (int)str.size();
		int j = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] >= '0' && str[i] <= '8') {
				for (int l = 0; l < (str[i] - '0'); l++)
					board[j].push_back('-');
			} else if (str[i] == '/') {
				j++;
			} else {
				board[j].push_back(str[i]);
			}
		}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				switch (board[i][j]) {
				case 'k':
				case 'K':
					fillKing(attack, board, i, j);
					break;
				case 'q':
				case 'Q':
					fillQueen(attack, board, i, j);
					break;
				case 'r':
				case 'R':
					fillRook(attack, board, i, j);
					break;
				case 'n':
				case 'N':
					fillKnight(attack, board, i, j);
					break;
				case 'b':
				case 'B':
					fillBishop(attack, board, i, j);
					break;
				case 'p':
					fillPawn(attack, board, true, i, j); break;
				case 'P':
					fillPawn(attack, board, false, i, j); break;
				}
				// for (int k = 0; k <= 7; k++)
				// 	cout << board[k] << '\n';
				// cout << board[i][j] << endl;
				// for (int k = 0; k < 8; k++, cout << '\n')
				// for (int l = 0; l < 8; l++)
				// cout << attack[k][l] << " ";
			}

		// for (int i = 0; i < 8; i++)
		// 	cout << board[i] << '\n';
		// for (int k = 0; k < 8; k++, cout << '\n')
		// 	for (int l = 0; l < 8; l++)
		// 		cout << attack[k][l] << " ";
		int count = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (!attack[i][j])
					count++;
		cout << count << "\n";
	}
}