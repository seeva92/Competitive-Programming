#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int dp[67][67][67];
class MutaliskEasy
{


public:

	int compute(int a, int b, int c) {
		if ((a == 0) && (b == 0) && (c == 0)) return dp[a][b][c] = 0;
		if (dp[a][b][c] != -1) return dp[a][b][c];

		int & res = dp[a][b][c];
		res = INT_MAX;

		vector<int> v = {a, b, c};
		sort(v.begin(), v.end());

		do {
			int aa = max(0, v[0] - 9);
			int bb = max(0, v[1] - 3);
			int cc = max(0, v[2] - 1);
			res = min(res, 1 + compute(aa, bb, cc));
			// cout << res << '\n';
		} while (next_permutation(v.begin(), v.end()));
		return res;
	}
	int minimalAttacks(vector<int> x) {
		memset(dp, -1, sizeof dp);
		while (x.size() < 3) x.push_back(0);
		int a = 0, b = 0, c = 0;
		a = x[0];
		b = x[1];
		c = x[2];
		// cout << a << " " << b << " " << c;
		return compute(a, b, c);
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
		cout << "Testing MutaliskEasy (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1482892268;
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
		MutaliskEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int x[] = {12, 10, 4};
			_expected = 2;
			_received = _obj.minimalAttacks(vector <int>(x, x + sizeof(x) / sizeof(int))); break;
		}
		case 1:
		{
			int x[] = {54, 18, 6};
			_expected = 6;
			_received = _obj.minimalAttacks(vector <int>(x, x + sizeof(x) / sizeof(int))); break;
		}
		case 2:
		{
			int x[] = {55, 60, 53};
			_expected = 13;
			_received = _obj.minimalAttacks(vector <int>(x, x + sizeof(x) / sizeof(int))); break;
		}
		case 3:
		{
			int x[] = {1, 1, 1};
			_expected = 1;
			_received = _obj.minimalAttacks(vector <int>(x, x + sizeof(x) / sizeof(int))); break;
		}
		case 4:
		{
			int x[] = {60, 40};
			_expected = 9;
			_received = _obj.minimalAttacks(vector <int>(x, x + sizeof(x) / sizeof(int))); break;
		}
		case 5:
		{
			int x[] = {60};
			_expected = 7;
			_received = _obj.minimalAttacks(vector <int>(x, x + sizeof(x) / sizeof(int))); break;
		}
		/*case 6:
		{
			int x[] = ;
			_expected = ;
			_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			int x[] = ;
			_expected = ;
			_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
		}*/
		/*case 8:
		{
			int x[] = ;
			_expected = ;
			_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
