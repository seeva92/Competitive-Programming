#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
using namespace std;
long long n;
int arr[1000007];
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	long long total = 0;\
	for (long long i = 0, layer = 1; i < n; layer++) {
		if (layer * layer < arr[i])
			total += layer * layer;
		else {
			total += (layer * layer) - arr[i]; i++;
		}
	}

	cout << total;
}