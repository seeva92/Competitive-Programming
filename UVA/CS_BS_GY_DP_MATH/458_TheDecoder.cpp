#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
char arr[10000]; int len, i;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	while (gets(arr)) {
		len = strlen(arr);
		for (i = 0; i < len; i++) arr[i] = char(arr[i] - 7);
		printf("%s\n", arr);
	}
}