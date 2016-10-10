#include <cstdio>
#include <algorithm>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int a, d;
	while (scanf("%d %d", &a, &d) && (a || d)) {
		int att[a]; int def[d];
		for (int i = 0; i < a; i++) scanf("%d", &att[i]); sort(att, att + a);
		for (int i = 0; i < d; i++) scanf("%d", &def[i]); sort(def, def + d);
		if(att[0]<def[1]) printf("Y\n");
		else printf("N\n");
	}

}