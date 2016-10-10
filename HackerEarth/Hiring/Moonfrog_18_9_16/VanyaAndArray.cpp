#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n, k;
pair<int, int> arr[1000007];
int inver[1000007];
int bit[1000007];
map<int, int> mp;
void update(int val, int i) {
	while (i <= n) {
		bit[i] += val;
		i += (i & -i);
	}
}
int query(int i) {
	int sum = 0;
	while (i > 0) {
		sum += bit[i];
		i -= (i & -i);
	}
	return sum;
}
void compute() {
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--) {
		if (mp.count(arr[i].first)) update(-1, mp[arr[i].first]);
		inver[arr[i].second] = query(n) - query(arr[i].second);
		update(1, arr[i].second + 1);
		mp[arr[i].first] = arr[i].second + 1;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<long long> st;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	compute();

	vector<int> temp (inver, inver + n);
	sort(temp.begin(), temp.end());
	for (auto it : temp) cout << it << " "; cout << endl;
	int len = temp.size(), res = 0;
	int prev = -1;
	for (int i = 0; i < len; i++) {
		if (temp[i] == prev) continue;
		if (k > temp[i]) {
			res += temp.end() - lower_bound(temp.begin() + i + 1, temp.end(), k - temp[i]) ;
		}

		prev = temp[i];
	}
	cout << res << '\n';

}


