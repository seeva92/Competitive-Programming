#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	// ios::sync_with_stdio(false); cin.tie(0);
	int a, b, ta, tb, sh, sm;
	scanf("%d %d %d %d", &a, &ta, &b, &tb);
	scanf("%d:%d", &sh, &sm);
	int start = sh * 60 + sm;
	int end = sh * 60 + sm + ta;
	int count = 0;
	for (int i = (5 * 60); i < (24 * 60); i += b) {
		if (((i + tb) <= start) || (end <= (i))) continue;
		count++;
	}
	cout << count << endl;
}