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
class SRMCards {
public:
	int len;
	vector<int> check;
	map<vector<int>, int> mp;
	int compute(vector<int> arr) {
		if (mp.count(arr)) return mp[arr];
		int res = 0;
		for (int i = 0; i < len; i++) {
			if (arr[i] == 0) continue;
			int x = i, x1 = -1, x2 = -1;
			int tx = 0, tx1 = 0, tx2 = 0;
			if (check[arr[x] - 1] != -1) {
				x1 = check[arr[x] - 1];
				swap(arr[x1], tx1);
			}
			if (check[arr[x] + 1] != -1) {
				x2 = check[arr[x] + 1];
				swap(arr[x2], tx2);
			}
			swap(arr[x], tx);
			res = max(res, 1 + compute(arr));
			swap(arr[x], tx);
			if (x1 != -1) swap(arr[x1], tx1);
			if (x2 != -1) swap(arr[x2], tx2);
		}
		return mp[arr] = res;
	}
	int maxTurns(vector<int> cards) {
		check.assign(502, -1);
		len = cards.size();
		for (int i = 0; i < len; i++) check[cards[i]] = i;
		return compute(cards);
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
		cout << "Testing SRMCards (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1479926512;
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
		SRMCards _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int cards[] = {498, 499};
			_expected = 1;
			_received = _obj.maxTurns(vector <int>(cards, cards + sizeof(cards) / sizeof(int))); break;
		}
		case 1:
		{
			int cards[] = {491, 492, 495, 497, 498, 499};
			_expected = 4;
			_received = _obj.maxTurns(vector <int>(cards, cards + sizeof(cards) / sizeof(int))); break;
		}
		case 2:
		{
			int cards[] = {100, 200, 300, 400};
			_expected = 4;
			_received = _obj.maxTurns(vector <int>(cards, cards + sizeof(cards) / sizeof(int))); break;
		}
		case 3:
		{
			int cards[] = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1};
			_expected = 6;
			_received = _obj.maxTurns(vector <int>(cards, cards + sizeof(cards) / sizeof(int))); break;
		}
		case 4:
		{
			int cards[] = {118, 321, 322, 119, 120, 320};
			_expected = 4;
			_received = _obj.maxTurns(vector <int>(cards, cards + sizeof(cards) / sizeof(int))); break;
		}
		case 5:
		{
			int cards[] = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			_expected = 7;
			_received = _obj.maxTurns(vector <int>(cards, cards + sizeof(cards) / sizeof(int))); break;
		}
		/*case 6:
		{
			int cards[] = ;
			_expected = ;
			_received = _obj.maxTurns(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			int cards[] = ;
			_expected = ;
			_received = _obj.maxTurns(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
		}*/
		/*case 8:
		{
			int cards[] = ;
			_expected = ;
			_received = _obj.maxTurns(vector <int>(cards, cards+sizeof(cards)/sizeof(int))); break;
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
