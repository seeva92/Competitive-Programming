#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX], cpy[MAX];
class PallindromeTransformation
{
	int n, p;
	string s;
	vector<int> mis;
public:
	void pre() {
		memset(arr, 0, sizeof arr);
		int l = 0, r = n - 1;
		while (l <= r) {
			if (s[l] < s[r]) {
				arr[l] = arr[r] = min(s[r] - s[l], abs(('z' - s[r]) + (s[l] - 'a')) + 1);
				// cout << "F " << arr[l] << " " << arr[r] << '\n';
				mis.push_back(l + 1);
			}
			else if (s[l] > s[r]) {
				arr[l] = arr[r] = min(s[l] - s[r], abs(('z' - s[l]) + (s[r] - 'a')) + 1);
				// cout << "S " << arr[l] << " " << arr[r] << '\n';
				mis.push_back(l + 1);
			}
			l++; r--;
		}
	}
	void solve() {
		cin >> n >> p;
		cin >> s;
		pre();

		ll curr = 0;
		for (int i = 1; i <= n / 2; i++) {
			// cout << arr[i - 1] << " ";
			curr += arr[i - 1];
		}
		// cout << '\n';
		if (n / 2 < p && p <= n) p = 1 + n - p;
		// cout << curr << '\n';
		if (mis.size() == 1) cout << curr + abs(p - mis[0]);
		else if (mis.size() > 1) {
			if (mis.front() <= p && p <= mis.back())
				cout << curr + min(abs(mis.back() - p) + abs(mis.back() - mis.front()), abs(p - mis.front() ) + abs(mis.back() - mis.front()));
			else if (p < mis.front()) cout << curr + abs(mis.back() - p);
			else if (p > mis.back()) cout << curr + abs(p - mis.front());
		}
		else cout << 0;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	PallindromeTransformation p; p.solve();
}
