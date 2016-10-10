#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
map<string, int> mp;
vector<string> v;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; string s;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		getline(cin, s);
		while (n--) {
			getline(cin, s);
			// mp[s]++;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		n = int(v.size());
		int count = 1;

		for (int i = 0; i < n;) {
			cout << v[i] << " ";
			count = 1;
			int j;
			for (j = i + 1; j < n && v[i] == v[j]; j++) {
				count++;
			}
			cout << count << endl;
			i = j;
		}
		cout << endl;
		// mp.clear();
		v.clear();
	}


}