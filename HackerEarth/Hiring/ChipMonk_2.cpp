#include <cstring>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int arr[20];
int t, n;
int main() {
// #ifndef ONLINE_JUDGE
	// freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	// freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
// #endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		long long P = INT_MIN;
		int length = 0, count = (pow(2, n) - 1), tmp;;


		while (count)
		{
			tmp = count;
			vector<int> v;
			for (int i = 0; i < n; i++)
			{
				if (tmp & 1)
					v.push_back(arr[i]);
				tmp >>= 1;
			}
			if (int(v.size()) > 0) {
				int xoru = v[0], andu = v[0];
				for (size_t i = 1; i < v.size(); i++) {
					xoru ^= v[i];
					andu &= v[i];
				}
				if ((xoru | andu) > P) {
					P = xoru | andu;
					length = int(v.size());
				} else if (((xoru | andu) == P) && (length < int(v.size())))
					length = int(v.size());
			}
			count--;
		}
		printf("%ld %d\n", P, length);
	}
}