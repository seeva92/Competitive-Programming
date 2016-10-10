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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr;
	int pos[110];
	int total = 0, x;
	for (int i = 0; i < k; i++) {
		cin >> x; arr.push_back(x);
		pos[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x;
			// cout<<x<<" "<<pos[x]<<endl; 
			total += pos[x];
			int temp = arr[pos[x]];
			vector<int> narr; narr.push_back(temp);
			pos[temp] = 0;
			for (int l = 0; l < int(arr.size()); l++) {
				if (arr[l] != temp) {
					narr.push_back(arr[l]);
					pos[arr[l]] = int(narr.size()) - 1;
				}
			}
			swap(arr, narr);
		}
	}
	cout << total+(n*m) << endl;

}