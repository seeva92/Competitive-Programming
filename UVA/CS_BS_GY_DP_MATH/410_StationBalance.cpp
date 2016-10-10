#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int c, s, i, j, x = 1;
	while (scanf("%d %d", &c, &s) != EOF) {
		vi spec(s); double total = 0.0, avg = 0.0;
		for (i = 0; i < s; i++) { scanf("%d", &spec[i]); total += double(spec[i]);}
		avg = total / double(c);
		// printf("%f\n", avg);
		for (i = 0; i < (2 * c - s); i++) spec.push_back(0);
		sort(spec.begin(), spec.end());
		printf("Set #%d\n", x++); total = 0.0;
		for (i = 0, j = int(spec.size()) - 1; i < j; i++, j--) {
			printf("%2d:", i);
			if (spec[i]) printf(" %d", spec[i]);
			if (spec[j]) printf(" %d", spec[j]);
			total += abs(double(spec[i] + spec[j]) - avg);
			printf("\n");
		}
		printf("IMBALANCE = %.5f\n\n", total);
	}

}