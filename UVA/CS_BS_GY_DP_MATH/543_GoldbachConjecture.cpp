#include <bits/stdc++.h>
#define vi vector<int>
#define SIZE 1000500
using namespace std;
bitset<SIZE> primes;
vector<int> p;
void generate() {
	primes.set();
	for (int i = 2; i < SIZE; i++) {
		if (primes[i]) {
			for (int j = 2; (j * i) < SIZE; j++) primes[j * i] = 0;
		}
	}
	for (int i = 2; i < SIZE; i++)
		if (primes[i]) p.push_back(i);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n;
	generate();
	while (scanf("%d", &n) && n != 0) {
		int val;
		vector<int>::iterator check;
		bool found = false;
		for (auto it : p) {
			check = lower_bound(p.begin(), p.end(), n - it);
			if (check != p.end() && *check + it == n) {
				printf("%d = %d + %d\n", n, it, *check); found = true; break;
			}
		}
		if (!found)
			printf("Goldbach's conjecture is wrong.\n");
	}

}