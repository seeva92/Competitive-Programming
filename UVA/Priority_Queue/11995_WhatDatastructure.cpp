#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif

	int n;
	int i, x;
	while (scanf("%d", &n) != EOF) {
		stack<int> stk;
		queue<int> que;
		priority_queue<int> pq;
		bool s = 1, q = 1, p = 1;
		while (n--) {
			scanf("%d %d", &i, &x);
			if (i == 1) {
				if (s)
					stk.push(x);
				if (q)
					que.push(x);
				if (p)
					pq.push(x);
			} else {
				if (s) {
					if (!stk.empty() && stk.top() == x)
						stk.pop();
					else
						s = 0;
				}
				if (q) {
					if (!que.empty() && que.front() == x)
						que.pop();
					else
						q = 0;
				}
				if (p) {
					if (!pq.empty() && pq.top() == x)
						pq.pop();
					else
						p = 0;
				}
			}
		}
		if ((s && q && p) || (s && q) || (q && p) || (s && p))
			printf("not sure\n");
		else if (s)
			printf("stack\n");
		else if (q)
			printf("queue\n");
		else if (p)
			printf("priority queue\n");
		else
			printf("impossible\n");

	}
}