#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int arr[20007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	// ios::sync_with_stdio(false); cin.tie(0);
	int t; scanf("%d", &t);
	for (int x = 1; x <= t; x++) {
		int n, k; scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", arr + i);
		if (k == 1) { printf("0\n"); continue;}
		sort(arr, arr + n);
		int diff = INT_MAX;
		for (int i = 0; i < (n - k + 1); i++)
			if (diff > (arr[i + k - 1] - arr[i])) diff = arr[i + k - 1] - arr[i];
		printf("%d\n", diff);
	}

}