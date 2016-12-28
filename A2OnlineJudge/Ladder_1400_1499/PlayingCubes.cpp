#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
int fst[2 * MAX], snd[2 * MAX];
class PlayingCubes
{
	int n, m;
public:
	pair<int, int> process(bool flag) {
		int i = 0, p = 0, v = 0;
		int nn = n, mm = m;
		int turn = 1;
		if (flag) {
			fst[i++] = 0; n--;
		} else {
			fst[i++] = 1; m--;
		}
		while (n || m) {
			if (turn) {
				if (fst[i - 1] == 0) {
					if (m > 0) { fst[i++] = 1; m--; v++; }
					else if (n > 0) { fst[i++] = 0; n--; p++; }
				} else {
					if (n > 0) { fst[i++] = 0; n--; v++; }
					else if (m > 0) { fst[i++] = 1; m--; p++; }
				}
				turn = 0;
			} else {
				if (fst[i - 1] == 0) {
					if (n > 0) { fst[i++] = 0; n--; p++; }
					else if (m > 0) { fst[i++] = 1; m--; v++; }
				} else {
					if (m > 0) { fst[i++] = 1; m--; p++; }
					else if (n > 0) { fst[i++] = 0; n--; v++; }
				}
				turn = 1;
			}
		}
		n = nn; m = mm;
		return {p, v};
	}
	void compute() {
		pair<int, int> f = process(true);
		pair<int, int> s = process(false);
		// cout << f.first << " " << f.second << '\n';
		// cout << s.first << " " << s.second << '\n';
		if (f.first > s.first) cout << f.first << " " << f.second;
		else if (f.first < s.first) cout << s.first << " " << s.second;
		else {
			cout << f.first << " ";
			if (f.second > s.second) cout << f.second << '\n';
			else cout << s.second << '\n';
		}
	}
	void solve() {
		cin >> n >> m;
		compute();
	}


};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	PlayingCubes p; p.solve();
}
