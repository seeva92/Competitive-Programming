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
	int t; char mat[12][100], line[100];
	scanf("%d", &t); gets(line);
	while (t--) {
		for (int i = 0; i < 10; i++) scanf("%s", &mat[i]);
		int len = strlen(mat[0]) - 1;
		for (int j = 1; j < len; j++) {
			for (int k = 32; k < 128; k++) {
				int i;
				for (i = 1; i <= 8; i++) {
					if (mat[i][j] == '\\') {
						if (k / (1 << (i - 1)) % 2 == 0) break;
					} else {
						if (k / (1 << (i - 1)) % 2 == 1) break;
					}
				}
				if (i == 9) printf("%c", k);
			}
		}
		printf("\n");
	}
}