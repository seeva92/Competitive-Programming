#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n;
	char str1[256], str2[256];
	unordered_map<string, string> mp;

	scanf("%d", &n); n = n << 1; gets(str1);
	for (int i = 0; i < n; i += 2) {
		gets(str1); gets(str2);
		mp[str1] = str2;
	}
	scanf("%d", &n); gets(str1);
	for (int i = 0; i < n; i++) {
		gets(str1);
		printf("%s\n",mp[str1].c_str());
	}
}


