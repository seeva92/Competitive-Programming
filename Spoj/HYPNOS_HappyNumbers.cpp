#include <cstdio>
#include <climits>
#include <cmath>
#include <unordered_map>
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
	int N;
	scanf("%d", &N);
	int temp = N;
	int count = 0;
	unordered_map<int, bool> mp;
	do {
		int res = 0;
		while (N > 0) {
			res += pow((N % 10), 2);
			N /= 10;
		}
		N = res;
		if (!mp[N]) mp[N] = 1; else break;

		count++;
	} while ((N != 1));
	if (N != 1) printf("-1\n"); else printf("%d\n", count);
}