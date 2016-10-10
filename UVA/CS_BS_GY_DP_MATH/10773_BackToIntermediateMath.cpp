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
	int d, u, v;
	int  t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &d, &v, &u);
		if (u == 0 || v == 0 || u<=v)
			printf("Case %d: can't determine\n", cas++);
		else {
			double fast = double(d)/double(u);// printf("%f\n",fast);
			double shrt = double(d)/double(sqrt(u*u-v*v)); //printf("%f\n",shrt);
			printf("Case %d: %.3f\n", cas++, abs(fast - shrt));
		}
	}

}