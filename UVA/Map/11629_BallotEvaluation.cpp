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
const double eps = 1e-1;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int p, g;
	int n;
	char str[512];
	char name[25]; int in, f;
	unordered_map<string, int> party; party.reserve(50);
	scanf("%d %d", &p, &g);
	for (int i = 0; i < p; i++) {
		scanf("%s %d.%d", name, &in, &f);
		party[name] = in * 10 + f;
	}
	gets(str); //Empty
	bool comp = false;
	string tmp;
	double total = 0.0;
	for (int i = 0; i < g; i++) {
		gets(str);
		comp = false;
		char *p = strtok(str, " ");
		total = 0;
		while (p) {
			tmp = string(p);
			if (tmp == "<") {
				p = strtok(NULL, " ");
				sscanf(p, "%d", &n);				
				if (total < n*10) {
					printf("Guess #%d was correct.\n", i + 1);
				} else
					printf("Guess #%d was incorrect.\n", i + 1);
				break;
			} else if (tmp == ">") {
				p = strtok(NULL, " ");
				sscanf(p, "%d", &n);				
				if (total > n*10) {
					printf("Guess #%d was correct.\n", i + 1);
				} else
					printf("Guess #%d was incorrect.\n", i + 1);
				break;
			} else if (tmp == ">=") {
				p = strtok(NULL, " ");
				sscanf(p, "%d", &n);				
				if (total >= n*10) {
					printf("Guess #%d was correct.\n", i + 1);
				} else
					printf("Guess #%d was incorrect.\n", i + 1);
				break;
			} else if (tmp == "<=") {
				p = strtok(NULL, " ");
				sscanf(p, "%d", &n);				
				if (total <= n*10) {
					printf("Guess #%d was correct.\n", i + 1);
				} else
					printf("Guess #%d was incorrect.\n", i + 1);
				break;
			} else if (tmp == "=") {
				p = strtok(NULL, " ");
				sscanf(p, "%d", &n);				
				if (total == n*10) {
					printf("Guess #%d was correct.\n", i + 1);
				} else
					printf("Guess #%d was incorrect.\n", i + 1);
				break;
			} else if (tmp == "+") {

			} else {
				total += party[tmp];
			}
			p = strtok(NULL, " ");
		}
	}

}


