#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
long long arr[91];
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	arr[1] = 1, arr[2] = 2;
	for (int i = 3; i < 91; i++) arr[i] = arr[i - 1] + arr[i - 2];
	long long x, total;
	while (scanf("%lld", &x) != EOF) {
		total = 0;
		vector<pair<int, long>> v;
		for (int i = 90; i >= 1; i--)
			if (total + arr[i] <= x) {
				v.push_back(mp(i, arr[i])); total += arr[i]; --i;
			}
		printf("%lld\n", x);
		for (size_t i = 0; i < v.size(); i++) {
			printf("%d ", v[i].first);
		} printf("\n");
		for (size_t i = 0; i < v.size(); i++) {
			printf("%lld ", v[i].second);
		} printf("\n"); printf("\n");

	}


}