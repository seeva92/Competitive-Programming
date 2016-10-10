#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class IdealString {
public:
	int dp[107][107], L;

	bool can(int length, int left) {
		if (left < 0) return false;
		if (length + left > L) return false;
		if (length == L) return true;
		if (dp[length][left] != -1) return dp[length][left];
		if (can(length + 1, length + left) || can(length + 1, left - 1)) {
			return dp[length][left] = 1;
		}
		return dp[length][left] = 0;

	}
	string construct(int length) {
		memset(dp, -1, sizeof dp);
		this->L = length;
		string res = "";
		queue<char> q;
		int nxt = 0;
		while (int(res.size()) < length) {
			if (can(int(res.size()) + 1, int(q.size()) - 1)) {
				res += q.front(); q.pop(); continue;
			}
			char c = (char)('A' + nxt++);
			for (int i = 0; i < int(res.size()); i++) q.push(c);
			res += c;
			if (!can(int(res.size()), int(q.size()))) return "";
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
		cout << "Testing IdealString (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1471916599;
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
		IdealString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int length = 1;
			_expected = "A";
			_received = _obj.construct(length); break;
		}
		case 1:
		{
			int length = 3;
			_expected = "ABB";
			_received = _obj.construct(length); break;
		}
		case 2:
		{
			int length = 2;
			_expected = "";
			_received = _obj.construct(length); break;
		}
		case 3:
		{
			int length = 6;
			_expected = "ABCBCC";
			_received = _obj.construct(length); break;
		}
		case 4:
		{
			int length = 7;
			_expected = "ABBCCCC";
			_received = _obj.construct(length); break;
		}
		case 5:
		{
			int length = 5;
			_expected = "";
			_received = _obj.construct(length); break;
		}
		/*case 6:
		{
			int length = ;
			_expected = ;
			_received = _obj.construct(length); break;
		}*/
		/*case 7:
		{
			int length = ;
			_expected = ;
			_received = _obj.construct(length); break;
		}*/
		/*case 8:
		{
			int length = ;
			_expected = ;
			_received = _obj.construct(length); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
