#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
const int MAX = 316227777;
using namespace std;
ll powers[10][17];
bool bs[MAX];
vector<ll> primes;
void init() {
	for (ll i = 2; i <= 10; i++) {
		ll ans = 1;
		for (ll j = 1; j <= 16; j++) {
			ans *= i;
			powers[i][j] = ans;
		}
	}
	// for (int i = 2; i <= 10; i++, cout << endl)
	// 	for (int j = 1; j <= 16; j++)
	// 		cout << powers[i][j] << " ";
	memset(bs, 1, sizeof bs);
	bs[0] = 0; bs[1] = 0;
	ll size = (ll)MAX;
	for (ll i = 2; i < size; i++) {
		for (ll j = i * i; j < size; j += i)
			bs[j] = 0;
		if (bs[i]) primes.push_back(i);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	ll ans = 0;
	// for (ll i = 1; i < 100000007; i++) arr[i] = arr[i - 1] + i;

	// ll t, n, j; cin >> t;
	// while (t--) {
	// 	cin >> n >> j;
	// 	queue<string> q; q.push("0"); q.push("1");

	// 	while (!q.empty()) {
	// 		cout << q.front() << endl;
	// 		if (n != (ll)q.front().size()) {
	// 			q.push(q.front() + "0"); q.push(q.front() + "1");
	// 		} else {
	// 			bool flag = true;
	// 			for (ll i = 2; i <= 10 && flag; i++) {
	// 				for()

	// 			}
	// 			q.pop();
	// 		}
	// 	}
	// }

}