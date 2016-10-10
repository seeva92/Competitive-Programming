#include <cstdio>
#include <algorithm>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
long long arr[1000001];
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	arr[1] = 1;
	for (long long i = 2; i < 1000001; i++) arr[i] = arr[i - 1] + (6 * (i - 1));	
	long long x;
	while (scanf("%lld", &x) & x != -1) {
		if (binary_search(arr, arr + 1000001, x)) printf("Y\n");
		else printf("N\n");
	}
}