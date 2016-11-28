#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int N, K, A[507], B[507];
map<int, pair<int, int>> mp;
bool flag = true;
void compute() {
	int j = 1;
	int s = 1;
	flag = true;
	int sum = 0, c = 0;
	int mx = -1e9, mn = 1e9, mxdx = 0;
	for (int i = 1; i <= N; i++) {
		mx = max(mx, A[i]);
		mn = min(mn, A[i]);
		sum += A[i]; c++;
		if (B[j] == sum) {
			if (c != 1 && mx == mn) {
				flag = false; break;
			}
			c = 0;
			sum = 0;
			mp[j++] = {s, i};
			s = i + 1;
			mx = -1e9, mn = 1e9;
		} else if (sum > B[j]) {
			flag = false; break;
		}
	}
	if (int(mp.size()) != K || sum != 0) flag = false;
}
void print() {
	if (!flag) { cout << "NO"; return;}
	cout << "YES\n";
	int idx = 1;
	for (auto i : mp) {
		int cnt = i.second.second - i.second.first;
		// cout << idx << " " << cnt << " " << N << '\n';
		while (cnt) {
			int resi;
			priority_queue<pair<int, int>> pq;
			for (int j = idx; j <= (idx + cnt); j++) pq.push({A[j], j});
			while (!pq.empty()) {
				resi = pq.top().second;
				if (resi + 1 <= (idx + cnt) && A[resi] > A[resi + 1]) {
					cout << resi << " R" << '\n';
					A[resi] += A[resi + 1];
					for (int l = resi + 2; l <= N; l++) A[l - 1] = A[l];
					N--;
					// for (int f = 1; f <= N; f++) cout << A[f] << " "; cout << '\n';
					break;
				} else if (resi - 1 >= idx && A[resi] > A[resi - 1]) {
					cout << resi << " L" << '\n';
					A[resi - 1] += A[resi];
					for (int l = resi + 1; l <= N; l++) A[l - 1] = A[l];
					N--;
					// for (int f = 1; f <= N; f++) cout << A[f] << " "; cout << '\n';
					break;
				}
				pq.pop();
			}
			cnt--;
		}
		idx++;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> K;
	for (int i = 1; i <= K; i++)cin >> B[i];
	compute(); print();
}
