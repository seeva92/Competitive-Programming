#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
double dp[1007][4007];
class MarblesInABag {
public:
	double compute(int r, int b) {
		if (b <= 0 || r > b || r > 1000) return 0.0;
		if (r == 0) return 1.0;
		double &ret = dp[r][b];
		// cout << ret << '\n';
		if (ret == ret) return ret;
		double x = r, y = b;
		return ret = (x / (x + y) * compute(r - 1, b - 1)) + ((y / (x + y)) * compute(r, b - 2));
	}
	double getProbability(int redCount, int blueCount) {
		memset(dp, -1, sizeof dp);
		int x = 0x7E;
		printf("%d", x);
		return compute(redCount, blueCount);
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
		cout << "Testing MarblesInABag (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1474559112;
		double PT = T / 60.0, TT = 75.0;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score : " << 1000.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MarblesInABag _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int redCount = 1;
			int blueCount = 2;
			_expected = 0.3333333333333333;
			_received = _obj.getProbability(redCount, blueCount); break;
		}
		case 1:
		{
			int redCount = 2;
			int blueCount = 3;
			_expected = 0.13333333333333333;
			_received = _obj.getProbability(redCount, blueCount); break;
		}
		case 2:
		{
			int redCount = 2;
			int blueCount = 5;
			_expected = 0.22857142857142856;
			_received = _obj.getProbability(redCount, blueCount); break;
		}
		case 3:
		{
			int redCount = 11;
			int blueCount = 6;
			_expected = 0.0;
			_received = _obj.getProbability(redCount, blueCount); break;
		}
		case 4:
		{
			int redCount = 4;
			int blueCount = 11;
			_expected = 0.12183372183372182;
			_received = _obj.getProbability(redCount, blueCount); break;
		}
		/*case 5:
		{
			int redCount = ;
			int blueCount = ;
			_expected = ;
			_received = _obj.getProbability(redCount, blueCount); break;
		}*/
		/*case 6:
		{
			int redCount = ;
			int blueCount = ;
			_expected = ;
			_received = _obj.getProbability(redCount, blueCount); break;
		}*/
		/*case 7:
		{
			int redCount = ;
			int blueCount = ;
			_expected = ;
			_received = _obj.getProbability(redCount, blueCount); break;
		}*/
		default: return 0;
		}
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock() - _start) / CLOCKS_PER_SEC;
		if (abs(_expected - _received) < 1e-9 || (_received > min(_expected * (1.0 - 1e-9), _expected * (1.0 + 1e-9)) && _received < max(_expected * (1.0 - 1e-9), _expected * (1.0 + 1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
