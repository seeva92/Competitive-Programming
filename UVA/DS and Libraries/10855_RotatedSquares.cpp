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

void rotate(std::vector<string> & arr) {
	//Swap values Diagonally
	int len = (int)arr.size();

	int i, j, k;
	for (i = 0; i < len; i++)
		for (j = i; j < len; j++) {
			swap(arr[i][j], arr[j][i]);
		}

	for (i = 0, j = len - 1; i < j; i++, j--) {
		for (k = 0; k < len; k++)
			swap(arr[k][i], arr[k][j]);
	}

}

int compare(vector<string> big, vector<string> small) {
	int i, j, k, l, m, n;
	int count = 0;
	int blen = (int)big.size(), slen = (int)small.size();
	bool flag = false;
	for (i = 0; i <= (blen - slen); i++) {
		for (j = 0; j <= (blen - slen); j++) {
			flag = false;
			for (k = 0, m = i; k < slen; k++, m++) {
				for (l = 0, n = j; l < slen; l++, n++) {
					if (small[k][l] != big[m][n]) {
						flag = true; break;
					}
				}
				if (flag)
					break;
			}
			if (k == slen && l == slen)
				count++;
		}
	}
	return count;
}
int main() {
	// std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	int N, n;
	while (scanf("%d %d", &N, &n), N || n) {
		vector<string> big, small;
		char c;
		for (int i = 0; i < N; i++) {
			string str;
			for (int j = 0; j < N; j++) {
				scanf(" %c", &c);
				str.push_back(c);
			}
			big.push_back(str);

		}


		for (int i = 0; i < n; i++) {
			string str;
			for (int j = 0; j < n; j++) {
				scanf(" %c", &c);
				str.push_back(c);
			}
			small.push_back(str);
		}


		printf("%d ", compare(big, small));
		rotate(small);
		printf("%d ", compare(big, small));
		rotate(small);
		printf("%d ", compare(big, small));
		rotate(small);
		printf("%d\n", compare(big, small));

	}
}