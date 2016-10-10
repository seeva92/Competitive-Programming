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
	ll t, n; cin >> t;
	bool flag = false;
	while (t--) {
		flag = false;
		cin >> n;
		ll start = 1, end = sqrt(n), ss, ee;
		if ((end * end) == n) cout << "Yes\n";
		else {
			while (start <= end) {
				ss = start * start; ee = end * end;
				if (ss + ee == n){cout << "Yes\n"; flag=true; break;}
				else if (ss + ee < n) start++;
				else end--;
			}
			if(!flag) cout<<"No\n";
		}

	}

}