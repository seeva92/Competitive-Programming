#include <iostream>
#include <cstring>
using namespace std;
int state[5][1000010];
int solve(int i, int j) {
	if (i == 1 && j == 1) return 0;
	if (state[i][j] != -1) return state[i][j];
	state[i][j] = 0;
	for (int k = 1; k <= 2; k++)
		if (j - k > 0)
			state[i][j] |= (1 - solve(i, j - k));
	for (int k = 1; k <= 3; k++)
		if (i - k > 0)
			state[i][j] |= (1 - solve(i - k, j));
	return state[i][j];

}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	memset(state, -1, sizeof state);

	for (int i = 1; i <= 4; i++)
		for (int j = 1; j < 1000010; j++)
			state[i][j] = solve(i, j);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (state[(n - 1) % 4 + 1][m])
			cout << "Tuzik\n";
		else
			cout << "Vanya\n";
	}
}
