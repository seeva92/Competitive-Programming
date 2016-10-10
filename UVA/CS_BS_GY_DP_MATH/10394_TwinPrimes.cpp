#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define RANGE floor(int(sqrt(20000100)))
using namespace std;
vi primes;
vector<pii> twins;
const int range = RANGE;
bitset<range> flags;
void init() {
	flags.set();
	flags[0] = 0, flags[1] = 0;
	for (int i = 2; i * i < range; i++)
		for (int j = i * 2; j < range; j += i)
			flags[j] = 0;
	int f = -1, s = -1;
	for (int i = 2; i < range; i++) {
		if (flags[i]) {
			s = f != -1 && s == -1 ? i : s;
			f = f == -1 ? i : f;
			if (f != -1 && s != -1) {
				if (f + 2 == s) twins.push_back(mp(f, s));
				f = s; s = -1;
			}
			primes.push_back(i);
		}
	}
	int len = int(primes.size());
	bool check = true;
	for (int i = range; i < 20000100; i++) {
		check = true;
		for (int j = 0; j < len; j++)
			if (!(i % primes[j])) { check = false; break;}
		if (check) {
			s = f != -1 && s == -1 ? i : s;
			f = f == -1 ? i : f;
			if (f != -1 && s != -1) {
				if (f + 2 == s) twins.push_back(mp(f, s));
				f = s; s = -1;
			}
		}
	}
	// for (auto it : twins)
	// 	printf("%d %d\n", it.first, it.second);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	init();
	int s;
	while(scanf("%d",&s)!=EOF){
		printf("(%d, %d)\n",twins[s-1].first,twins[s-1].second);
	}
}