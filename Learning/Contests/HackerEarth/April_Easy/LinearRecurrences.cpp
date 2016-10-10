#include <cstdio>
#include <cstring>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define vii vector<pi>
ll mod = 1000000007;
using namespace std;
ll mem[30][5][5], temp[5];
ll a, b, c, d, e, f, F0, F1, G0, G1, q;
ll H0, H1;
int i, j, k, l;

void init() {
	H0 = (e * F0 + f * G0 ) % mod;
	H1 = (e * F1  + f * G1 ) % mod;
	mem[0][0][0] = a, mem[0][0][3] = b, mem[0][1][0] = 1, mem[0][2][1] = d;
	mem[0][2][2] = c, mem[0][3][2] = 1;
	mem[0][4][0] = (e * a) % mod;
	mem[0][4][1] = (f * d) % mod;
	mem[0][4][2] = (f * c) % mod;
	mem[0][4][3] = (e * b) % mod;
	mem[0][4][4] = 1;

	for (i = 1; i < 30; i++) {
		for (j = 0; j < 5; j++)
			for (k = 0; k < 5; k++) {
				for (l = 0; l < 5; l++)
					mem[i][j][k] += mem[i - 1][j][l] * mem[i - 1][l][k];
				mem[i][j][k] %= mod;
			}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &F0, &F1, &G0, &G1);
	init();
	int q;
	scanf("%d", &q);
	ll H[2] = {H0, (H0 + H1) % mod};
	while (q--) {
		int n;
		scanf("%d", &n);
		if (n <= 1) printf("%lld\n", H[n]);
		else {
			n--;

			ll B[5] = {F1, F0, G1, G0, (H0 + H1) % mod};
			for (int i = 0; i < 30; i++)
				if (n & (1 << i)) {
					memset(temp, 0, sizeof temp);
					for (int j = 0; j < 5; j++) {
						for (int k = 0; k < 5; k++)
							temp[j] += mem[i][j][k] * B[k];
						temp[j] %= mod;
					}
					for (int l = 0; l < 5; l++) B[l] = temp[l];
				}
			printf("%lld\n", B[4]);
		}

	}

}

// #include <bits/stdc++.h>
// using namespace std;
// const long long int MOD = 1000000007;
// long long int F[2],G[2],H[2],A[30][5][5];
// void matmult(long long int ans[][5], long long int a[][5], long long int b[][5])
// {
// 	for (int i = 0; i < 5; ++i)
// 		for (int j = 0; j < 5; ++j)
// 		{
// 			ans[i][j] = 0;
// 			for (int k = 0; k < 5; ++k)
// 				ans[i][j]+=a[i][k]*b[k][j];
// 			ans[i][j]%=MOD;
// 		}
// }
// int main()
// {
// 	#ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
// 	long long int a,b,c,d,e,f;
// 	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
// 	scanf("%lld %lld", &F[0], &F[1]);
// 	scanf("%lld %lld", &G[0], &G[1]);
// 	// H actually stores syum of H tilong long that point
// 	H[0] = (e*F[0] + f*G[0])%MOD;
// 	H[1] = (e*F[1] + f*G[1] + H[0])%MOD;
// 	// create transition matrxi
// 	A[0][0][0] = a;	A[0][0][3] = b;
// 	A[0][1][0] = 1;
// 	A[0][2][1] = d;	A[0][2][2] = c;
// 	A[0][3][2] = 1;
// 	A[0][4][0] = e*a;	A[0][4][1] = f*d;	A[0][4][2] = f*c;	A[0][4][3] = e*b;	A[0][4][4] = 1;
// 	for (int i = 0; i < 5; ++i)
// 		A[0][4][i]%=MOD;
// 	// precompute powers of transition matrix
// 	for (int i = 1; i < 30; ++i)
// 		matmult(A[i],A[i-1],A[i-1]);
// 	int q;
// 	scanf("%d", &q);
// 	while(q--)
// 	{
// 		int n;
// 		scanf("%d", &n);
// 		if(n <= 1)
// 			printf("%lld\n", H[n]);
// 		else
// 		{
// 			n--;
// 			long long int ans[] = {F[1],F[0],G[1],G[0],H[1]};
// 			for (int i = 0; i < 30; ++i)
// 			{
// 				if(n & (1<<i))
// 				{
// 					long long int temp[] = {0,0,0,0,0};
// 					for (int j = 0; j < 5; ++j)
// 					{
// 						for (int k = 0; k < 5; ++k)
// 							temp[j]+=A[i][j][k]*ans[k];
// 						temp[j]%=MOD;
// 					}
// 					for (int j = 0; j < 5; ++j)
// 						ans[j] = temp[j];
// 				}
// 			}
// 			printf("%lld\n", ans[4]);
// 		}
// 	}
// 	return 0;
// }