#include <cstdio>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
const long long MOD = 1000007;
using namespace std;
long long arr[1000007];
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif

	arr[1] = 2;
	// for (int i = 2; i < 1000007; i++) arr[i] = (arr[i - 1] % MOD + ((3 * i) - 1) % MOD) % MOD;
	// for (int i = 1; i < 1000007; i++) printf("%lld\n", arr[i]);
	int t;
	long long a = 2, d = 3;
	long long n;
	scanf("%d", &t);

	while (t--) {
		scanf("%lld", &n);
		n = (n*(2*a+(n-1)*d))/2;
		n%=MOD;
		printf("%lld\n",n);
		
		// printf("%lld\n", arr[n]);
	}

}