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
class OlympicCandles {
public:
	int numberOfNights(vector <int> arr) {
		int len = arr.size();
		int res = 0;
		sort(arr.begin(), arr.end(), greater<int>());
		for (int i = 0;; i++) {
			int c = 0;
			for (int j = 0; j < len && c < (i + 1); j++) {
				if (arr[j] != 0) {
					arr[j]--; c++;
				}
			}
			sort(arr.begin(), arr.end(), greater<int>());
			if (c == (i + 1)) res++;
			else break;
		}
		return res;
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
		cout << "Testing OlympicCandles (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1474509285;
		double PT = T / 60.0, TT = 75.0;
		cout.setf(ios::fixed, ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
		cout << "Score : " << 500.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OlympicCandles _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int candles[] = {2, 2, 2};
			_expected = 3;
			_received = _obj.numberOfNights(vector <int>(candles, candles + sizeof(candles) / sizeof(int))); break;
		}
		case 1:
		{
			int candles[] = {2, 2, 2, 4};
			_expected = 4;
			_received = _obj.numberOfNights(vector <int>(candles, candles + sizeof(candles) / sizeof(int))); break;
		}
		case 2:
		{
			int candles[] = {5, 2, 2, 1};
			_expected = 3;
			_received = _obj.numberOfNights(vector <int>(candles, candles + sizeof(candles) / sizeof(int))); break;
		}
		case 3:
		{
			int candles[] = {1, 2, 3, 4, 5, 6};
			_expected = 6;
			_received = _obj.numberOfNights(vector <int>(candles, candles + sizeof(candles) / sizeof(int))); break;
		}
		case 4:
		{
			int candles[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			_expected = 4;
			_received = _obj.numberOfNights(vector <int>(candles, candles + sizeof(candles) / sizeof(int))); break;
		}
		/*case 5:
		{
			int candles[] = ;
			_expected = ;
			_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
		}*/
		/*case 6:
		{
			int candles[] = ;
			_expected = ;
			_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			int candles[] = ;
			_expected = ;
			_received = _obj.numberOfNights(vector <int>(candles, candles+sizeof(candles)/sizeof(int))); break;
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
