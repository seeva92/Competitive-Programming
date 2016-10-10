// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheSumOfLuckyNumbers.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define MAX 10000007
using namespace std;
int dp[MAX + 7];
vector<int>  v;
vector<int> result;
class TheSumOfLuckyNumbers {
public:
	void init()
	{
		v.push_back(4); v.push_back(7);
		for (int i = 0; i < int(v.size()); i++) {
			if (v[i] > 10000007) break;
			v.push_back(v[i] * 10 + 4);
			v.push_back(v[i] * 10 + 7);
		}
	}
	int compute(int n) {
		if (n == 0) return 0;
		if (dp[n] != -1) return dp[n];
		int ans = 1 << 30;
		for (int i = 0; i < int(v.size()); i++) {
			if (v[i] <= n) {
				ans = min(ans, (compute(n - v[i]) + 1));
			}
		}
		dp[n] = ans;
		return ans;
	}
	void path(int n) {
		if (n == 0) return;
		for (int i = 0; i < int(v.size()); i++) {
			if (v[i] <= n) {
				int t = compute(n - v[i]);
				if (t + 1 == dp[n]) {
					result.push_back(v[i]);
					path(n - v[i]);
					return;
				}
			}
		}
	}
	vector <int> sum(int n) {
		init();
		memset(dp, -1, sizeof dp);
		int res = compute(n);
		if (res == (1 << 30)) return vector<int>();
		path(n);
		return result;
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
		cout << "Testing TheSumOfLuckyNumbers (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1472003818;
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
		TheSumOfLuckyNumbers _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int n = 11;
			int __expected[] = {4, 7 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.sum(n); break;
		}
		case 1:
		{
			int n = 12;
			int __expected[] = {4, 4, 4 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.sum(n); break;
		}
		case 2:
		{
			int n = 13;
			int __expected[] = { };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.sum(n); break;
		}
		case 3:
		{
			int n = 100;
			int __expected[] = {4, 4, 4, 44, 44 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.sum(n); break;
		}
		/*case 4:
		{
			int n = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.sum(n); break;
		}*/
		/*case 5:
		{
			int n = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.sum(n); break;
		}*/
		/*case 6:
		{
			int n = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.sum(n); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
