#include <bits/stdc++.h>
#define vi vector<int>
#define SIZE 110
#define EPS 1e-9
using namespace std;
double fibo[110] = {0};
void generate() {
	fibo[1] = 1.0; fibo[2] = 2.0;
	for (int i = 3; i < SIZE; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
	double sum = 0.0;
	// for (int i = 1; i < SIZE; i++) {
	// 	printf("%.0f\n", fibo[i]);
	// 	sum += fibo[i];
	// }
	// printf("%.0f\n", sum);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	generate();
	char str1[SIZE], str2[SIZE];
	int l1, l2;
	while (scanf("%s %s", str1, str2) != EOF) {
		l1 = strlen(str1), l2 = strlen(str2);
		double s1 = 0.0, s2 = 0.0;
		for (int i = 0; i < l1; i++)
			s1 += (fibo[l1 - i] * (1.0 * (str1[i] - '0')));

		for (int i = 0; i < l2; i++)
			s1 += (fibo[l2 - i] * (1.0 * (str2[i] - '0')));

		int i;
		for (i = SIZE - 1; i >= 1; i--) {
			// printf("%.0f %.0f\n", fibo[i], s1);
			if (islessequal(fibo[i], s1))
				break;
		}
		printf("%f\n", s1);
		if (i >= 1) {
			s1 -= fibo[i];
			printf("1");
			bool flag = false;
			for (i = i - 1; i >= 1; i--) {
				if (!flag && isgreaterequal(s1 - fibo[i], 0.0)) {
					printf("1");
					s1 -= fibo[i];
				} else {
					printf("0");
				}
			}
		} else
			printf("0");

		printf("\n");
	}
}