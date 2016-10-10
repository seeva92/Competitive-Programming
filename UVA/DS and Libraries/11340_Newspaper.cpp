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
int n, k, m, val;
char c;
int arr[1000];
int i, len;
long long total;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	stringstream ss;
	string str;
	getline(cin, str);

	ss << str;
	ss >> n;
	while (n--) {
		getline(cin, str); ss << str; ss >> k;
		memset(arr, 0, sizeof arr); total = 0;
		while (k--) {
			getline(cin, str); ss << str;
			ss >> c; ss >> val;
			arr[(int)c] = val;
		}
		getline(cin, str); ss << str; ss >> m;
		while (m--) {
			getline(cin, str);
			if (str.back() == '\r')
				str.pop_back();
			len = str.length();
			for (i = 0; i < len; i++) {
				total += arr[str[i]];
			}
		}
		cout << total / 100 << ".";
		if (total % 100 < 10)
			cout << 0;
		cout << total % 100 << "$" << '\n';
	}
}