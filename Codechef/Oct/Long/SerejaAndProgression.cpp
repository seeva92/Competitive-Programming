#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[100007];
vector<pair<int, int>> v;
vector<int> del;
pair<int, int> arrc[100007];
int N, S, D;
int partition(int i, int j) {
	int pVal = arr[i];
	int ii = i + 1, jj = j;
	for (; ii <= jj && S > 0;) {
		while (ii <= jj && pVal >= arr[ii]) ii++;
		while (ii <= jj && pVal <= arr[jj]) jj--;
		if (ii <= jj)
		{
			if (S > 0) {
				swap(arr[ii], arr[jj]);
				v.push_back({ii, jj});
				S--;
			}
		}
	}
	if (S > 0 && (arr[i] != arr[jj])) {
		swap(arr[i], arr[jj]);
		v.push_back({i, jj});
		S--;
	}
	return jj;
}
void quick(int i, int j) {
	if (i < j) {
		int p = partition(i, j);
		if (S > 0) quick(i, p - 1);
		if (S > 0) quick(p + 1, j);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S >> D;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	quick(1, N);
	for (int i = 1; i <= N; i++) {
		arrc[i] = {arr[i], i};
	}
	stable_sort(arrc + 1, arrc + N + 1);
	int i;
	for (i = N; i >= 1 && D > 0; i--) {
		del.push_back(arrc[i].second);
		arr[arrc[i].second] = -1;
		D--;
	}
	//A R
	if (i == 0) cout << "0 0" << '\n';
	else cout << "0 " << arrc[(1 + i) / 2].first << '\n';
	//Swap
	for (auto it : v) cout << "1 " << it.first << " " << it.second << '\n';
	//Del
	for (auto it : del) cout << "2 " << it << '\n';
	cout << "-1\n";
}
