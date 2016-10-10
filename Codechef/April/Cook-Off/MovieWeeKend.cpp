#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
struct node {
	int L, R, LR, i;
};
node arr[110];
bool compare(node a, node b) {
	if (b.LR < a.LR) return true;
	else if (b.LR == a.LR) {
		if (b.R < a.R) return true;
		else if (b.R == a.R) {
			if (a.i < b.i) return true;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t, n, l, r;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i].L;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].R; arr[i].LR = arr[i].L * arr[i].R; arr[i].i  = i;
		}
		sort(arr, arr + n, compare);
		cout<<arr[0].i+1<<endl;
	}

}