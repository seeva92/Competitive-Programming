#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	char arr[5];
	int count[3] = {0};
	int n; cin >> n;
	while (n--) {
		cin >> arr; //cout << arr << endl;
		if (arr[0] == '1' && arr[2] == '4') count[0]++;
		else if (arr[0] == '1' && arr[2] == '2') count[1]++;
		else count[2]++;
	}
	int total = 1;
	total += count[2];
	if (count[2] <= count[0]) count[0] -= count[2];
	else count[0] = 0;

	total += (count[1] / 2) + (count[1] % 2 != 0 ? 1 : 0);
	if (count[0] > 0 && count[1] % 2 != 0) {
		if (count[1] % 2 <= count[0]) count[0] -= count[1] % 2;
		else count[0] = 0;
	}
	total += (count[0] / 4) + (count[0] % 4 != 0 ? 1 : 0);
	cout << total << endl;
}