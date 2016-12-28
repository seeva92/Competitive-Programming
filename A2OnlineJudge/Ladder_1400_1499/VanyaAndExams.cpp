#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
const double eps = 1e-9;
using namespace std;
typedef vector<int> vi;
pair<double, double> arr[MAX];
class VanyaAndExams
{
	ll n, r;
	double g;
public:
	void solve() {
		cin >> n >> r >> g;
		double total = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].second >> arr[i].first;
			total += arr[i].second;
		}

		double curr = (total / (double)n);

		if (curr > g || abs(curr - g) < eps) { cout << 0; return;}

		sort(arr, arr + n);
		ll res = 0;
		for (int i = 0; i < n; i++) {
			curr = (total + (double)(r - arr[i].second)) / (double)n;
			if (curr < g || abs(curr - g) < eps) {
				total = total + (r - arr[i].second);
				res = res + ((r - arr[i].second) * arr[i].first);
			}
			else {
				ll lt = 1, rt = r - arr[i].second;
				ll temp = 0;
				while (lt <= rt) {
					ll mid = (lt + rt) / 2;
					curr = (total + (double)mid) / (double)n;
					if ((curr < g) || (abs(curr - g) < eps)) {
						temp = mid;
						lt = mid + 1;
					} else {
						rt = mid - 1;
					}
				}
				res = res + (temp * arr[i].first);
				break;
			}
		}
		cout << res;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	VanyaAndExams v; v.solve();
}
