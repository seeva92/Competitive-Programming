#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int T, N;
	cin >> T; cout<<T;
	int x = 1;
	while (T--) {
		cin >> N;
		int temp;
		vector<pair<int, int>> arr;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			arr.push_back({temp, i});
		}
		cout << "Case  #" << x << ": ";
		sort(arr.begin(),arr.end(), greater<pair<int, int>>());		
		while (arr[0].first != 0) {
			if (arr[0].first == arr[1].first) {
				cout << ('A' + (arr[0].second)) << ('A' + (arr[0].second));
				arr[0].first--; arr[1].first--;
			} else if (arr[0].first >= 2) {
				char c = (char)('A' + (arr[0].second));
				cout << c << c;
				arr[0].first -= 2;
			} else if (arr[0].first == 1) {
				cout << (char)('A' + (arr[0].second));
				arr[0].first--;
			}
			cout << " ";
			sort(arr.begin(),arr.end(), greater<pair<int, int>>());

		}
		cout << endl;
		// while (!p.empty()) {
		// 	pair<int, int> first = p.top(); p.pop();
		// 	if (!p.empty()) {
		// 		pair<int, int> second = p.top(); p.pop();
		// 		if (first.first == second.first) {
		// 			p.push({first.first - 1, first.second});
		// 			p.push({second.first - 1, second.second});
		// 			cout << (char)('A' + (first.second - 1)) << (char)('A' + (second.second - 1));
		// 		} else {
		// 			if (first.first - 2 > 0) {
		// 				p.push({first.first - 2, first.second});
		// 				char c = (char)('A' + first.second - 1);
		// 				cout << c << c;
		// 			}
		// 			else if (first.first - 1 > 0) {
		// 				p.push({first.first - 1, first.second});
		// 				char c = (char)('A' + first.second - 1);
		// 				cout << c;
		// 			}
		// 		}
		// 	} else {
		// 		if (first.first - 2 > 0) {
		// 			p.push({first.first - 2, first.second});
		// 			char c = (char)('A' + first.second - 1);
		// 			cout << c << c;
		// 		}
		// 		else if (first.first - 1 > 0) {
		// 			p.push({first.first - 1, first.second});
		// 			char c = (char)('A' + first.second - 1);
		// 			cout << c << c;
		// 		}
		// 	}
		// 	cout << " ";
		// }
		cout << endl;
	}

}