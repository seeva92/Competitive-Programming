#include <cstdio>
#include <cstring>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define ll long long
#define vii vector<pi>
const ll mod = 1000000007;
using namespace std;
ll a, b, c, d, e, f;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	int q;
	scanf("%d", &q);
	while (q--) {
		ll n;
		scanf("%lld", &n);
		if (n == 0) printf("0\n");
		else {
			printf("%lld\n", (f + (((((n - 1)*f) % mod)*d))) % mod);
		}
	}
}
