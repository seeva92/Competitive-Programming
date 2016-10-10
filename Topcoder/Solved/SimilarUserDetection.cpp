// BEGIN CUT HERE

// END CUT HERE
#line 5 "SimilarUserDetection.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class SimilarUserDetection {
public:
	string haveSimilar(vector <string> handles) {
		if (int(handles.size()) == 1) return "Similar handles not found";
		map<string, int> mp;
		for (auto it : handles) {
			if (!mp[it]) mp[it]++;
			else {
				// cout << "Wow";
				return "Similar handles found";
			}
		}
		int len = int(handles.size());
		for (int i = 0; i < len; i++)
			for (int j = i + 1; j < len; j++) {
				if (int(handles[i].size()) != int(handles[j].size())) continue;
				else {
					int k;
					for (k = 0; k < (int)handles[i].size(); k++) {
						// cout << handles[i][k] << " " << handles[j][k] << endl;
						if (handles[i][k] == handles[j][k]) continue;
						else if ((handles[i][k] == '0' || handles[i][k] == 'O') && (handles[j][k] == 'O' || handles[j][k] == '0')) continue;
						else if ((handles[i][k] == '1' || handles[i][k] == 'l' || handles[i][k] == 'I') && (handles[j][k] == '1' || handles[j][k] == 'l' || handles[j][k] == 'I')) continue;
						else {
							break;
						}
					}
					if (k == (int)handles[i].size()) return "Similar handles found";
				}
			}
		return "Similar handles not found";
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	SimilarUserDetection s;
// 	vector<string> vv {"Topcoder", "topcoder", "t0pcoder", "topcOder"};
// 	// cout << s.haveSimilar(vv);
// }
