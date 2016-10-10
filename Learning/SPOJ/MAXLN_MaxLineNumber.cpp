#include <cstdio>
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
	int t;
	long long r;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%lld", &r);
		printf("Case %d: %lld.25\n", i, 4 * r * r);
	}
}