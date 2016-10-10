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
	int n, r, x = 1;
	while (scanf("%d %d", &n, &r) != EOF && n || r) {
		printf("Case %d: ", x++);
		if (n > (r + (r * 26)))
			printf("impossible\n");
		else {
			if (n % r == 0) printf("%d\n", (n / r) - 1);
			else printf("%d\n", n / r );
		}
	}

}