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
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	string temp;
	int i, j;
	while (getline(cin, temp)) {
		if (temp == "Game Over")
			break;
		string str;
		int len = temp.length();
		for (i = 0; i < len; i += 2)
			str.push_back(temp[i]);

		// cout << str << endl;
		int points = 0;
		int f = 0;
		len = str.length();
		bool frames[len] = {false};
		for (i = 0; i < len; i++) {
			if (f < 10) {
				if (str[i] == 'X') {
					points += 10;
					if (i + 1 < len) {
						if (str[i + 1] == 'X')
							points += 10;
						else if (str[i + 1] == '/')
							points += 10 - (str[i] - '0');
						else
							points += (str[i + 1] - '0');
					}
					if (i + 2 < len) {
						if (str[i + 2] == 'X')
							points += 10;
						else if (str[i + 2] == '/')
							points += (10 - (str[i + 1] - '0'));
						else
							points += (str[i + 2] - '0');
					}
					frames[i] = true;
					f++;
				} else if (str[i] == '/') {
					points += 10 - (str[i - 1] - '0');
					if (i + 1 < len) {
						if (str[i + 1] == 'X')
							points += 10;
						else
							points += (str[i + 1] - '0');
					}
					f++;
					frames[i] = true;
				} else {
					points += (str[i] - '0');
					if (i - 1 >= 0 && !frames[i - 1]) {
						frames[i] = true;
						f++;
					}
				}
			}
			// cout << "Frame " << f << " " << i << " " << str[i] << " " << "Points: " << points << endl;
		}
		cout<<points<<'\n';
		// for (i = 0; i < size; i++)
		// 	cout << arr[i] << " ";
		// cout << '\n';
	}

}