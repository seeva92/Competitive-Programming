#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
int unread = 0;
vector<int> arr[300007];
bool visited[300007];
int idx = 1, curr = 1;
void compute(int t, int x) {
	if (t == 1) {
		arr[x].push_back(idx); idx++;
		unread++;
	} else if (t == 2) {
		while (!arr[x].empty()) {
			if (!visited[arr[x].back()]) {
				visited[arr[x].back()] = 1;
				unread--;
			}
			arr[x].pop_back();
		}
	}
	else {
		while (curr <= x) {
			if (!visited[curr]) {
				unread--;
				visited[curr] = 1;
			}
			curr++;
		}
	}
	cout << unread << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(visited, 0, sizeof visited);
	int n, q;
	cin >> n >> q;
	int t, x;
	for (int i = 1; i <= q; i++) {
		cin >> t >> x;
		compute(t, x);
	}
}
