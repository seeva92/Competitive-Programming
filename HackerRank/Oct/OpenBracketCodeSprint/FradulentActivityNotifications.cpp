#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
set<pair<int, int>, greater<pair<int, int>>> lt;
set<pair<int, int>> rt;
int arr[200007], N, d;
inline void push(int val, int i) {
	if (rt.empty()) rt.insert({val, i});
	else if (int(rt.size()) > int(lt.size())) {
		if ((*rt.begin()).first >= val) lt.insert({val, i});
		else {
			lt.insert(*rt.begin()); rt.erase(rt.begin()); rt.insert({val, i});
		}
	} else {
		if ((val >= (*rt.begin()).first) || (val > (*lt.begin()).first)) rt.insert({val, i});
		else {
			rt.insert(*lt.begin()); lt.erase(lt.begin()); lt.insert({val, i});
		}
	}
}
inline void pop(int val, int i) {
	auto lti = lt.find({val, i});
	if (lti != lt.end()) {
		lt.erase(lti);
	}
	auto rti = rt.find({val, i});
	if (rti != rt.end()) {
		rt.erase(rti);
	}

	if (int(lt.size()) > int(rt.size())) {
		rt.insert(*lt.begin()); lt.erase(lt.begin());
	} else if ((int(rt.size()) - int(lt.size())) > 1) {
		lt.insert(*rt.begin()); rt.erase(rt.begin());
	}

}
inline int getmed() {
	if (d % 2 == 0) {
		if (int(lt.size()) == int(rt.size())) {
			return (*lt.begin()).first + (*rt.begin()).first;
		}
	}
	return (*rt.begin()).first * 2;
}
void compute() {
	for (int i = 0; i < d && i < N; i++) {
		push(arr[i], i);
	}
	int cnt = 0;
	for (int i = d; i < N; i++) {
		if (getmed() <= arr[i]) cnt++;
		pop(arr[i - d], i - d);
		push(arr[i], i);
	};
	cout << cnt << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> d;
	for (int i = 0; i < N; i++) cin >> arr[i];
	compute();
}
