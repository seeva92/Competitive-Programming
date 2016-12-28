#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class SRMCards {
public:
	int maxTurns(vector<int> cards) {
		sort(cards.begin(), cards.end());
		int len = cards.size();
		int res = 0;
		for (int i = 0; i < len; i++) {
			if (i + 1 < len && cards[i] + 1 == cards[i + 1]) {
				i++;
				res++;
			} else res++;
		}
		return res;
	}
};
#include <bits/stdc++.h>

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	SRMCards s; cout << s.maxTurns({491, 492, 495, 497, 498, 499});
}
