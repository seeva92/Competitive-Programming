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
class TestTaking {
public:
	int findMax(int questions, int guessed, int actual) {
		if (actual >= guessed) {
			return guessed + (questions - actual);
		}
		return actual + (questions - guessed);
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
		cout << "Testing TestTaking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1481523307;
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
		TestTaking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int questions = 3;
			int guessed = 1;
			int actual = 2;
			_expected = 2;
			_received = _obj.findMax(questions, guessed, actual); break;
		}
		case 1:
		{
			int questions = 3;
			int guessed = 2;
			int actual = 1;
			_expected = 2;
			_received = _obj.findMax(questions, guessed, actual); break;
		}
		case 2:
		{
			int questions = 5;
			int guessed = 5;
			int actual = 0;
			_expected = 0;
			_received = _obj.findMax(questions, guessed, actual); break;
		}
		case 3:
		{
			int questions = 10;
			int guessed = 8;
			int actual = 8;
			_expected = 10;
			_received = _obj.findMax(questions, guessed, actual); break;
		}
		case 4:
		{
			int questions = 7;
			int guessed = 0;
			int actual = 2;
			_expected = 5;
			_received = _obj.findMax(questions, guessed, actual); break;
		}
		/*case 5:
		{
			int questions = ;
			int guessed = ;
			int actual = ;
			_expected = ;
			_received = _obj.findMax(questions, guessed, actual); break;
		}*/
		/*case 6:
		{
			int questions = ;
			int guessed = ;
			int actual = ;
			_expected = ;
			_received = _obj.findMax(questions, guessed, actual); break;
		}*/
		/*case 7:
		{
			int questions = ;
			int guessed = ;
			int actual = ;
			_expected = ;
			_received = _obj.findMax(questions, guessed, actual); break;
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
