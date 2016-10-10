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
	int n, curr = 0, res = INT_MIN, x;
	while (scanf("%d", &n) != EOF && n != 0) {
		curr = 0; res = INT_MIN;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			curr += x;
			res = max(res, curr);
			if (curr < 0) curr = 0;
		}
		res = max(res, curr);
		if (res <= 0) printf("Losing streak.\n");
		else printf("The maximum winning streak is %d.\n", res);
	}

}