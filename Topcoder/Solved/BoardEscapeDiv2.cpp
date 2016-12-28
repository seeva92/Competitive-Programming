#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int x[] = { -1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
int dp[51][51][101];


int *p;
class BoardEscapeDiv2
{
	int r, c;
	int er, ec;
	vector<string> s;
public:
	//My approach
	// bool isAliceWinning(int i, int j, int k, bool alice) {
	// 	if (k == 0 || s[i][j] == 'E') return (dp[i][j][k][alice] = !alice);

	// 	if (dp[i][j][k][alice] != -1) return dp[i][j][k][alice];
	// 	bool flag = false;
	// 	bool res = alice ? false : true;
	// 	for (int l = 0; l < 4; l++) {
	// 		if (((0 <= i + x[l] && i + x[l] < r) &&
	// 		        (0 <= j + y[l] && j + y[l] < c)) &&
	// 		        (s[i + x[l]][j + y[l]] != '#')) {
	// 			flag = true;
	// 			if (alice) {
	// 				if (!res) res =  isAliceWinning(i + x[l], j + y[l], k - 1, !alice);
	// 			} else {
	// 				if (res) res = isAliceWinning(i + x[l], j + y[l], k - 1, !alice);
	// 			}
	// 		}
	// 	}
	// 	if (!flag) return (dp[i][j][k][alice] = !alice);
	// 	return (dp[i][j][k][alice] = res);
	// }
	//Editorial State Reduction
	bool isAliceWinning(int i, int j, int k) {
		int & res = dp[i][j][k];
		if (res == -1) {
			if (k == 0 || s[i][j] == 'E') return (res = 0);
			res = 0;
			for (int l = 0; l < 4; l++) {
				if (((0 <= i + x[l] && i + x[l] < r) &&
				        (0 <= j + y[l] && j + y[l] < c)) &&
				        (s[i + x[l]][j + y[l]] != '#')) {
					if (isAliceWinning(i + x[l], j + y[l], k - 1) == false) res = 1;
				}
			}
		}
		return res;
	}
	string findWinner(vector<string> st, int k) {
		this->s = st;
		r = s.size(); c = s[0].size();
		memset(dp, -1, sizeof dp);
		int ii, jj;
		for (int i = 0; i < r; i++) {
			size_t idx = s[i].find('T');
			if (idx != string::npos) {
				ii = i; jj = idx; break;
			}
		}
		// cout << ii << " " << jj << '\n';
		bool flag = isAliceWinning(ii, jj, k);
		if (flag) return "Alice";
		return "Bob";
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		cout << "Testing BoardEscapeDiv2 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1480670821;
		double PT = T / 60.0, TT = 75.0;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score : " << 550.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BoardEscapeDiv2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string s[] = {"T.#",
			              "#.E"
			             };
			int k = 3;
			_expected = "Alice";
			_received = _obj.findWinner(vector <string>(s, s + sizeof(s) / sizeof(string)), k); break;
		}
		case 1:
		{
			string s[] = {"E#E",
			              "#T#",
			              "E#E"
			             };
			int k = 99;
			_expected = "Bob";
			_received = _obj.findWinner(vector <string>(s, s + sizeof(s) / sizeof(string)), k); break;
		}
		case 2:
		{
			string s[] = {"#E...",
			              "#...E",
			              "E.T#.",
			              "..#.."
			             };
			int k = 13;
			_expected = "Alice";
			_received = _obj.findWinner(vector <string>(s, s + sizeof(s) / sizeof(string)), k); break;
		}
		case 3:
		{
			string s[] = {"TE"};
			int k = 50;
			_expected = "Alice";
			_received = _obj.findWinner(vector <string>(s, s + sizeof(s) / sizeof(string)), k); break;
		}
		case 4:
		{
			string s[] = {".T."};
			int k = 1;
			_expected = "Alice";
			_received = _obj.findWinner(vector <string>(s, s + sizeof(s) / sizeof(string)), k); break;
		}
		case 5:
		{
			string s[] = {"..........................",
			              "......EEE..EEE..E...E.....",
			              ".....E.....E..E.EE.EE.....",
			              "......EEE..EEE..E.E.E.....",
			              ".........E.E.E..E...E.....",
			              "......EEE..E..E.E...E.....",
			              "..........................",
			              "...E#E#E#E#E#E#E#E#E#E#...",
			              "..........................",
			              "......EEE..EEE...EEE......",
			              ".....E........E.E.........",
			              "......EEE.....E..EEE......",
			              ".....E...E...E..E...E.....",
			              "......EEE....E...EEE......",
			              "..........................",
			              "...#E#E#E#E#E#E#E#E#E#E...",
			              "..........................",
			              "....EE...E...E..E.EEE.E...",
			              "...E.....E...E..E.E...E...",
			              "...E.EE..E...EEEE.EE..E...",
			              "...E..E..E...E..E.E.......",
			              "....EE...EEE.E..E.E...E...",
			              "T........................."
			             };
			int k = 100;
			_expected = "Bob";
			_received = _obj.findWinner(vector <string>(s, s + sizeof(s) / sizeof(string)), k); break;
		}
		/*case 6:
		{
			string s[] = ;
			int k = ;
			_expected = ;
			_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
		}*/
		/*case 7:
		{
			string s[] = ;
			int k = ;
			_expected = ;
			_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
		}*/
		/*case 8:
		{
			string s[] = ;
			int k = ;
			_expected = ;
			_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
		}*/
		default: return 0;
		}
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock() - _start) / CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
