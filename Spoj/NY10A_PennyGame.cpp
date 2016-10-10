#include <cstdio>
#include <unordered_map>
#include <iostream>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif

	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t, x;
	cin >> t;
	string seq[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
	for (int a = 1; a <= t; a++) {
		unordered_map<string, int> mp;
		string str;
		cin >> x >> str;
		int len = int(str.size());
		for (int i = 0; i < (len - 2); i++) {
			mp[str.substr(i, 3)] += 1;
		}
		cout << x;
		for (int i = 0; i < 8; i++)
			cout << " " << mp[seq[i]];
		cout << endl;
	}
}

