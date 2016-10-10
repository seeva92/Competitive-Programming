#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class FactoVisors {
public:
	map<int, int> arr;

	int getNum(vector <int> divisors, vector <int> multiples) {
		long long len = sqrt(1e9);
		set<int> fac;
		for (auto i : multiples) {
			if (i == 1) {
				arr[1]++;
				fac.insert(i);
			}
			else if (i <= 2) {
				arr[1]++; arr[2]++;
				fac.insert(1); fac.insert(2);
			}
			else {
				int s = sqrt(i);
				for (int j = 2; j <= s; j++) {
					if ((i % j) == 0) {
						arr[j]++; fac.insert(j);
						if ((i / j) != j) {
							arr[(i / j)]++;
							fac.insert((i / j));
						}
					}
				}
				arr[1]++; arr[i]++; fac.insert(1); fac.insert(i);
			}
		}

		for (auto j : divisors) {
			for (auto k : fac) {
				if (k >= j && (k % j == 0)) {
					arr[k]++;
				}
			}
		}

		int total = int(divisors.size()) + int(multiples.size());
		int res = 0;
		for (auto i : arr) {
			if (i.second == total) res++;
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
		cout << "Testing FactoVisors (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1472224428;
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
		FactoVisors _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int divisors[] = {1};
			int multiples[] = {100};
			_expected = 9;
			_received = _obj.getNum(vector <int>(divisors, divisors + sizeof(divisors) / sizeof(int)), vector <int>(multiples, multiples + sizeof(multiples) / sizeof(int))); break;
		}
		case 1:
		{
			int divisors[] = {6, 9};
			int multiples[] = {18};
			_expected = 1;
			_received = _obj.getNum(vector <int>(divisors, divisors + sizeof(divisors) / sizeof(int)), vector <int>(multiples, multiples + sizeof(multiples) / sizeof(int))); break;
		}
		case 2:
		{
			int divisors[] = {6, 9};
			int multiples[] = {96, 180};
			_expected = 0;
			_received = _obj.getNum(vector <int>(divisors, divisors + sizeof(divisors) / sizeof(int)), vector <int>(multiples, multiples + sizeof(multiples) / sizeof(int))); break;
		}
		case 3:
		{
			int divisors[] = {2, 4};
			int multiples[] = {256};
			_expected = 7;
			_received = _obj.getNum(vector <int>(divisors, divisors + sizeof(divisors) / sizeof(int)), vector <int>(multiples, multiples + sizeof(multiples) / sizeof(int))); break;
		}
		case 4:
		{
			int divisors[] = {1000, 10000, 100000};
			int multiples[] = {1000000000};
			_expected = 25;
			_received = _obj.getNum(vector <int>(divisors, divisors + sizeof(divisors) / sizeof(int)), vector <int>(multiples, multiples + sizeof(multiples) / sizeof(int))); break;
		}
		/*case 5:
		{
			int divisors[] = ;
			int multiples[] = ;
			_expected = ;
			_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
		}*/
		/*case 6:
		{
			int divisors[] = ;
			int multiples[] = ;
			_expected = ;
			_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			int divisors[] = ;
			int multiples[] = ;
			_expected = ;
			_received = _obj.getNum(vector <int>(divisors, divisors+sizeof(divisors)/sizeof(int)), vector <int>(multiples, multiples+sizeof(multiples)/sizeof(int))); break;
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
