#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, an, k, d, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &an); int poly[an + 1];
		for (i = 0; i <= an; i++) scanf("%d", &poly[i]);
		scanf("%d %d", &d, &k);
		int terms = 0;
		for (i = 1; true ; i++) {terms += i * d; if (terms >= k) break;} //printf("%d %d\n", terms, i);
		long total = poly[0], n = i, power = 1;
		for (i = 1; i <= an; i++) {
			total += (poly[i] * power * n);
			power *= n;
		}
		printf("%ld\n", total);
	}

}