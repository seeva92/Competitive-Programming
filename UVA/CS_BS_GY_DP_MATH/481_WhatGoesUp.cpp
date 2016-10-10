#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define sz 100000
using namespace std;
void print(int x, int v [], int p []) {
	int end = x;
	stack<int> s;
	for (; p[x] >= 0; x = p[x]) s.push(v[x]);
	s.push(v[x]);
	while (!s.empty()) {
		printf("%d\n", s.top()); s.pop();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int v[sz], p[sz], lis[sz], lis_i[sz];
	int x, a = 0;
	while (scanf("%d", &x) != EOF) {v[a++] = x;}



	int li = 0, li_end = 0;
	for (size_t i = 0; i < a; i++) {
		int pos = lower_bound(lis, lis + li, v[i]) - lis;
		lis[pos] = v[i]; lis_i[pos] = i;
		p[i] = pos ? lis_i[pos - 1] : -1;
		if (pos + 1 > li) {
			li = pos + 1;
			li_end = i;
		}
		
	}

	printf("%d\n-\n", li); print(li_end, v, p);

}