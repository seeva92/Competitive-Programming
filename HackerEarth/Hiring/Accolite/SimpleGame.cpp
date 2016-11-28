#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, M;
ll A[MAX], B[MAX];
ll Atot = 0, Btot = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	// cin >> N >> M;
	// for (int i = 0; i < N; i++) cin >> A[i];
	// for (int i = 0; i < M; i++) cin >> B[i];
	// sort(A, A + N);
	// sort(B, B + M);
	// ll a, b;
	// for (int i = 0; i < N; i++) {
	// 	a = upper_bound(B, B + M, A[i] - 1) - B;
	// 	b = M - (upper_bound(B, B + M, A[i]) - B);
	// 	cout << a << " " << b << "\n";
	// 	Atot += (a * b);
	// }
	// for (int i = 0; i < M; i++) {
	// 	a = upper_bound(A, A + N, B[i] - 1) - A;
	// 	b = N - (upper_bound(A, A + N, B[i]) - A);
	// 	cout << a << " " << b << "\n";
	// 	Btot += (a * b);
	// }
	// // cout << Atot << " " << Btot << "\n";
	// if (Atot == Btot) cout << "Tie";
	// else if (Atot > Btot) cout << "Monk";
	// else cout << "!Monk";

	int arr[] = {1, 2, 3, 4};
	do {
		for (int i = 0; i < 4; i++) cout << arr[i] << " ";
		cout << '\n';
	} while (next_permutation(arr, arr + 4));
}
