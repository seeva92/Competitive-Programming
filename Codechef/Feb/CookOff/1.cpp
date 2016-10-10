#include <cstdio>
using namespace std;
int sum(int d, int n) {
	if (d == 1)
		return (n * (n + 1) / 2);
	return sum(d - 1, (n * (n + 1)) / 2);
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
// 	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
// #endif
	int t;
	int d, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &d, &n);
		printf("%d\n", sum(d, n));
	}

}