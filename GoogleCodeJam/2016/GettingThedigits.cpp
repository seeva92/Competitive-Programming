#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	int t; cin >> t;
	string str;
	for (int a = 1; a <= t; a++) {
		int arr[26]; memset(arr, 0, sizeof arr);
		cin >> str;

		for (auto i : str) arr[i - 'A']++;
		cout << "Case #" << a << ": ";
		stringstream ss;
		for (int i = 0; i < 10;) {
			string temp = num[i];
			int j;
			for (j = 0; j < int(temp.size()); j++) {
				if (arr[temp[j] - 'A'] > 0)
					arr[temp[j] - 'A']--;
				else {
					for (int k = j - 1; k >= 0; k--)
						arr[temp[k] - 'A']++;
					break;
				}
			}
			if (j == (int)temp.size())
				ss << i;
			else
				i++;
		}
		cout<<ss.str();
		cout << endl;
	}
}
