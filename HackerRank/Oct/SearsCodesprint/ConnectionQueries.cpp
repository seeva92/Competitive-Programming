#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int N, Q, BLK;
struct query {
	int x, y, i;
} Qu[50007];
int arr[100007], ans[50007];
bool taken[100007];
int L = 0, R = 0, C = 0;
inline bool cmp(query a, query b) {
	if (a.x / BLK != b.x / BLK) return a.x / BLK < b.x / BLK;
	return a.y / BLK < b.y / BLK;
}
void add(int i) {
	if (taken[arr[i] - 1] && taken[arr[i] + 1]) C--;
	else if (!taken[arr[i] - 1] && !taken[arr[i] + 1]) C++;
	taken[arr[i]] = true;
}
void remove(int i) {
	if (taken[arr[i] - 1] && taken[arr[i] + 1]) C++;
	else if (!taken[arr[i] - 1] && !taken[arr[i] + 1]) C--;
	taken[arr[i]] = false;
}
void solve(int l, int r) {
	while (L > l) { add(L - 1); L--; }
	while (R <= r) { add(R); R++; }
	while (L < l) { remove(L); L++; }
	while (R > (r + 1)) { remove(R - 1); R--;}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(taken, 0, sizeof taken);
	cin >> N >> Q;
	BLK = sqrt(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < Q; i++) {
		cin >> Qu[i].x >> Qu[i].y, Qu[i].i = i;
		Qu[i].x--, Qu[i].y--;
	}
	sort(Qu, Qu + Q, cmp);
	for (int i = 0; i < Q; i++) {
		solve(Qu[i].x, Qu[i].y);
		ans[Qu[i].i] = C;
	}
	for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
}
