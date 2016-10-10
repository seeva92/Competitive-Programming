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
class SpiralWalking {
public:
	int i = 0, j = 0;
	int curr = 1;
	void compute(int dir) {
		switch (dir) {
		case 1 : j++; break;
		case 2 : j--; break;
		case 3 : i++; break;
		case 4 : i--; break;
		}
	}
	int totalPoints(vector <string> levelMap) {
		int total = int(levelMap.size()) * int(levelMap[0].size());
		int n = int(levelMap.size()), m = int(levelMap[0].size());
		int points = 0;
		while (total > 0) {
			int temp = int(levelMap[i][j] - '0');
			levelMap[i][j] = '-';
			// cout << temp << " " << i << " " << j << "\n";
			points += temp;
			// cout << i << " " << j << "\n";
			switch (curr) {
			case 1 : if ((j + 1) < m && levelMap[i][j + 1] != '-') compute(1);
				else {
					if (total - 1 != 0)
						points -= temp;
					compute(3); curr = 3;
				} break;
			case 2: if ((j - 1) >= 0 && levelMap[i][j - 1] != '-') compute(2);
				else {
					if (total - 1 != 0)
						points -= temp; compute(4); curr = 4;
				} break;
			case 3: if ((i + 1) < n && levelMap[i + 1][j] != '-') compute(3);
				else {
					if (total - 1 != 0)
						points -= temp; compute(2); curr = 2;
				} break;
			case 4: if ((i - 1) >= 0 && levelMap[i - 1][j] != '-') compute(4);
				else {
					if (total - 1 != 0)
						points -= temp; compute(1); curr = 1;
				} break;
			}
			// cout << points << '\n';
			total--;
		}

		return points;
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
		cout << "Testing SpiralWalking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1473573357;
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
		SpiralWalking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string levelMap[] = {"111",
			                     "111",
			                     "111"
			                    };
			_expected = 5;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap + sizeof(levelMap) / sizeof(string))); break;
		}
		case 1:
		{
			string levelMap[] = {"101",
			                     "110"
			                    };
			_expected = 3;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap + sizeof(levelMap) / sizeof(string))); break;
		}
		case 2:
		{
			string levelMap[] = {"00",
			                     "10"
			                    };
			_expected = 1;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap + sizeof(levelMap) / sizeof(string))); break;
		}
		case 3:
		{
			string levelMap[] = {"86850",
			                     "76439",
			                     "15863",
			                     "24568",
			                     "45679",
			                     "71452",
			                     "05483"
			                    };
			_expected = 142;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap + sizeof(levelMap) / sizeof(string))); break;
		}
		/*case 4:
		{
			string levelMap[] = ;
			_expected = ;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
		}*/
		/*case 5:
		{
			string levelMap[] = ;
			_expected = ;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
		}*/
		/*case 6:
		{
			string levelMap[] = ;
			_expected = ;
			_received = _obj.totalPoints(vector <string>(levelMap, levelMap+sizeof(levelMap)/sizeof(string))); break;
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
