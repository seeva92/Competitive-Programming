#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
class LCMGCD {
public:
	vector<int> res;
	ll gcd(ll a, ll b) {
		if (b == 0) return a;
		return gcd(b, a % b);
	}
	ll lcm(ll a, ll b) {
		return (a * b) / gcd(a, b);
	}
	ll T;
	int size;
	bool compute(int i, ll val) {
		if (i == size) {
			if (T == val) return true;
			else return false;
		}
		bool l = compute(i + 1, gcd(val, res[i]));
		bool r = compute(i + 1, lcm(val, res[i]));
		return l || r;
	}
	string isPossible(vector<int> x, int t) {
		if (int(x.size()) == 1) return "Impossible";
		// T = t;
		// size = int(x.size());
		// for (auto it : x) res.push_back(it);
		// for (int i = 0; i < size; i++)
		// 	for (int j = 0; j < size; j++) {
		// 		if (i == j) continue;
		// 		bool l = compute(2, gcd(res[i], res[j]));
		// 		bool r = compute(2, lcm(res[i], res[j]));
		// 		if (l || r) return "Possible";
		// 	}
		vector<int> tmp;
		for (int i = 1; i < int(x.size()); i++) {
			sort(x.begin(), x.end());
			if(x[0])
			for (int j = 2; j < (int)x.size(); j++)
				tmp.push_back(x[j]);
			x = tmp;
		}
		return "Impossible";
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	
}

