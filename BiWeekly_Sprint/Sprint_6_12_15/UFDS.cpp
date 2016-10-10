#include <bits/stdc++.h>
using namespace std;
class UFDS
{
private:
	vector<int> v, rank, setSize; int numSets;
public:
	UFDS(int n) {
		v.assign(n, 0); rank.assign(n, 0); setSize.assign(n, 1); numSets = n;
		for (int i = 0; i < n; i++) v[i] = i;
	}
	int findSet(int i) {
		return v[i] == i ? i : (v[i] = findSet(v[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int y = findSet(j); int x = findSet(i);
			setSize[y] += setSize[x];
			if (rank[x] < rank[y]) v[x] = y;
			else {
				v[y] = x; rank[y]++;
			}
		}
	}
	int numDisjointSets() { return numSets;}
	int size(int i) { return setSize[findSet(i)];}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
#endif
	UFDS ufds(5);
	// ufds.unionSet(2, 3);
	// ufds.unionSet(1, 3);
	ufds.unionSet(0, 1);
	ufds.unionSet(3, 4);
	cout << ufds.isSameSet(0, 1) << endl; cout << ufds.isSameSet(0, 2) << endl;
	cout << ufds.isSameSet(0, 3) << endl; cout << ufds.isSameSet(0, 4) << endl;
}