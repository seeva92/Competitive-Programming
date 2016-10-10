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
#include <map>
using namespace std;
const int n = 12;
struct bal {
	string left;
	string right;
	string result;
};
int even[12], lup[12], rup[12], ldown[12], rdown[12];
int down = 0, up = 0;
bool upEmpty() {
	for (int i = 0; i < n; i++) {
		if (even[i] == 0) {
			if (lup[i] != 0 || rup[i] != 0)
				return false;
		}

	}
	return true;
}
bool downEmpty() {
	for (int i = 0; i < n; i++) {
		if (even[i] == 0) {
			if (ldown[i] != 0 || rdown[i] != 0)
				return false;
		}
	}
	return true;
}
bool compute() {
	// cout << endl;

	// cout << "Eve:";
	// for (int i = 0; i < 12; i++)
	// 	cout << even[i] << " ";
	// cout << endl;
	// cout << "Ldo:";
	// for (int i = 0; i < 12; i++)
	// 	cout << ldown[i] << " ";
	// cout << endl;
	// cout << "Rdo:";
	// for (int i = 0; i < 12; i++)
	// 	cout << rdown[i] << " ";
	// cout << endl;
	// cout << "Lup:";
	// for (int i = 0; i < 12; i++)
	// 	cout << lup[i] << " ";
	// cout << endl;
	// cout << "Rup:";
	// for (int i = 0; i < 12; i++)
	// 	cout << rup[i] << " ";
	// cout << endl;
	if (upEmpty() && !downEmpty()) {
		for (int i = 0; i < 12; i++) {
			if (ldown[i] == down) {
				cout << (char)(i + 'A') << " is the counterfeit coin and it is light.\n";
				return true;
			}
			if (rdown[i] == down) {
				cout << (char)(i + 'A') << " is the counterfeit coin and it is heavy.\n";
				return true;
			}
		}
	}
	if (!upEmpty() && downEmpty()) {
		for (int i = 0; i < 12; i++) {
			if (lup[i] == up) {
				cout << (char)(i + 'A') << " is the counterfeit coin and it is heavy.\n";
				return true;
			}
			if (rup[i] == up) {
				cout << (char)(i + 'A') << " is the counterfeit coin and it is light.\n";
				return true;
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		if (ldown[i] == down && rup[i] == up) {
			cout << (char)(i + 'A') << " is the counterfeit coin and it is light.\n";
			return true;
		}
		if (rdown[i] == down && lup[i] == up) {
			cout << (char)(i + 'A') << " is the counterfeit coin and it is heavy.\n";
			return true;
		}

	}

}
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	// freopen("2.txt","w",stdout);
	int t;
	string str1, str2, str3;
	cin >> t;
	while (t--) {
		bal balances[3];
		for (int i = 0; i < 3; i++)
			cin >> balances[i].left >> balances[i].right >> balances[i].result;
		// for (int i = 0; i < 3; i++)
		// 	cout << balances[i].left << " " << balances[i].right << " " << balances[i].result << '\n';


		memset(even, 0, sizeof even); memset(lup, 0, sizeof lup); memset(ldown, 0, sizeof ldown);
		memset(rup, 0, sizeof rup); memset(rdown, 0, sizeof rdown);
		//Even Part
		for (int i = 0; i < 3; i++) {
			if (balances[i].result == "even") {
				for (int j = 0; j < (int)balances[i].left.length(); j++) {
					even[(int)(balances[i].left[j] - 'A')] = 1;
					// cout << (int)(balances[i].left[j] - 'A');
				}
				for (int j = 0; j < (int)balances[i].right.length(); j++) {
					even[(int)(balances[i].right[j] - 'A')] = 1;
					// cout << (int)(balances[i].right[j] - 'A');
				}
			}
		}
		int count = 0;
		int index = 0;
		for (int i = 0; i < 12; i++)
			if (even[i] == 0) {
				count++;
				index = i;
			}
		if (count == 1)
		{
			cout << (char)(index + 'A') << " is the counterfeit coin and it is heavy.\n";
			continue;
		}

		down = up = 0;
		//Down Part
		for (int i = 0; i < 3; i++) {
			if (balances[i].result == "down") {
				down++;
				for (int j = 0; j < (int)balances[i].left.length(); j++)
					if (even[(int)(balances[i].left[j] - 'A')] == 0) {
						ldown[(int)(balances[i].left[j] - 'A')] += 1;
						// cout << (int)(balances[i].left[j] - 'A') << " ";
					}

				for (int j = 0; j < (int)balances[i].right.length(); j++)
					if (even[(int)(balances[i].right[j] - 'A')] == 0) {
						rdown[(int)(balances[i].right[j] - 'A')] += 1;
						// cout << (int)(balances[i].right[j] - 'A') << " ";


					}
			}
		}

		//Up Part
		for (int i = 0; i < 3; i++) {
			if (balances[i].result == "up") {
				up++;
				for (int j = 0; j < (int)balances[i].left.length(); j++)
					if (even[(int)(balances[i].left[j] - 'A')] == 0)
						lup[(int)(balances[i].left[j] - 'A')]++;

				for (int j = 0; j < (int)balances[i].right.length(); j++)
					if (even[(int)(balances[i].right[j] - 'A')] == 0)
						rup[(int)(balances[i].right[j] - 'A')]++;
			}
		}
		compute();
	}
}