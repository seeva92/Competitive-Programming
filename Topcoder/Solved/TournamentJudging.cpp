#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class TournamentJudging {
public:
	int getPoints(vector <int> rawScores, vector <int> conversionFactor) {
		int len = rawScores.size();
		int res = 0;
		for (int i = 0; i < len; i++) {
			double temp = rawScores[i]; temp /= conversionFactor[i];
			temp = round(temp);
			res += (int)temp;
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
		cout << "Testing TournamentJudging (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1474508902;
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
		TournamentJudging _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int rawScores[] = {10, 20, 30};
			int conversionFactor[] = {10, 10, 5};
			_expected = 9;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores + sizeof(rawScores) / sizeof(int)), vector <int>(conversionFactor, conversionFactor + sizeof(conversionFactor) / sizeof(int))); break;
		}
		case 1:
		{
			int rawScores[] = {8, 16, 32};
			int conversionFactor[] = {10, 10, 5};
			_expected = 9;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores + sizeof(rawScores) / sizeof(int)), vector <int>(conversionFactor, conversionFactor + sizeof(conversionFactor) / sizeof(int))); break;
		}
		case 2:
		{
			int rawScores[] = {60, 59};
			int conversionFactor[] = {24, 24};
			_expected = 5;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores + sizeof(rawScores) / sizeof(int)), vector <int>(conversionFactor, conversionFactor + sizeof(conversionFactor) / sizeof(int))); break;
		}
		case 3:
		{
			int rawScores[] = {47, 42, 37, 30, 27, 21, 18};
			int conversionFactor[] = {1, 2, 3, 4, 5, 6, 7};
			_expected = 100;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores + sizeof(rawScores) / sizeof(int)), vector <int>(conversionFactor, conversionFactor + sizeof(conversionFactor) / sizeof(int))); break;
		}
		case 4:
		{
			int rawScores[] = {0, 1000000, 5000, 1000000};
			int conversionFactor[] = {1, 2, 1000000, 4};
			_expected = 750000;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores + sizeof(rawScores) / sizeof(int)), vector <int>(conversionFactor, conversionFactor + sizeof(conversionFactor) / sizeof(int))); break;
		}
		/*case 5:
		{
			int rawScores[] = ;
			int conversionFactor[] = ;
			_expected = ;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores+sizeof(rawScores)/sizeof(int)), vector <int>(conversionFactor, conversionFactor+sizeof(conversionFactor)/sizeof(int))); break;
		}*/
		/*case 6:
		{
			int rawScores[] = ;
			int conversionFactor[] = ;
			_expected = ;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores+sizeof(rawScores)/sizeof(int)), vector <int>(conversionFactor, conversionFactor+sizeof(conversionFactor)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			int rawScores[] = ;
			int conversionFactor[] = ;
			_expected = ;
			_received = _obj.getPoints(vector <int>(rawScores, rawScores+sizeof(rawScores)/sizeof(int)), vector <int>(conversionFactor, conversionFactor+sizeof(conversionFactor)/sizeof(int))); break;
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
