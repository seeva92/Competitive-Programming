#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 100100
bool rep[MAX];
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
// 	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
// #endif
	int n, x;
	memset(rep, 0, sizeof rep);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);	rep[x] = 1;
	}
	for (int i = 1; i <= n; i++) if (rep[i] == 0) printf("%d ", i);
}