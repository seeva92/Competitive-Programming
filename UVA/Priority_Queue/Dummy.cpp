#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	vector<pair<int, int>> v;
	for (int i = 0; i < 20; i++)
		v.push_back(make_pair(rand() % 100, rand() % 100));
	sort(v.begin(), v.end());
	for(auto it : v)
		printf("%d %d\n",it.first,it.second );

}