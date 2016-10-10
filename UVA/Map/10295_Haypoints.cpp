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
char str[100];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, m, sal;
	scanf("%d %d", &n, &m);
	fflush(stdin);
	map<string, int> salarymp;
	while (n--) {
		scanf("%s %d", &str, &sal);
		salarymp[str] = sal;
	}
	map<string, int> wordmp;
	while (m--) {
		wordmp.clear();
		while (scanf("%s", &str), strcmp(str, ".") != 0) {
			wordmp[str]++;
		}
		int total = 0;
		for(auto it : salarymp){
			total+=(wordmp[it.first]*it.second);
		}
		printf("%d\n",total);
	}
}


