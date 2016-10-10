#include <bits/stdc++.h>
using namespace std;

int n, len, trees, acorns; char p[60];
bitset<26> edge_exist, visited;
vector<int> temp; vector<pair<int, int>> edges;
vector<vector<int>> graph(26);
bool compute(int i, int parent) {
	vector<int> v = graph[i];
	visited[i] = 1;
	for (auto it : v) {
		if (!visited[it]) {
			if (compute(it, i)) return true;
		} else if (it != parent) return true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	scanf("%d", &n);
	while (n--) {
		edge_exist.reset(); visited.reset(); edges.clear(); graph.assign(26, std::vector<int>());
		trees = acorns = 0;
		while (scanf("%s", &p), p[0] != '*') {
			edges.push_back(make_pair(p[1] - 'A', p[3] - 'A'));
		}
		scanf("%s", &p); len = strlen(p);
		for (int i = 0; i < len; i++) if ('A' <= p[i] && p[i] <= 'Z') edge_exist[p[i] - 'A'] = 1;
		for (auto i : edges) {
			graph[i.first].push_back(i.second);
			graph[i.second].push_back(i.first);
		}
		for (int i = 0; i < 26; i++) {
			if (edge_exist[i] && !visited[i]) {
				if ((int)graph[i].size() == 0) acorns++;
				else if (!compute(i, -1)) trees++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}
}