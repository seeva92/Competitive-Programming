#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
pair<int, int> oddpair[MAX], evenpair[MAX];
set<int> taken;
int oddIndex = 1, evenIndex = 2;
class NumbersExchange
{
	map<int, int> odd, even;
	map<int, vector<int>> odditems, evenitems;
	deque<pair<int, int>> oddqueue, evenqueue;
	int n, m;
	int distodd = 0, disteven = 0;
public:
	inline int getNextOdd() {
		while (oddIndex < m) {
			if (taken.find(oddIndex) == taken.end()) return oddIndex;
			oddIndex += 2;
		}
		return -1;
	}
	inline int getNextEven() {
		while (evenIndex < m) {
			if (taken.find(evenIndex) == taken.end()) return evenIndex;
			evenIndex += 2;
		}
		return -1;
	}
	void solve() {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 0) {
				even[arr[i]]++;
				evenitems[arr[i]].push_back(i);
			}
			else {
				odd[arr[i]]++;
				odditems[arr[i]].push_back(i);
			}
			taken.insert(arr[i]);
		}
		distodd = odditems.size();
		disteven = evenitems.size();
		int op = 0, ep  = 0;
		for (auto i : odd) {
			oddpair[op].first = i.second; oddpair[op].second = i.first; op++;
		}
		for (auto i : even) {
			evenpair[ep].first = i.second; evenpair[ep].second = i.first; ep++;
		}
		sort(oddpair, oddpair + op, greater<pair<int, int>>());
		sort(evenpair, evenpair + op, greater<pair<int, int>>());
		for (int i = 0; i < op; i++) {
			for (auto j : odditems[oddpair[i].second]) {
				oddqueue.push_back({oddpair[i].second, j});
			}
		}

		for (int i = 0; i < ep; i++) {
			for (auto j : evenitems[evenpair[i].second]) {
				evenqueue.push_back({evenpair[i].second, j});
			}
		}

		while ((distodd + disteven) != n) {
			if ()
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
}
