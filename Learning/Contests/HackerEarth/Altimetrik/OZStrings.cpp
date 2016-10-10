#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int f(int o, int z, int n) {
	if (n == 0) return 0;
	if (o == 0 && z == 0) return 0;
	int to = 0, tz = 0;
	for (int i = 0; i < str[n - 1].size(); i++)
			if (str[n - 1][i] == 'O') to++; else tz++;
	if (to < o || tz < z) return f(o, z, n - 1);

	return max(f(o, z, n - 1), 1 + f(o - to, z - tz, n - 1));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);


}