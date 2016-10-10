#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class AddElectricalWires {
public:

	bool vis[55];
	int c = 0;
	int dp[60][60];
	vector<string> w;
	void can(int i) {
		vis[i] = true;
		c++;
		for (int j = 0; j < int(w[i].size()); j++)
			if (w[i][j] == '1' && !vis[j]) can(j);
	}

	int maxNewWires(vector <string> wires, vector <int> gridConnections) {
		w = wires;
		int curr = 0;
		for (auto i : wires)
			for (auto j : i)
				if (j == '1') curr++;
		curr /= 2;
		int res = 0;
		int mst = 0;
		int left = wires.size();
		for (auto i : gridConnections) {
			c = 0;
			can(i);
			res += (c * (c - 1)) / 2;
			left -= c;
			mst = max(mst, c);
		}
		res += (left * (left - 1)) / 2 + (mst * left);
		return res - curr;

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
		cout << "Testing AddElectricalWires (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1475721030;
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
		AddElectricalWires _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string wires[] = {"000", "000", "000"};
			int gridConnections[] = {0};
			_expected = 3;
			_received = _obj.maxNewWires(vector <string>(wires, wires + sizeof(wires) / sizeof(string)), vector <int>(gridConnections, gridConnections + sizeof(gridConnections) / sizeof(int))); break;
		}
		case 1:
		{
			string wires[] = {"000", "000", "000"};
			int gridConnections[] = {0, 1};
			_expected = 1;
			_received = _obj.maxNewWires(vector <string>(wires, wires + sizeof(wires) / sizeof(string)), vector <int>(gridConnections, gridConnections + sizeof(gridConnections) / sizeof(int))); break;
		}
		case 2:
		{
			string wires[] = {"01", "10"};
			int gridConnections[] = {0};
			_expected = 0;
			_received = _obj.maxNewWires(vector <string>(wires, wires + sizeof(wires) / sizeof(string)), vector <int>(gridConnections, gridConnections + sizeof(gridConnections) / sizeof(int))); break;
		}
		case 3:
		{
			string wires[] = {"00000", "00000", "00000", "00000", "00000"};
			int gridConnections[] = {0, 1, 2, 3, 4};
			_expected = 0;
			_received = _obj.maxNewWires(vector <string>(wires, wires + sizeof(wires) / sizeof(string)), vector <int>(gridConnections, gridConnections + sizeof(gridConnections) / sizeof(int))); break;
		}
		case 4:
		{
			string wires[] = {"01000", "10100", "01010", "00100", "00000"};
			int gridConnections[] = {2, 4};
			_expected = 3;
			_received = _obj.maxNewWires(vector <string>(wires, wires + sizeof(wires) / sizeof(string)), vector <int>(gridConnections, gridConnections + sizeof(gridConnections) / sizeof(int))); break;
		}
		/*case 5:
		{
			string wires[] = ;
			int gridConnections[] = ;
			_expected = ;
			_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
		}*/
		/*case 6:
		{
			string wires[] = ;
			int gridConnections[] = ;
			_expected = ;
			_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
		}*/
		/*case 7:
		{
			string wires[] = ;
			int gridConnections[] = ;
			_expected = ;
			_received = _obj.maxNewWires(vector <string>(wires, wires+sizeof(wires)/sizeof(string)), vector <int>(gridConnections, gridConnections+sizeof(gridConnections)/sizeof(int))); break;
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
