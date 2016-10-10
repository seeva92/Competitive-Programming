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
class Stick {
public:
	int X;
	int compute(int x, int total) {
		if (total == X) return 0;
		if (total + x <= X)
			return 1 + compute(x / 2, total + x);
		return compute(x / 2, total);

	}
	int pieces(int x) {
		X = x;
		return compute(64, 0);
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
		cout << "Testing Stick (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1475165460;
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
		Stick _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int x = 32;
			_expected = 1;
			_received = _obj.pieces(x); break;
		}
		case 1:
		{
			int x = 48;
			_expected = 2;
			_received = _obj.pieces(x); break;
		}
		case 2:
		{
			int x = 23;
			_expected = 4;
			_received = _obj.pieces(x); break;
		}
		/*case 3:
		{
			int x = ;
			_expected = ;
			_received = _obj.pieces(x); break;
		}*/
		/*case 4:
		{
			int x = ;
			_expected = ;
			_received = _obj.pieces(x); break;
		}*/
		/*case 5:
		{
			int x = ;
			_expected = ;
			_received = _obj.pieces(x); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
