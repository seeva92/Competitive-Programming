#include <cstdio>
#include <bitset>
#include <cstring>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	int t, i;
	scanf("%d", &t);
	bitset<26> arr;
	char a[1010], b[1010];
	while (t--) {
		scanf("%s %s", &a, &b);
		arr.reset();
		int len = strlen(a);
		for (i = 0; i < len; i++) arr[a[i] - 'a'] = 1;
		len = strlen(b);
			for (i = 0; i < len; i++) if (arr[b[i] - 'a']) break;
		if (i < len) printf("Yes\n");
		else printf("No\n");
	}



}