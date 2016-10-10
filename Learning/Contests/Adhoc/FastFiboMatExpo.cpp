#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<long long>
#define pi pair<long,long>
#define vii vector<pi>
using namespace std;
void print(std::vector<vi> ans) {
	for (auto i : ans) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
}
vector<vi> multiply(vector<vi> f, vector<vi> m) {
	vector<vi> res(2, vi(2L, 0L));
	for (size_t i = 0; i < f.size(); i++)
		for (size_t j = 0; j < m.size(); j++) {
			for (size_t k = 0; k < f.size(); k++)
				res[i][j] += f[i][k] * m[k][j];
		}
	return res;
}
vector<vi> raise(vector<vi> f, int n) {

	vector<vi> ans(2, vi(2, 0));
	for (int i = 0; i < 2; i++) ans[i][i] = 1;

	while (n) {
		if (n & 1){ ans = multiply(f, ans); print(ans);}
		f = multiply(f, f);
		n >>= 1;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	std::vector<vi> v{{1, 1}, {1, 0}};
	print(raise(v, 5));
}