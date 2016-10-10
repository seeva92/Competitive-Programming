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
	int arr[26] = {0};
	int n; string str;
	cin >>n>> str;
	if (n > 26) cout << -1 << endl;
	else {
		for (auto it : str) arr[it-'a']++;
		int cnt = 0;
		for (int i = 0; i < 26; i++) if (arr[i] != 0) cnt++;
		cout << int(str.size()) - cnt << endl;
	}

}