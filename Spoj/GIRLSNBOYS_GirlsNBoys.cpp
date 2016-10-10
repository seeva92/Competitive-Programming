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
	int b, g;
	while (scanf("%d %d", &b, &g) && (b != -1 && g != -1)) {
		if (b == 0 && g == 0) printf("0");
		else if (b == 0) printf("%d", g);
		else if (g == 0) printf("%d", b);
		else if (b == g) printf("1");
		else {
			int mx = max(b, g), my = min(b, g);
			if (mx % (my + 1) == 0) printf("%d", (mx / (my + 1)));
			else printf("%d", (mx / (my + 1)) + 1);
		}
		printf("\n");
	}
}