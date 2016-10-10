#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <climits>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
const int MAX = 1e5 + 7;
int arr[MAX], L[MAX], R[MAX];
bool flag[MAX];
int n;
void compute() {
	bool f = false;
	int s = -1, e = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (flag[i]) {
			if (s == -1) {
				s = e = i;
			} else
				e = i;
			f = true;
			L[i] = 0;
			continue;
		}
		if (f) L[i] = L[i - 1] + (arr[i] - arr[i - 1]);
	}
	f = false;
	for (int i = n - 1; i >= 0; i--) {
		if (flag[i]) {
			f = true;
			R[i] = 0;
			continue;
		}
		if (f) R[i] = R[i + 1] + (arr[i + 1] - arr[i]);
	}

	int total = 0;
	total += (arr[s] - arr[0]);
	total += (arr[n - 1] - arr[e]);
	int curr = INT_MAX;
	for (; s < e; s++) {
		if (flag[s] && flag[s + 1])
			continue;
		if (curr > (L[s] + R[s + 1]))
			curr = (L[s] + R[s + 1]);
		if (flag[s + 1]) {
			total += curr;
			curr = INT_MAX;
		}
	}

	cout << total << endl;
	// for (int i = 0; i < n; i++) cout << L[i] << " ";
	// cout << endl;
	// for (int i = 0; i < n; i++) cout << R[i] << " ";
	// cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		memset(L, 0, sizeof L);
		memset(R, 0, sizeof R);
		memset(flag, 0, sizeof flag);
		string s; cin >> s;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')
				flag[i] = 0;
			else flag[i] = 1;
		}
		compute();

	}

}
