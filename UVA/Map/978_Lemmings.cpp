#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, b, sg, sb, x;
	int i, j, k;
	priority_queue<int> green, blue;
	priority_queue<int> wong, wonb;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &b, &sg, &sb);
		for (j = 0; j < sg; j++) {
			scanf("%d", &x); green.push(x);
		}
		for (j = 0; j < sb; j++) {
			scanf("%d", &x); blue.push(x);
		}
		while (!(green.empty() || (blue.empty()))) {
			for (k = 0; k < b && (!green.empty()) && (!blue.empty()); k++) {
				if (green.top() < blue.top())
					wonb.push(blue.top() - green.top());
				else if (green.top() > blue.top())
					wong.push(green.top() - blue.top());
				blue.pop(); green.pop();
			}
			while (!wong.empty()) {
				green.push(wong.top()); wong.pop();
			}
			while (!wonb.empty()) {
				blue.push(wonb.top()); wonb.pop();
			}
		}

		if (green.empty() && blue.empty())
			printf("green and blue died\n");
		else if (!green.empty()) {
			printf("green wins\n");
			while (!green.empty()) {
				printf("%d\n", green.top()); green.pop();
			}
		} else {
			printf("blue wins\n");
			while (!blue.empty()) {
				printf("%d\n", blue.top()); blue.pop();
			}
		}

		if(i+1!=n)
			printf("\n");
	}
}



