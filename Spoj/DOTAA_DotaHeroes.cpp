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
	int t, n, m, d, h; cin >> t;
	while (t--) {
		cin >> n >> m >> d;
		priority_queue<int> p;
		while (n--) {
			cin >> h; p.push(h);
		}
		bool flag = true;
		while (m-- && flag) {
			int tmp = p.top(); p.pop();
			tmp -= d;
			if (tmp <= 0) flag = false;
			else p.push(tmp);
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

}