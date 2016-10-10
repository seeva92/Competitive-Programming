#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
int arr[] = { -1, 0, 1};
class HappyCells {
public:
	int N, M;

	vector<string> g;
	bool onehappy(int i, int j) {
		if (g[i][j] == '.') {
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++) {
					if ((arr[k] == 0) && (arr[l] == 0)) continue;
					if ((0 <= (i + arr[k])) && ((i + arr[k]) < N) && (0 <= (j + arr[l])) &&  ((j + arr[l]) < M)) {
						if (g[i + arr[k]][j + arr[l]] != 'X') return false;
					}
				}
			return true;
		}
		return false;
	}
	bool twohappy(int i, int j) {
		if (g[i][j] == '.') {
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++) {
					if ((arr[k] == 0) && (arr[l] == 0)) continue;
					if ((arr[k] != 0) && (arr[l] != 0)) continue;
					if ((0 <= (i + arr[k])) && ((i + arr[k]) < N) && (0 <= (j + arr[l])) &&  ((j + arr[l]) < M)) {


						if (g[i + arr[k]][j + arr[l]] != 'X') {
							// cout << "oh god" << (i + arr[k]) << " " << (j + arr[l]) << " " << arr[k] << " " << arr[l] << '\n';

							return false;
						}
					}
				}
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++) {
					if (arr[k] == 0 || arr[l] == 0) continue;
					if ((0 <= (i + arr[k])) && ((i + arr[k]) < N) && (0 <= (j + arr[l])) &&  ((j + arr[l]) < M)) {
						if (g[i + arr[k]][j + arr[l]] == '.') return true;
					}
				}
		}
		return false;
	}

	bool threehappy(int i, int j) {
		if (g[i][j] == '.') {
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++) {
					if (arr[k] == 0 || arr[l] == 0) continue;
					if ((0 <= (i + arr[k])) && ((i + arr[k]) < N) && (0 <= (j + arr[l])) &&  ((j + arr[l]) < M)) {
						if (g[i + arr[k]][j + arr[l]] != 'X') return false;
					}
				}
			for (int k = 0; k < 3; k++)
				for (int l = 0; l < 3; l++) {
					if ((arr[k] == 0) && (arr[l] == 0)) continue;
					if (arr[k] != 0 && arr[l] != 0) continue;
					if ((0 <= (i + arr[k])) && ((i + arr[k]) < N) && (0 <= (j + arr[l])) &&  ((j + arr[l]) < M)) {
						if (g[i + arr[k]][j + arr[l]] == '.') return true;
					}
				}

		}
		return false;
	}
	vector <int> getHappy(vector <string> grid) {
		int len = grid.size();
		int one, two, three;
		g = grid;
		one = two = three = 0;
		N = len;
		for (int i = 0; i < len; i++) {
			int slen = grid[i].size();
			M = slen;
			for (int j = 0; j < slen; j++) {
				if (onehappy(i, j)) one++;
				else if (twohappy(i, j)) two++;
				else if (threehappy(i, j)) three++;
			}
		}

		std::vector<int> v;
		v.push_back(one); v.push_back(two); v.push_back(three);
		return v;
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
		cout << "Testing HappyCells (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1472221284;
		double PT = T / 60.0, TT = 75.0;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HappyCells _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string grid[] = {
				"XXX",
				"X.X",
				"XXX"
			};
			int __expected[] = {1, 0, 0 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid + sizeof(grid) / sizeof(string))); break;
		}
		case 1:
		{
			string grid[] = {"."};
			int __expected[] = {1, 0, 0 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid + sizeof(grid) / sizeof(string))); break;
		}
		case 2:
		{
			string grid[] = {
				"XXXXXX",
				"X.XXXX",
				"XXX.XX",
				"X..XXX",
				"XXXXXX"
			};
			int __expected[] = {1, 1, 1 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid + sizeof(grid) / sizeof(string))); break;
		}
		case 3:
		{
			string grid[] = {"..."};
			int __expected[] = {0, 0, 3 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid + sizeof(grid) / sizeof(string))); break;
		}
		/*case 4:
		{
			string grid[] = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
		}*/
		/*case 5:
		{
			string grid[] = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
		}*/
		/*case 6:
		{
			string grid[] = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.getHappy(vector <string>(grid, grid+sizeof(grid)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
