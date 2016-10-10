#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define SIZE 2000050
using namespace std;
vi v(SIZE, 0);
char line[50];
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	while (gets(line)) {
		int y, n; sscanf(line, "%d", &y);
		gets(line); sscanf(line, "%d", &n);
		fill(all(v), 0);
		vi arr(n, 0);
		for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); v[arr[i]]++;}
		for (int i = 1; i < SIZE; i++) v[i] += v[i - 1];
		int f, l, c = INT_MIN;
		for (int i = 0; i < n; i++) {
			if ((v[arr[i] + y - 1] - v[arr[i] - 1]) > c) {
				c = v[arr[i] + y - 1] - v[arr[i] - 1]; f = arr[i];
				vi::iterator it = lower_bound(all(arr), f + y - 1);
				if (it == arr.end() || (*it) > (f + y - 1)) --it;
				l = *it;
			}
		}
		gets(line);  gets(line);
		printf("%d %d %d\n", c, f, l );
	}
}