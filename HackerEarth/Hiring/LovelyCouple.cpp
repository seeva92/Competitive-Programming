#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int size = 1000000;
bitset<size> sieve;
vector<int> primes;
void generate() {
	sieve.set();
	sieve[0] = sieve[1] = 0;
	// cout << sieve[2];
	for (long i = 2; i < size; i++)
		if (sieve[i]) {
			for (long j = i * i; j < size; j += i ) 	sieve[j] = 0;
			primes.push_back(i);
		}

}
void compute(int val) {
	int count = 0;
	int i = 0; int prime = primes[i];
	bool flag = false;
	for (int i = 0; (i < int(primes.size())) && (primes[i] * primes[i] <= val); i++) {
		flag = false;
		while (val % primes[i] == 0) { val /= primes[i]; flag = true;}
		if (flag) count++;
	}
	if (val != 1) count++;
	if (sieve[count]) printf("Yes\n");
	else printf("No\n");
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	generate();
	int t;
	int a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		compute(lcm(a, b));
	}

}