#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int t;
	scanf("%d", &t);
	long long l, r, s, n, d;
	while (t--) {
		scanf("%lld %lld %lld", &l, &r, &s);
		n = (s * 2) / (l + r);
		printf("%lld\n", n);
		d = (r - l) / ((n - 3) - 2);
		printf("%lld %lld %lld", l - (2 * d), l - d, l);
		n = n - 3;
		while (n > 0) {
			l = l + d;
			printf(" %lld", l);
			n--;
		}
		printf("\n");
	}
}