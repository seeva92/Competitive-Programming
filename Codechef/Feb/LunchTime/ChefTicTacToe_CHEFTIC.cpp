#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
char arr[25][25];
int n, k;
bool isWinning(int i, int j) {
	int counter = 0;
	arr[i][j] = 'X';
	// Horizontal
	for (int a = j; a < n && counter < k; a++)
			if (arr[i][a] == 'X') counter++; else break;
	for (int a = j - 1; a >= 0 && counter < k; a--)
			if (arr[i][a] == 'X') counter++; else break;
	if (counter == k) return true; else counter = 0;

	// Vertical
	for (int a = i; a < n && counter < k ; a++)
			if (arr[a][j] == 'X') counter++; else break;
	for (int a = i - 1; a >= 0 && counter < k; a--)
			if (arr[a][j] == 'X') counter++; else break;
	if (counter == k) return true; else counter = 0;

	//Right Diagonal
	for (int a = i, b = j; a < n && b < n && counter < k; a++, b++)
			if (arr[a][b] == 'X') counter++; else break;
	for (int a = i - 1, b = j - 1; a >= 0 && b >= 0 && counter < k; a--, b--)
			if (arr[a][b] == 'X') counter++; else break;
	if (counter == k) return true; else counter = 0;

	//Left Diagonal
	for (int a = i, b = j; a < n && b >= 0 && counter < k; a++, b--)
			if (arr[a][b] == 'X') counter++; else break;
	for (int a = i - 1, b = j + 1; a >= 0 && b < n && counter < k; a--, b++)
			if (arr[a][b] == 'X') counter++; else break;
	if (counter == k) return true; else counter = 0;

	arr[i][j] = '.';
	return false;
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int t;
	bool flag = true;
	string str;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		flag = true;
		fill(&arr[0][0], &arr[0][0] + sizeof(arr), '.');
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		// for (int i = 0; i < n; i++, cout << endl)
		// 	for (int j = 0; j < n; j++)
		// 		cout << arr[i][j];
		for (int i = 0; i < n && flag; i++)
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != '.')
					continue;
				else if (isWinning(i, j)) {
					cout << "YES" << endl; flag = false; break;
				}

			}
		if (flag)
			cout << "NO" << endl;
	}

}
