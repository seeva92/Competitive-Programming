#include <bits/stdc++.h>
using namespace std;
struct Query {
	long num, period, total;
};
struct Compare {
	bool operator()(Query a, Query b) {
		if (a.total > b.total)
			return true;
		else if (a.total == b.total) {
			if (a.num >= b.num)
				return true;
		}
		return false;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	priority_queue<Query, vector<Query>, Compare> p;
	char str[10]; long num, period, k;
	while (scanf("%s", str), str[0] != '#') {
		scanf("%ld %ld", &num, &period);
		Query q; q.num = num; q.period = period; q.total = period;
		p.push(q);
	}
	scanf("%ld", &k);
	Query q;
	while (k > 0 && !p.empty()) {
		q = p.top();
		printf("%ld\n", q.num);
		p.pop();
		q.total += q.period;
		p.push(q); k--;
	}
}