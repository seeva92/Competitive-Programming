#include <iostream>
#include <cstring>
#include <cmath>
#define left(x) x<<1
#define right(x) (x<<1)+1
const long long M = 1299709;
long long sum[25];
long long arr[6000100];
void build(int idx, int curr, int h, int & incr) {
	if (curr > h) return;
	if (curr == h) {
		arr[idx] = incr; incr++;
		sum[curr] = (sum[curr] + arr[idx]) % M;
		return;
	}
	build(left(idx), curr + 1, h, incr);
	build(right(idx), curr + 1, h, incr);
	arr[idx] = (arr[left(idx)] * arr[right(idx)]) % M;
	sum[curr] = (sum[curr] + arr[idx]) % M;

}
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int l, q, x, y, incr = 1;
	memset(arr, -1, sizeof arr);
	memset(sum, 0, sizeof sum);
	cin >> l >> q;
	build(1, 1, l, incr);
	// int n = pow(2, l + 1) - 1;
	// for (int i = 1; i <= n; i++)
	// 	cout << arr[i] << " ";
	// cout << endl;
	while (q--) {
		cin >> x >> y;
		long long total = 0;
		for (int i = x; i <= y; i++) {
			total = (total + sum[i]) % M;
		}
		cout << total << endl;
	}

}