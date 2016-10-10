#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
void compute(int a[], string & p) {
	int j = 0;
	int n = int(p.size());
	for (int i = 1; i < n; i++) {
		while (j >= 0 && p[i] != p[j]) {
			if (j - 1 >= 0) j = a[j - 1];
			else j = -1;
		}
		j++;
		a[i] = j;
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	// a b c a b c d a b c a b c a b c
	// 0 0 0 1 2 3 0 1 2 3 4 5 6 4 5 6
}
void find_count(int a[], string &p, string & t) {
	int j = 0; int pn = int(p.size()), tn = int(t.size());
	cout << pn << endl;
	vector<int> idx;
	for (int i = 0; i < tn; i++) {
		while (j >= 0 && t[i] != p[j]) {
			if (j - 1 >= 0) j = a[j - 1];
			else j = -1;
		}
		j++;
		if (j == pn) {
			j = a[pn - 1]; // Move the jth index to longest prefix match index
			idx.push_back(i - pn + 1);
		}
	}
	for (size_t i = 0; i < idx.size(); i++) {
		cout << idx[i];
		if (i + 1 != idx.size()) cout << endl;
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; string needle, haystack;
	while (cin >> t >> needle >> haystack) {
		int len = int(haystack.size());
		//KMP
		int a[t];
		memset(a, 0, sizeof a);
		compute(a, needle);
		find_count(a, needle, haystack);



		//Naive Logic
		// for (int i = int(haystack.find(needle, 0)); (i != -1);) {
		// 	cout << i;
		// 	i = int(haystack.find(needle, i + 1));
		// 	if (i != -1) cout << endl;
		// }
		cout << endl;
	}

}