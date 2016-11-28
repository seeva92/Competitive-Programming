#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll N;
class LuckyNumbers {
public:
	ll solve() {
		cin >> N;
		queue<string> q; q.push("4"); q.push("7");
		ll res;
		int fr = 0, sv = 0;
		while (!q.empty()) {
			string temp = q.front(); q.pop();
			res = stoll(temp);
			fr = sv = 0;
			for (auto i : temp)
				if (i == '4') fr++;
				else sv++;
			if (fr == sv && N <= res) { break;}
			q.push(temp + "4");
			q.push(temp + "7");
		}
		return res;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LuckyNumbers l;
	cout << l.solve();
}
