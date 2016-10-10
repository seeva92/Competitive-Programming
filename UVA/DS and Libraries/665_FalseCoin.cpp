#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
const int arrsize = (int)1e5;
int eqArr[arrsize], leftArr[arrsize], rightArr[arrsize];
int eqCount, leftCount, rightCount;
int m, n, k, x, p;
struct Data {
	int p;
	vector<int> left;
	vector<int> right;
	char c;
};
bool Compute(Data input[], int k, int coin, bool isHeavy) {
	int leftWeight = 0, rightWeight = 0;
	int heavy = 50, light = -50, even = 1;

	for (int j = 1; j <= k; j++) {
		Data data = input[j];
		leftWeight = rightWeight = 0;
		for (int i = 0; i < (int)data.left.size(); i++) {
			if (coin == data.left[i]) leftWeight += isHeavy ? heavy : light;
			else
				leftWeight += even;
		}

		for (int i = 0; i < (int)data.right.size(); i++) {
			if (coin == data.right[i]) rightWeight += isHeavy ? heavy : light;
			else
				rightWeight += even;
		}

		if (data.c == '=') {
			if (leftWeight != rightWeight) return false;
		} else if (data.c == '<') {
			if (leftWeight >= rightWeight) return false;
		}
		else if (data.c == '>') {
			if (leftWeight <= rightWeight) return false;
		};
	}


	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);

	cin >> m;
	while (m--) {
		cin >> n >> k;
		Data data[k + 1];
		bool found = false;
		int foundCoin = 0;
		for (int i = 1; i <= k; i++) {


			cin >> data[i].p;
			for (int j = 1; j <= data[i].p; j++) {
				cin >> x;
				data[i].left.push_back(x);
			}
			for (int j = 1; j <= data[i].p; j++) {
				cin >> x;
				data[i].right.push_back(x);
			}
			cin >> data[i].c;


		}

		int i;
		int foundCount = 0;
		int foundValue = 0;
		for (i = 1; i <= n; i++) {
			if (Compute(data, k, i, true) || Compute(data, k, i, false)) {
				foundValue = i; foundCount++;
			}
		}
		if (foundCount == 1)
			cout << foundValue;
		else
			cout << 0;

		cout << '\n';
		if (m != 0)
			cout << '\n';

	}
}