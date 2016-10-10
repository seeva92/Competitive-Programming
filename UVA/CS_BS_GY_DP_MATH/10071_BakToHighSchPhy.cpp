#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	long v, t;
	while (scanf("%ld %ld", &v, &t) != EOF) printf("%ld\n", v * (2 * t));
}