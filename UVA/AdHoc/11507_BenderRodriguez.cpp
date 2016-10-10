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
using namespace std;
int main() {
	// std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int n;
	// scanf("%d", &n);

	cin >> n;
	string arr;
	map<string, map<string, string>> mp;
	mp["+x"]["+y"] = "+y";
	mp["+x"]["-y"] = "-y";
	mp["+x"]["+z"] = "+z";
	mp["+x"]["-z"] = "-z";
	mp["-x"]["+y"] = "-y";
	mp["-x"]["-y"] = "+y";
	mp["-x"]["+z"] = "-z";
	mp["-x"]["-z"] = "+z";
	mp["+y"]["+y"] = "-x";
	mp["+y"]["-y"] = "+x";
	mp["+y"]["+z"] = "+y";
	mp["+y"]["-z"] = "+y";
	mp["-y"]["+y"] = "+x";
	mp["-y"]["-y"] = "-x";
	mp["-y"]["+z"] = "-y";
	mp["-y"]["-z"] = "-y";
	mp["+z"]["+y"] = "+z";
	mp["+z"]["-y"] = "+z";
	mp["+z"]["+z"] = "-x";
	mp["+z"]["-z"] = "+x";
	mp["-z"]["+y"] = "-z";
	mp["-z"]["-y"] = "-z";
	mp["-z"]["+z"] = "+x";
	mp["-z"]["-z"] = "-x";

	while (n != 0) {
		string temp = "+x"; n--;
		for (int i = 0; i < n; i++) {
			cin >> arr;
			// cout<<arr<<" ";
			if (arr == "No")
				continue;
			temp = mp[temp][arr];
			// cout<<temp<<" "<<arr<<endl;
		}
		// cout<<'\n';
		cout << temp << '\n';
		cin >> n;
	}
}