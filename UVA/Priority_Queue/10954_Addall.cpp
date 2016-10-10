#include<bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	long n, x; long total, cost;
	while (scanf("%ld", &n) && n) {
		total = 0L; cost = 0L;
		priority_queue<long, vector<long>, greater<long>> p;
		while (n--) {
			scanf("%ld", &x);
			p.push(x);
		}
		cost = total;
		while ((int)p.size() > 1) {
			total = p.top(); p.pop();
			total += p.top(); p.pop();
			cost += total;
			p.push(total);
		}
		printf("%ld\n", cost);
	}
}


