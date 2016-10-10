#include <bits/stdc++.h>
using namespace std;
char line[10000];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, p, i, x, size, curr = 0;
	scanf("%d", &t);
	while (t--) {
		queue<int> mn; size = INT_MAX;
		scanf("%d", &p); gets(line);
		for (i = 1; i <= p; i++) {
			gets(line); char *ptr = strtok(line, " ");
			curr = 0;
			while (ptr) {curr++; ptr = strtok(NULL, " ");}
			if (size > curr) {
				while (!mn.empty()) mn.pop();
				mn.push(i); size = curr;
			}
			else if (size == curr) {mn.push(i);}
		}
		for (i = mn.size(); i > 0; i--) {
			printf("%d", mn.front()); mn.pop();
			if (i != 1) printf(" ");
		}
		printf("\n");
	}
}