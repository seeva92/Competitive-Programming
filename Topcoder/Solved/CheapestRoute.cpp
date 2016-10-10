#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class CheapestRoute {
public:
	int mp[107][107];
	int dx[2] = { -1, 1};
	pair<int, int> F[107][107];
	vector <int> routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) {
		int n = cellPrice.size();
		for (size_t i = 0; i < enterCell.size(); i++) mp[enterCell[i]][exitCell[i]] = 1;

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++) F[i][j] = { -1, -1};

		F[0][0] = {0, 0};
		queue<pair<int, int>> q; q.push({0, 0});
		while (!q.empty()) {
			auto x = q.front(); q.pop();
			int i = x.first, num = x.second;
			int ocost = F[i][num].first, od = F[i][num].second;
			for (int k = 0; k < 2; k++) {
				if ((i + dx[k] >= 0) && (i + dx[k] < n) && cellPrice[i + dx[k]] != -1) {
					pair<int, int> newstate = {i + dx[k], num};
					pair<int, int> newcost = {ocost + cellPrice[i + dx[k]], od + 1};
					if (F[i + dx[k]][num].first == -1 || F[i + dx[k]][num] > newcost) {
						F[i + dx[k]][num] = newcost;
						q.push(newstate);
					}
				}
			}

			if (num < n) {
				for (int j = 0; j < n; j++) {
					if (mp[i][j] && cellPrice[j] != -1) {
						pair<int, int> newstate = {j, num + 1};
						pair<int, int> newcost = {ocost + num + teleportPrice, od + 1};
						if (F[j][num + 1].first == -1 || F[j][num + 1] > newcost) {
							F[j][num + 1] = newcost;
							q.push(newstate);
						}
					}
				}
			}
		}

		pair<int, int> res = {1e9, 1e9};
		for (int i = 0; i <= n; i++) {
			if (F[n - 1][i].first != -1)
				if (F[n - 1][i] < res)
					res = F[n - 1][i];
		}

		if (res.first == 1e9) return {};
		return {res.first, res.second};
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
		cout << "Testing CheapestRoute (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1473576478;
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
		CheapestRoute _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			int cellPrice[] = {100};
			int enterCell[] = {0};
			int exitCell[] = {0};
			int teleportPrice = 1000;
			int __expected[] = {0, 0 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice + sizeof(cellPrice) / sizeof(int)), vector <int>(enterCell, enterCell + sizeof(enterCell) / sizeof(int)), vector <int>(exitCell, exitCell + sizeof(exitCell) / sizeof(int)), teleportPrice); break;
		}
		case 1:
		{
			int cellPrice[] = {0, -1, 0, 0};
			int enterCell[] = {0};
			int exitCell[] = {2};
			int teleportPrice = 1000;
			int __expected[] = {1000, 2 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice + sizeof(cellPrice) / sizeof(int)), vector <int>(enterCell, enterCell + sizeof(enterCell) / sizeof(int)), vector <int>(exitCell, exitCell + sizeof(exitCell) / sizeof(int)), teleportPrice); break;
		}
		case 2:
		{
			int cellPrice[] = {1, 2, 3};
			int enterCell[] = {};
			int exitCell[] = {};
			int teleportPrice = 100;
			int __expected[] = {5, 2 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice + sizeof(cellPrice) / sizeof(int)), vector <int>(enterCell, enterCell + sizeof(enterCell) / sizeof(int)), vector <int>(exitCell, exitCell + sizeof(exitCell) / sizeof(int)), teleportPrice); break;
		}
		case 3:
		{
			int cellPrice[] = {1, 0, -1};
			int enterCell[] = {0};
			int exitCell[] = {2};
			int teleportPrice = 0;
			int __expected[] = { };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice + sizeof(cellPrice) / sizeof(int)), vector <int>(enterCell, enterCell + sizeof(enterCell) / sizeof(int)), vector <int>(exitCell, exitCell + sizeof(exitCell) / sizeof(int)), teleportPrice); break;
		}
		case 4:
		{
			int cellPrice[] = {4, 2, 1, 0, 5, 6, 0, 3, 0};
			int enterCell[] = {4, 4, 3, 7, 5, 4, 2, 5, 8, 4};
			int exitCell[] = {7, 3, 5, 0, 5, 4, 5, 0, 8, 3};
			int teleportPrice = 8;
			int __expected[] = {14, 6 };
			_expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice + sizeof(cellPrice) / sizeof(int)), vector <int>(enterCell, enterCell + sizeof(enterCell) / sizeof(int)), vector <int>(exitCell, exitCell + sizeof(exitCell) / sizeof(int)), teleportPrice); break;
		}
		/*case 5:
		{
			int cellPrice[] = ;
			int enterCell[] = ;
			int exitCell[] = ;
			int teleportPrice = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
		}*/
		/*case 6:
		{
			int cellPrice[] = ;
			int enterCell[] = ;
			int exitCell[] = ;
			int teleportPrice = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
		}*/
		/*case 7:
		{
			int cellPrice[] = ;
			int enterCell[] = ;
			int exitCell[] = ;
			int teleportPrice = ;
			int __expected[] = ;
			_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
			_received = _obj.routePrice(vector <int>(cellPrice, cellPrice+sizeof(cellPrice)/sizeof(int)), vector <int>(enterCell, enterCell+sizeof(enterCell)/sizeof(int)), vector <int>(exitCell, exitCell+sizeof(exitCell)/sizeof(int)), teleportPrice); break;
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
