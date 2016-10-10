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
bool next_permute(int arr[], int start, int end) {
	if (start == end)
		return false;
	if (end - start == 1)
		return false;

	int i, j, k;
	i = end;
	while (true) {
		j = i;
		i--;
		if (arr[i] < arr[j]) {
			k = end;
			while (!(arr[i] < arr[--k]));
			swap(arr[i], arr[k]);
			reverse(arr + j, arr + end);
			return true;
		}
		if (i == start) {
			reverse(arr, arr + end);
			return false;
		}
	}
	return true;
}

bool compare(const string & first, const string & second) {
	string a = first;
	string b = second;
	int alen = a.length(), blen = b.length();
	int i = 0, j = 0;
	char x, y;
	while (i < alen && j < blen) {
		if (a[i] < b[j]) {
			if (isupper(a[i]) && islower(b[j])) {
				if (tolower(a[i]) <= b[j])
					return true;
				return false;
			}
			return true;
		}
		else if (a[i] > b[j]) {
			if (islower(a[i]) && isupper(b[j])) {
				if (a[i] >= tolower(b[j]))
					return false;
				return true;
			}
			return false;
		}
		i++;
		j++;
	}
	// if (i == alen && j == blen)
	// 	return true;
	// else if (i < alen)
	// 	return true;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	string str, temp;
	int t;
	int i, len;
	cin >> t;
	while (t--) {
		cin >> str;
		sort(str.begin(), str.end());
	vector<string> v;
		do {
			v.push_back(str);
		} while (next_permutation(str.begin(), str.end()));
		len = (int)v.size();

		sort(v.begin(), v.end(), compare);
		for (i = 0; i < len; i++)
			cout << v[i] << '\n';
	}
}