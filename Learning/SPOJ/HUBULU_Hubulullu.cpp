#include <cstdio>
#include <cmath>
#include <string>
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
	string str[] = {"Airborne wins.", "Pagfloyd wins."};
	scanf("%d", &t);
	while (t--) {
		long long N; int p;
		scanf("%lld %d", &N, &p);
		printf("%s\n", str[p].c_str());
	}
}