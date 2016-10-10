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
class ReadingBooks {
	public:
	int countBooks(vector <string> readParts) {
		
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
		cout << "Testing ReadingBooks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471913801;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ReadingBooks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string readParts[] = {"introduction", "story", "introduction", "edification"};
				_expected = 1;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}
			case 1:
			{
				string readParts[] = {"introduction", "story", "edification", "introduction", "story", "edification"};
				_expected = 2;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}
			case 2:
			{
				string readParts[] = {"introduction", "story", "introduction", "edification", "story", "introduction"};
				_expected = 1;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}
			case 3:
			{
				string readParts[] = {"introduction", "story", "introduction", "edification", "story",
				                      "story", "edification", "edification", "edification", "introduction",
				                      "introduction", "edification", "story", "introduction", "story",
				                      "edification", "edification", "story", "introduction", "edification",
				                      "story", "story", "edification", "introduction", "story"};
				_expected = 5;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}
			/*case 4:
			{
				string readParts[] = ;
				_expected = ;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string readParts[] = ;
				_expected = ;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string readParts[] = ;
				_expected = ;
				_received = _obj.countBooks(vector <string>(readParts, readParts+sizeof(readParts)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
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
