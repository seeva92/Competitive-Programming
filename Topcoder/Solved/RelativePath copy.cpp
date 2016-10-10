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
class RelativePath {
public:
	string back = "..";

	vector<string> compute(string path) {
		vector<string> p;
		string temp = "";
		for (int i = 0; i < int(path.size()); i++) {
			if (path[i] != '/')
				temp += path[i];
			else if (temp != "") {
				p.push_back(temp); temp = "";
			}
		}
		if (temp != "") p.push_back(temp);
		return p;
	}
	string makeRelative(string path, string currentDir) {
		string res = "";
		vector<string> p = compute(path), c = compute(currentDir);
		// for (auto i : p) cout << i << " "; cout << '\n';
		// for (auto i : c) cout << i << " ";
		bool flag = false;
		int i, j;
		for (i = 0, j = 0; i < int(p.size()) && j < int(c.size()); i++, j++) {
			if (p[i] == c[j]) continue;
			else  break;
		}
		for (; j < int(c.size()); j++) {
			res += back; res += "/";
		}
		for (; i < int(p.size()); i++) {
			res += p[i];
			if (i + 1 != int(p.size())) res += "/";
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
		cout << "Testing RelativePath (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL) - 1471914927;
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
		RelativePath _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
		case 0:
		{
			string path = "/home/top/data/file";
			string currentDir = "/home/user/pictures";
			_expected = "../../top/data/file";
			_received = _obj.makeRelative(path, currentDir); break;
		}
		case 1:
		{
			string path = "/home/user/movies/title";
			string currentDir = "/home/user/pictures";
			_expected = "../movies/title";
			_received = _obj.makeRelative(path, currentDir); break;
		}
		case 2:
		{
			string path = "/file";
			string currentDir = "/";
			_expected = "file";
			_received = _obj.makeRelative(path, currentDir); break;
		}
		case 3:
		{
			string path = "/a/b/a/b/a/b";
			string currentDir = "/a/b/a/a/b/a/b";
			_expected = "../../../../b/a/b";
			_received = _obj.makeRelative(path, currentDir); break;
		}
		case 4:
		{
			string path = "/root/root/root";
			string currentDir = "/root";
			_expected = "root/root";
			_received = _obj.makeRelative(path, currentDir); break;
		}
		/*case 5:
		{
			string path = ;
			string currentDir = ;
			_expected = ;
			_received = _obj.makeRelative(path, currentDir); break;
		}*/
		/*case 6:
		{
			string path = ;
			string currentDir = ;
			_expected = ;
			_received = _obj.makeRelative(path, currentDir); break;
		}*/
		/*case 7:
		{
			string path = ;
			string currentDir = ;
			_expected = ;
			_received = _obj.makeRelative(path, currentDir); break;
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
