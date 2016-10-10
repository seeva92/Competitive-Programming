#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) (x<<1)+1
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int t, D, I, i, j, pos, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &D, &I);
		n = pow(2, D);
		i = 1; I--;
		while (i < n) {
			pos = i;
			if (I % 2) {i = right(i);}
			else i = left(i);
			I /= 2;
		}
		printf("%d\n", pos);
	}

}