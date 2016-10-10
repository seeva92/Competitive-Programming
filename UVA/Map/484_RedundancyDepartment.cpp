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
	int n;
	map<int, int> count;
	map<int, int> pos;

	int i = 0;
	while (scanf("%d", &n) != EOF) {
		count[n] = count[n] + 1;
		if (count[n] == 1)
			pos[i] = n;
		++i;
	}
	for (auto it : pos) {
		printf("%d %d\n", it.second, count[it.second]);
	}
}


