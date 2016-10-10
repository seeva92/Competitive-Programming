#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define RANGE floor(int(sqrt(INT_MAX))) + 100
using namespace std;
vi primes;
const int n = RANGE;
bitset<n> flags;
void compute() {
	flags.set();
	flags[0] = flags[1] = 0;
	for (int i = 2; i * i < n && i * i >= 0; i++)
		for (int j = i * 2; j < n && j >= 0; j += i)
			flags[j] = 0;
	for (int i = 2; i < n; i++)
		if (flags[i]) primes.push_back(i);
}
inline bool is_prime(int x) {
	if (x < n) return flags[x];
	int len = int(primes.size());
	for (int i = 0; i < len && primes[i] < x; i++)
		if (!(x % primes[i])) return false;
	return true;
}
void segsieve(int l, int u) {
	int len;
	len = (int)primes.size();
	vi segprimes;
	int ll, lu, hl, hu; int ldiff = INT_MAX, hdiff = INT_MIN;
	for (int i = l; i <= u && i >= 0; i++) {
		if (is_prime(i))
			segprimes.push_back(i);
	}
	for (int i = 1; i < int(segprimes.size()); i++) {
		if (segprimes[i] - segprimes[i - 1] > hdiff) {
			hdiff = segprimes[i] - segprimes[i - 1]; hl = segprimes[i - 1]; hu = segprimes[i];
		}
		if (segprimes[i] - segprimes[i - 1] < ldiff) {
			ldiff = segprimes[i] - segprimes[i - 1]; ll = segprimes[i - 1]; lu = segprimes[i];
		}
	}
	if (ldiff == INT_MAX && hdiff == INT_MIN)
		printf("There are no adjacent primes.\n");
	else
		printf("%d,%d are closest, %d,%d are most distant.\n", ll, lu, hl, hu);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int l, u;
	compute();
	while (scanf("%d %d", &l, &u) != EOF) {
		segsieve(l, u);
	}
}