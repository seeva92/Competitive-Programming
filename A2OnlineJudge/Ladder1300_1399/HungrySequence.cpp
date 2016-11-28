#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e7 + 7;
using namespace std;
typedef vector<int> vi;
bitset<MAX> bs;
int N;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	int len = sqrt(MAX);
	for (int i = 2; i <= len; i++)
		if (bs[i]) {
			for (int j = i * i; j < MAX; j += i) {
				bs[j] = 0;
			}
		}
	for (int i = 0; i < MAX && N > 0; i++)
		if (bs[i]) {
			cout << i << " "; N--;
		}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	sieve();
}
