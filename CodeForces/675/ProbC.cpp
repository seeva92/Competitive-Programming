#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int neg[100007];
int pos[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n; int x;
	int i = 0, j = 0;
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>> neg;
	priority_queue<ll> pos;
	while (n--) {
		cin >> x;
		if (x < 0) neg.push(x);
		else if (x > 0) pos.push(x);
	}
	int cnt = 0;
	while (!pos.empty() && !neg.empty()) {
		ll tp = pos.top(), tn = neg.top();
		if (tp == (tn * -1)) {
			pos.pop(); neg.pop(); cnt++;
		} else if ((tp - (tn * -1)) > 0) {
			pos.pop(); pos.push(tp - (tn * -1)); neg.pop(); cnt++;
		} else if ((tp - (tn * -1)) < 0) {
			pos.pop(); neg.pop(); neg.push(tn + tp); cnt++;
		}
	}
	cout << cnt << endl;

}