#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
vi v[10010];
bool visited[10010];

int dfs(int i, int & longest) {
	visited[i] = true;
	std::vector<int> curr;
	for (auto it : v[i]) {
		if (!visited[it])
			curr.push_back(dfs(it, longest));
	}
	sort(all(curr), greater<int>());

	int lt = int(curr.size()) > 0 ? curr[0] : 0;
	int rt = int(curr.size()) > 1 ? curr[1] : 0;
	if (longest < (lt + rt + 1))
		longest = lt + rt + 1;
	// printf("%d %d %d\n", lt, rt, lt + rt + 1 );
	// printf("%d %d %d\n", i, lt + rt + 1, longest);
	return max(lt, rt) + 1;
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int n, s, d;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &s, &d);	v[s].push_back(d);
		v[d].push_back(s);
	}
	int path = 0;
	int count = 0;
	// for (int i = 1; i <= n; i++) {
	memset(visited, 0, sizeof visited); count = 0;
	dfs(1, count);
	// printf("%d %d\n", 1, count);
	// if (path < count) path = count;
	// }
	printf("%d\n", count - 1);
}