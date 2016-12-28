#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int dp[21 * MAX];
class NumbersChallenge
{
	vector<int> arr;
public:
	// int MinNumber(vector<int> S) {
	// 	int len = S.size();
	// 	set<ll> st;
	// 	// cout << len << '\n';
	// 	int blen = (1 << len);
	// 	for (int i = 0; i < blen; i++) {
	// 		ll sum = 0;
	// 		for (int j = 0; j < len; j++) {
	// 			if (i & (1 << j)) {
	// 				sum += S[j];
	// 			}
	// 		}
	// 		st.insert(sum);
	// 	}
	// 	int prev = 0;
	// 	for (auto i : st) {
	// 		if (i - prev > 1) {
	// 			break;
	// 		}
	// 		prev = i;
	// 	}
	// 	return prev + 1;
	// }

	int MinNumber(std::vector<int> S) {
		int len = S.size();
		int blen = 21 * MAX;
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < len; i++)
			for (int j = blen; j >= S[i]; j--) {
				dp[j] |= dp[j - S[i]];
			}
		for (int i = 1; i < blen; i++) {
			if (!dp[i]) return i;
		}
		return blen;
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
		cout << "Testing NumbersChallenge (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1482906913;
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
		NumbersChallenge _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int S[] = {5, 1, 2};
			_expected = 4;
			_received = _obj.MinNumber(vector <int>(S, S + sizeof(S) / sizeof(int))); break;
		}
		case 1:
		{
			int S[] = {2, 1, 4};
			_expected = 8;
			_received = _obj.MinNumber(vector <int>(S, S + sizeof(S) / sizeof(int))); break;
		}
		case 2:
		{
			int S[] = {2, 1, 2, 7};
			_expected = 6;
			_received = _obj.MinNumber(vector <int>(S, S + sizeof(S) / sizeof(int))); break;
		}
		case 3:
		{
			int S[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
			_expected = 1092;
			_received = _obj.MinNumber(vector <int>(S, S + sizeof(S) / sizeof(int))); break;
		}
		case 4:
		{
			int S[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
			_expected = 56523;
			_received = _obj.MinNumber(vector <int>(S, S + sizeof(S) / sizeof(int))); break;
		}
		/*case 5:
		{
			int S[] = ;
			_expected = ;
			_received = _obj.MinNumber(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
		}*/
		/*case 6:
		{
			int S[] = ;
			_expected = ;
			_received = _obj.MinNumber(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			int S[] = ;
			_expected = ;
			_received = _obj.MinNumber(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
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
