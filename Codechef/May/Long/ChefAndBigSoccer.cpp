#include <iostream>
#include <cstdio>
#include <cstring>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;
int strength[1000];
int t, N, M, s;
int f[1007][1007];
// ll dogs[1007];
// void compute(int i, int dog) {
// 	if (i == M) {
// 		dogs[dog] = (dogs[dog] + 1) % mod;
// 		return;
// 	}
// 	if (1 <= dog - strength[i] && dog - strength[i] <= N)
// 		compute(i + 1, dog - strength[i]);
// 	if (1 <= dog + strength[i] && dog + strength[i] <= N)
// 		compute(i + 1, dog + strength[i]);

// }
int compute(int i, int j) {
	if (f[i][j] != -1) return f[i][j];
	if (j == 0) {
		return f[i][j] = i == s;
	} else {
		int result = 0;
		if (i - strength[j - 1] >= 0) result += compute(i - strength[j - 1], j - 1);
		if (i + strength[j - 1] < N) result += compute(i + strength[j - 1], j - 1);
		result = result % mod;
		return f[i][j] = result;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> N >> M >> s;
		s--;
		// memset(dogs, 0, sizeof dogs);
		memset(f, 0, sizeof f);
		for (int i = 0; i < M; i++) cin >> strength[i];
		// for (int i = 0; i < N; i++) {
		// 	cout << compute(i, M) << " ";
		// }
		// memset(f, 0, sizeof f);
		for (int j = 0; j <= M; j++)
			for (int i = 0; i < N; i++) {
				if (j == 0) {
					f[i][j] = i == s;
				}
				else {
					int result = 0;
					if (i - strength[j - 1] >= 0)result += f[i - strength[j - 1]][j - 1];
					if (i + strength[j - 1] < N) result += f[i + strength[j - 1]][j - 1];
					f[i][j] = result % mod;
				}
			}

		for (int i = 0; i < N; i++) cout << f[i][M] << " ";
		cout << endl;
	}

}
