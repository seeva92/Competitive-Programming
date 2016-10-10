#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	long long int arr[51] = {0, 1, 2, 3};
	for (int i = 4; i < 51; i++) arr[i] = arr[i - 1] + arr[i - 2];
	int x;
	while (scanf("%d", &x) != EOF && x != 0) {
		printf("%lld\n", arr[x]);
	}
}