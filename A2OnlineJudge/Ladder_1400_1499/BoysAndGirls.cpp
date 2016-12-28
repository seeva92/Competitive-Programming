#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class BoysAndGirls
{
	int n, m;
public:
	void solve() {
		cin >> n >> m;
		char c;
		if (n > m) { cout << 'B'; c = 'B'; n--;}
		else { cout << 'G'; c = 'G'; m--;}
		while (n || m) {
			if (c == 'G') {
				if (n > 0) { cout << 'B'; n--; c = 'B';}
				else if (m > 0) { cout << 'G'; m--; c = 'G';}
			} else {
				if (m > 0) { cout << 'G'; m--; c = 'G';}
				else if (n > 0) { cout << 'B'; n--; c = 'B';}
			}
		}
	}
};
int main() {
// #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	BoysAndGirls b; b.solve();
}
