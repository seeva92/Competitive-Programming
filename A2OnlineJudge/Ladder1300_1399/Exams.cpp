#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
struct day { int a, b;};
pair<int, int> days[5007];
class Exams
{
	int n;
public:
	void solve() {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> days[i].first >> days[i].second;
		sort(days, days + n);
		int prev = 0;
		for (int i = 0; i < n; i++) {
			if (prev <= days[i].second) prev = days[i].second;
			else prev = days[i].first;
		}
		cout << prev;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Exams e; e.solve();
}
