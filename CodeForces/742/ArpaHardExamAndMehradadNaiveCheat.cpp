#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class ArpaHardExamAndMehradadNaiveCheat
{
	int n;
public:
	void solve() {
		cin >> n;
		int arr[] = {8, 4, 2, 6};
		if (n == 0) cout << 1;
		else {
			n--;
			cout << arr[n % 4];
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ArpaHardExamAndMehradadNaiveCheat a; a.solve();
}
