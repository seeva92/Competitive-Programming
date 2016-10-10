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
class OrderedSuperString {
public:
	int getLength(vector <string> words) {
		int len = words.size();
		string res = "";
		int last = 0;
		for (auto word : words) {
			for (int i = last; i <= res.size(); i++) {
				int overlap = min(res.size() - i, word.size());
				string temp1 = res.substr(i, overlap);
				string temp2 = word.substr(0, overlap);
				if (temp1 == temp2) {
					res += word.substr(overlap);
					last = i;
					break;
				}
			}
		}
		return res.size();
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
		cout << "Testing OrderedSuperString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1475166808;
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
		OrderedSuperString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string words[] = {"abc", "ca"};
			_expected = 4;
			_received = _obj.getLength(vector <string>(words, words + sizeof(words) / sizeof(string))); break;
		}
		case 1:
		{
			string words[] = {"a", "a", "b", "a"};
			_expected = 3;
			_received = _obj.getLength(vector <string>(words, words + sizeof(words) / sizeof(string))); break;
		}
		case 2:
		{
			string words[] = {"abcdef", "ab", "bc", "de", "ef"};
			_expected = 6;
			_received = _obj.getLength(vector <string>(words, words + sizeof(words) / sizeof(string))); break;
		}
		case 3:
		{
			string words[] = {"ab", "bc", "de", "ef", "abcdef"};
			_expected = 12;
			_received = _obj.getLength(vector <string>(words, words + sizeof(words) / sizeof(string))); break;
		}
		/*case 4:
		{
			string words[] = ;
			_expected = ;
			_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
		}*/
		/*case 5:
		{
			string words[] = ;
			_expected = ;
			_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
		}*/
		/*case 6:
		{
			string words[] = ;
			_expected = ;
			_received = _obj.getLength(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
