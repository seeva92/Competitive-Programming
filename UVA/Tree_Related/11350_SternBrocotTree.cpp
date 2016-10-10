#include <bits/stdc++.h>
using namespace std;
int N, len; char str[100];
struct frac {
	long n, d; frac(long ni, long di) {n = ni; d = di;}
};
frac ct(1, 1); frac lt(0, 1); frac rt(1, 0);
void compute(int i) {
	if (i == len) {
		printf("%ld/%ld\n", ct.n, ct.d); return;
	}
	if (str[i] == 'R') {
		lt.n = ct.n; lt.d = ct.d;
		ct.n += rt.n; ct.d += rt.d;
	} else {
		rt.n = ct.n; rt.d = ct.d;
		ct.n += lt.n; ct.d += lt.d;
	}
	compute(i + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	scanf("%d", &N);
	while (N--) {
		scanf("%s", &str); len = strlen(str);
		ct.n = ct.d = 1; lt.n = 0, lt.d = 1; rt.n = 1, rt.d = 0;
		compute(0);
	}
}