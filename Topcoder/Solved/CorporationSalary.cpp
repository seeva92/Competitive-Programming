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
class CorporationSalary {
public:
	vector<string> s;
	long long dp[100];
	long long compute(int i) {
		if (dp[i] != -1) return dp[i];

		long long res = 1LL, curr = 0LL;
		for (int j = 0; j < int(s[i].size()); j++) {
			if (s[i][j] == 'Y')
				curr += compute(j);
		}
		dp[i] = max(res, curr);
		return dp[i];
	}
	long long totalSalary(vector <string> relations) {
		memset(dp, -1, sizeof dp);
		s = relations;
		long long res = 0LL;
		int n = relations.size();
		for (int i = 0; i < n; i++)
			res += compute(i);
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
		cout << "Testing CorporationSalary (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1473575512;
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
		CorporationSalary _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string relations[] = {"N"};
			_expected = 1LL;
			_received = _obj.totalSalary(vector <string>(relations, relations + sizeof(relations) / sizeof(string))); break;
		}
		case 1:
		{
			string relations[] = {"NNYN",
			                      "NNYN",
			                      "NNNN",
			                      "NYYN"
			                     };
			_expected = 5LL;
			_received = _obj.totalSalary(vector <string>(relations, relations + sizeof(relations) / sizeof(string))); break;
		}
		case 2:
		{
			string relations[] = {"NNNNNN",
			                      "YNYNNY",
			                      "YNNNNY",
			                      "NNNNNN",
			                      "YNYNNN",
			                      "YNNYNN"
			                     };
			_expected = 17LL;
			_received = _obj.totalSalary(vector <string>(relations, relations + sizeof(relations) / sizeof(string))); break;
		}
		case 3:
		{
			string relations[] = {"NYNNYN",
			                      "NNNNNN",
			                      "NNNNNN",
			                      "NNYNNN",
			                      "NNNNNN",
			                      "NNNYYN"
			                     };
			_expected = 8LL;
			_received = _obj.totalSalary(vector <string>(relations, relations + sizeof(relations) / sizeof(string))); break;
		}
		case 4:
		{
			string relations[] = {"NNNN",
			                      "NNNN",
			                      "NNNN",
			                      "NNNN"
			                     };
			_expected = 4LL;
			_received = _obj.totalSalary(vector <string>(relations, relations + sizeof(relations) / sizeof(string))); break;
		}
		/*case 5:
		{
			string relations[] = ;
			_expected = LL;
			_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
		}*/
		/*case 6:
		{
			string relations[] = ;
			_expected = LL;
			_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
		}*/
		/*case 7:
		{
			string relations[] = ;
			_expected = LL;
			_received = _obj.totalSalary(vector <string>(relations, relations+sizeof(relations)/sizeof(string))); break;
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
