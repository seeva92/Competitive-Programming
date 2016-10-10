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
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int leapMonths[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int regularMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	long long leapSum[13], regularSum[13];
	leapSum[1] = leapMonths[1];
	regularSum[1] = regularMonths[1];
	for (int i = 2; i <= 12; i++) {
		leapSum[i] = leapSum[i - 1] + leapMonths[i];
		regularSum[i] = regularSum[i - 1] + regularMonths[i];
	}

	long long n;
	int d, m, y;
	while (cin >> n >> d >> m >> y, n || d || m || y) {
		long long curr  = 0;
		int i;
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
			for (i = d; i <= leapMonths[m] && curr < n; i++) {
				curr++;
			}
			if (curr == n) {
				cout << i << " " << m << " " << y;
				continue;
			}
		d = i;
			
		} else {
			for (i = d; i <= leapMonths[m] && curr < n; i++) {
				curr++;
			}
			if (curr == n) {
				cout << i << " " << m << " " << y;
				continue;
			}
		}


		for (i = y + 1; i < 3000 && curr < n; i++) {
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
				curr += leapSum[12];
			} else
				curr += regularSum[12];

		}
		if (curr == n)
		}
}