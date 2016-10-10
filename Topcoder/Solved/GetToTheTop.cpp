#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class GetToTheTop {
public:
	int L, n;
	struct Stair
	{
		int x, y, sw, l;
		bool operator()(const Stair & a, const Stair & b) {
			if (a.y < b.y) return true;
			else if (a.y > b.y) return false;
			else {
				if (a.x < b.x) return true;
				else if (a.x > b.x) return false;
			}
			return false;
		}
	};

	vector<Stair> stairs;
	int dp[10007];
	inline int sqr(int x) { return x * x;}
	bool possible(int i, int j) {
		Stair a = stairs[i], b = stairs[j];
		if ((a.x <= b.x && b.x <= a.x + a.l) || (b.x <= a.x && a.x <= b.x + b.l)) return abs(a.y - b.y) <= L;
		return (sqr(a.x + a.l - b.x) + sqr(a.y - b.y)) <= sqr(L) || (sqr(b.x + b.l - a.x) + sqr(a.y - b.y)) <= sqr(L);
	}


	int compute(int idx) {
		if (dp[idx] != -1) return dp[idx];

		int i, sum = stairs[idx].sw;
		int st, se;
		for (i = idx + 1; i < n; i++) {
			if ((stairs[i].y == stairs[i - 1].y) && possible(i, i - 1)) sum += stairs[i].sw;
			else break;
		}
		se = i - 1;
		for (i = idx - 1 ; i >= 0; i--) {
			if ((stairs[i].y == stairs[i + 1].y) && possible(i, i + 1)) sum += stairs[i].sw;
			else break;
		}
		st = i + 1;
		dp[idx] = 0;
		for (i = 0; i < n; i++) {
			if (i != idx && stairs[i].y >= stairs[idx].y && possible(i, idx)) {
				if (stairs[i].y == stairs[idx].y) dp[idx] = max(dp[idx], compute(i));
				else dp[idx] = max(dp[idx], compute(i) + sum);
			}
		}

		for (i = st; i <= se; i++) {
			if (dp[i] == -1) compute(i);
			dp[i] = max(dp[i], dp[idx]);
		}
		return dp[idx] = max(dp[idx], sum);
	}
	int collectSweets(int K, vector <int> sweets, vector <int> x, vector <int> y, vector <int> stairLength) {
		L = K;
		int len = sweets.size();
		n = len;
		for (int i = 0; i < len; i++) {
			Stair s; s.x = x[i]; s.y = y[i]; s.sw = sweets[i]; s.l = stairLength[i];
			stairs.push_back(s);
		}

		sort(stairs.begin(), stairs.end(), Stair());
		memset(dp, -1, sizeof dp);
		int res = 0;
		for (int i = 0; i < len; i++) {
			if (stairs[i].y <= K) {
				res = max(res, compute(i));
			}
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
		cout << "Testing GetToTheTop (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1471746737;
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
		GetToTheTop _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int K = 2;
			int sweets[] = {1, 2, 3, 4, 3, 5};
			int x[] = {1, 1, 1, 4, 5, 5};
			int y[] = {1, 3, 4, 1, 2, 3};
			int stairLength[] = {2, 1, 1, 2, 1, 1};
			_expected = 13;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		case 1:
		{
			int K = 4;
			int sweets[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4};
			int x[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10};
			int y[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9};
			int stairLength[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2};
			_expected = 47;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		case 2:
		{
			int K = 10;
			int sweets[] = {1, 3, 5, 7};
			int x[] = {1, 6, 2, 8};
			int y[] = {2, 4, 1, 2};
			int stairLength[] = {4, 1, 7, 4};
			_expected = 16;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		case 3:
		{
			int K = 3;
			int sweets[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1};
			int x[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20};
			int y[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11};
			int stairLength[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			_expected = 129;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		case 4:
		{
			int K = 10;
			int sweets[] = {0, 10, 11, 2, 0};
			int x[] = {1, 26, 29, 22, 3};
			int y[] = {1, 83, 88, 22, 5};
			int stairLength[] = {11, 1, 23, 15, 8};
			_expected = 0;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		case 5:
		{
			int K = 5;
			int sweets[] = {2, 0, 5};
			int x[] = {1, 8, 9};
			int y[] = {6, 6, 1};
			int stairLength[] = {3, 6, 3};
			_expected = 7;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		case 6:
		{
			int K = 2;
			int sweets[] = {2, 9, 9, 1, 9, 9, 8};
			int x[] = {10, 8, 6, 6, 8, 7, 3};
			int y[] = {6, 7, 5, 4, 5, 2, 5};
			int stairLength[] = {1, 1, 1, 1, 1, 1, 1};
			_expected = 47;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets + sizeof(sweets) / sizeof(int)), vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)), vector <int>(stairLength, stairLength + sizeof(stairLength) / sizeof(int))); break;
		}
		/*case 7:
		{
			int K = ;
			int sweets[] = ;
			int x[] = ;
			int y[] = ;
			int stairLength[] = ;
			_expected = ;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
		}*/
		/*case 8:
		{
			int K = ;
			int sweets[] = ;
			int x[] = ;
			int y[] = ;
			int stairLength[] = ;
			_expected = ;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
		}*/
		/*case 9:
		{
			int K = ;
			int sweets[] = ;
			int x[] = ;
			int y[] = ;
			int stairLength[] = ;
			_expected = ;
			_received = _obj.collectSweets(K, vector <int>(sweets, sweets+sizeof(sweets)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(stairLength, stairLength+sizeof(stairLength)/sizeof(int))); break;
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
