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
	int n; string str;
	int arr[26]; memset(arr, 0, sizeof arr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		arr[str[0] - 'a']++;
	}
	
	int total = 0;
	for (int i = 0; i < 26; i++) {
		total += (arr[i] / 10);
		if (arr[i] % 10) total++;
	}
	cout << total << endl;
}