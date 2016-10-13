#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int g, w, b, m;
inline bool isvalid(vector<string> &board, char c, int i, int j) {
	if (('A' <= c && c <= 'Z') && ('a' <= board[i][j] && board[i][j] <= 'z')) return true;
	if (('a' <= c && c <= 'z') && ('A' <= board[i][j] && board[i][j] <= 'Z')) return true;
	return false;
}
inline vector<pair<int, int>> possible_moves(vector<string> & board, char c, int i, int j) {
	vector<pair<int, int>> moves;
	if (c == 'Q' || c == 'q' || c == 'R' || c == 'r') {
		for (int jj = j + 1; jj < 4; jj++) {
			if (board[i][jj] == '*') moves.push_back({i, jj});
			else if (isvalid(board, c, i, jj)) { moves.push_back({i, jj}); break;}
			else break;
		}

		for (int jj = j - 1; jj >= 0; jj--) {
			if (board[i][jj] == '*') moves.push_back({i, jj});
			else if (isvalid(board, c, i, jj)) { moves.push_back({i, jj}); break;}
			else break;
		}
		for (int ii = i + 1; ii < 4; ii++) {
			if (board[ii][j] == '*') moves.push_back({ii, j});
			else if (isvalid(board, c, ii, j)) { moves.push_back({ii, j}); break;}
			else break;
		}
		for (int ii = i - 1; ii >= 0; ii--) {
			if (board[ii][j] == '*') moves.push_back({ii, j});
			else if (isvalid(board, c, ii, j)) { moves.push_back({ii, j}); break;}
			else break;
		}
	}
	if ( c == 'Q' || c == 'q' || c == 'B' || c == 'b') {
		for (int ii = i + 1, jj = j + 1; ii < 4 && jj < 4; ii++, jj++) {
			if (board[ii][jj] == '*') moves.push_back({ii, jj});
			else if (isvalid(board, c, ii, jj)) { moves.push_back({ii, jj}); break;}
			else break;
		}
		for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--) {
			if (board[ii][jj] == '*') moves.push_back({ii, jj});
			else if (isvalid(board, c, ii, jj)) { moves.push_back({ii, jj}); break;}
			else break;
		}
		for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < 4; ii--, jj++) {
			if (board[ii][jj] == '*') moves.push_back({ii, jj});
			else if (isvalid(board, c, ii, jj)) { moves.push_back({ii, jj}); break;}
			else break;
		}
		for (int ii = i + 1, jj = j - 1; ii < 4 && jj >= 0; ii++, jj--) {
			if (board[ii][jj] == '*') moves.push_back({ii, jj});
			else if (isvalid(board, c, ii, jj)) { moves.push_back({ii, jj}); break;}
			else break;
		}
	}
	if (c == 'N' || c == 'n') {
		for (int k = 1; k <= 2; k++) {
			if (i + k < 4 && j + (3 - k) < 4) {
				if (board[i + k][j + (3 - k)] == '*' || isvalid(board, c, i + k, j + (3 - k))) moves.push_back({i + k, j + (3 - k)});
			}
			if (i - k >= 0 && j + (3 - k) < 4) {
				if (board[i - k][j + (3 - k)] == '*' || isvalid(board, c, i - k, j + (3 - k))) moves.push_back({i - k, j + (3 - k)});
			}
			if (i - k >= 0 && j - (3 - k) >= 0) {
				if (board[i - k][j - (3 - k)] == '*' || isvalid(board, c, i - k, j - (3 - k))) moves.push_back({i - k, j - (3 - k)});
			}
			if (i + k < 4 && j - (3 - k) >= 0) {
				if (board[i + k][j - (3 - k)] == '*' || isvalid(board, c, i + k, j - (3 - k)))moves.push_back({i + k, j - (3 - k)});
			}
		}
	}
	return moves;
}
inline bool compute(vector<string> board,  int m, bool type, bool kill) {
	if (!type && kill) return true;
	else if (type && kill) return false;
	if (m == 0)return false;
	bool res = !type;
	if (type) {
		for (int i = 0; i < int(board.size()); i++) {
			for (int j = 0; j < int(board[i].size()); j++) {
				if (board[i][j] == '*' || ('a' <= board[i][j] && board[i][j] <= 'z')) continue;
				auto moves = possible_moves(board, board[i][j], i, j);
				for (auto k : moves) {
					char temp = board[k.first][k.second];
					board[k.first][k.second] = board[i][j];
					board[i][j] = '*';
					if (!res) res = res || compute(board, m - 1, !type, temp == 'q');
					board[i][j] = board[k.first][k.second];
					board[k.first][k.second] = temp;

					if (res) return res;
				}
			}
		}
	} else {
		for (int i = 0; i < int(board.size()); i++) {
			for (int j = 0; j < int(board[i].size()); j++) {
				if (board[i][j] == '*' || ('A' <= board[i][j] && board[i][j] <= 'Z')) continue;
				auto moves = possible_moves(board, board[i][j], i, j);
				for (auto k : moves) {
					char temp = board[k.first][k.second];
					board[k.first][k.second] = board[i][j];
					board[i][j] = '*';
					if (res) res = res && compute(board, m - 1, !type, temp == 'Q');
					board[i][j] = board[k.first][k.second];
					board[k.first][k.second] = temp;
					if (!res) return res;
				}
			}
		}
	}
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> g;
	while (g--) {
		cin >> w >> b >> m;
		string s = "****";
		vector<string> board;

		for (int i = 1; i <= 4; i++) board.push_back(s);
		char p, c; int r;
		for (int i = 1; i <= w; i++) {
			cin >> p >> c >> r; //cout << p << " " << c << " " << r << '\n';
			board[4 - r][c - 'A'] = toupper(p);
		}
		for (int i = 1; i <= b; i++) {
			cin >> p >> c >> r; //cout << p << " " << c << " " << r << '\n';
			board[4 - r][c - 'A'] = tolower(p);
		}
		if (compute(board, m, true, false)) cout << "YES\n";
		else cout << "NO\n";

	}
}