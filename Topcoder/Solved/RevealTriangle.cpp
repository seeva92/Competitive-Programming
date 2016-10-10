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
class RevealTriangle {
public:
	vector <string> calcTriangle(vector <string> s) {
		int len = s.size();
		int i, j, k;
		for (i = len - 2; i >= 0; i--) {
			int tlen = (int)s[i].size();
			for (j = 0; j < tlen && s[i][j] == '?'; j++);
			for (k = j; (k < tlen) && ((k + 1) < tlen); k++) {
				int p = s[i][k] - '0', q = s[i + 1][k] - '0';
				if (p <= q) s[i][k + 1] = (char)((q - p) + '0');
				else s[i][k + 1] = (char)((10 + q - p) + '0');
			}
			for (k = j; k >= 0 && k - 1 >= 0; k--) {
				int p = s[i][k] - '0', q = s[i + 1][k - 1] - '0';
				if (p <= q) s[i][k - 1] = (char)((q - p) + '0');
				else s[i][k - 1] = (char)((10 + q - p) + '0');
			}
		}
		return s;
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
		cout << "Testing RevealTriangle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1471741951;
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
		RevealTriangle _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string questionMarkTriangle[] = {"4??",
			                                 "?2",
			                                 "1"
			                                };
			string __expected[] = {"457", "92", "1" };
			_expected = vector <string>(__expected, __expected + sizeof(__expected) / sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + sizeof(questionMarkTriangle) / sizeof(string))); break;
		}
		case 1:
		{
			string questionMarkTriangle[] = {"1"};
			string __expected[] = {"1" };
			_expected = vector <string>(__expected, __expected + sizeof(__expected) / sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + sizeof(questionMarkTriangle) / sizeof(string))); break;
		}
		case 2:
		{
			string questionMarkTriangle[] = {"???2", "??2", "?2", "2"};
			string __expected[] = {"0002", "002", "02", "2" };
			_expected = vector <string>(__expected, __expected + sizeof(__expected) / sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + sizeof(questionMarkTriangle) / sizeof(string))); break;
		}
		case 3:
		{
			string questionMarkTriangle[] = {"??5?", "??9", "?4", "6"};
			string __expected[] = {"7054", "759", "24", "6" };
			_expected = vector <string>(__expected, __expected + sizeof(__expected) / sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle + sizeof(questionMarkTriangle) / sizeof(string))); break;
		}
		/*case 4:
		{
			string questionMarkTriangle[] = ;
			string __expected[] = ;
			_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
		}*/
		/*case 5:
		{
			string questionMarkTriangle[] = ;
			string __expected[] = ;
			_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
		}*/
		/*case 6:
		{
			string questionMarkTriangle[] = ;
			string __expected[] = ;
			_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
			_received = _obj.calcTriangle(vector <string>(questionMarkTriangle, questionMarkTriangle+sizeof(questionMarkTriangle)/sizeof(string))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
