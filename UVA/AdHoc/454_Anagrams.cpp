#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <sstream>
using namespace std;
void removeWhiteSpace(string & str) {
	int i, len = str.size();
	string temp;
	for (i = 0; i < len; i++)
		if (str[i] != ' ')
			temp.push_back(str[i]);

	str = temp;
}
int compare(const string & a, const string & b) {
	return strcmp(a.c_str(), b.c_str());
}
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int t;
	string str;
	stringstream ss;
	getline(cin, str); ss << str;
	ss >> t;
	getline(cin, str);

	// cout<<t;
	while (t--) {
		if (str.back() == '\r')
			str.pop_back();

		map<string, vector<string>> mapped;
		string temp;

		while (getline(cin, str)) {
			if (str.back() == '\r')
				str.pop_back();
			if (str.empty())
				break;
			// cout<<str<<'\n';
			temp = str;
			removeWhiteSpace(temp);
			sort(temp.begin(), temp.end());
			// cout << temp << '\n';

			mapped[temp].push_back(str);
		}
		// for(map<string,vector<string>>::iterator i = mapped.begin(); i!=mapped.end();i++){
		// 	cout<<i->first<<'\n';
		// 	vector<string> v = i->second;
		// 	for(int j=0;j<(int)v.size();j++)
		// 		cout<<v[j]<<" ";
		// 	cout<<'\n';
		// }
		vector<string> result;
		for (map<string,vector<string>>::iterator i = mapped.begin();i!=mapped.end();i++) {
			vector<string> v = i->second;
			sort(v.begin(),v.end());
			int vlen = v.size();
			for (int j = 0; j < vlen; j++) {
				for(int k=j+1;k<vlen;k++)
					result.push_back(v[j] + " = " + v[k]);
			}
		}
		sort(result.begin(),result.end());
		for (std::vector<string>::iterator i = result.begin(); i != result.end(); ++i)
		{
			cout << *i << '\n';
		}
		if (t != 0)
			cout << '\n';
	}

}