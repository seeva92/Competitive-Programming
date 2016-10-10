#include <cstdio>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	long long x = 2000000000;
	long long res = 0;
	for (long long i = 1; i < x; i++)
		res += i;
	printf("%lld\n",res);
}