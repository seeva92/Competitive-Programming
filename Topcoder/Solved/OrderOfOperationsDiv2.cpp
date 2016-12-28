#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class OrderOfOperationsDiv2
{
public:
	int minTime(vector<string> s) {
		int n = s.size(); int m = s[0].size();
		vector<int> masks(n, 0);
		int rmask = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '1')
					masks[i] |= (1 << j);
			}
			rmask |= masks[i];
		}
		int k;
		vector<int> dist(1 << m, mod);
		dist[0] = 0;
		for (int i = 0; i < (1 << m); i++) {
			for (int j = 0; j < n; j++) {
				int cmask = i | masks[j];
				int smask = cmask - i;
				int nbits = 0;
				for (int k = 0; k < m; k++) {
					if (smask & 1) nbits++;
					smask >>= 1;
				}
				dist[cmask] = min(dist[cmask], dist[i] + (nbits * nbits));
			}
		}
		return dist[rmask];
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
		cout << "Testing OrderOfOperationsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1480696969;
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
		OrderOfOperationsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string s[] = {
				"111",
				"001",
				"010"
			};
			_expected = 3;
			_received = _obj.minTime(vector <string>(s, s + sizeof(s) / sizeof(string))); break;
		}
		case 1:
		{
			string s[] = {
				"11101",
				"00111",
				"10101",
				"00000",
				"11000"
			};
			_expected = 9;
			_received = _obj.minTime(vector <string>(s, s + sizeof(s) / sizeof(string))); break;
		}
		case 2:
		{
			string s[] = {
				"11111111111111111111"
			};
			_expected = 400;
			_received = _obj.minTime(vector <string>(s, s + sizeof(s) / sizeof(string))); break;
		}
		case 3:
		{
			string s[] = {
				"1000",
				"1100",
				"1110"
			};
			_expected = 3;
			_received = _obj.minTime(vector <string>(s, s + sizeof(s) / sizeof(string))); break;
		}
		case 4:
		{
			string s[] = {
				"111",
				"111",
				"110",
				"100"
			};
			_expected = 3;
			_received = _obj.minTime(vector <string>(s, s + sizeof(s) / sizeof(string))); break;
		}
		/*case 5:
		{
			string s[] = ;
			_expected = ;
			_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
		}*/
		/*case 6:
		{
			string s[] = ;
			_expected = ;
			_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
		}*/
		/*case 7:
		{
			string s[] = ;
			_expected = ;
			_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
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
