#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <stack>
#include <map>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
using namespace std;
vector<stack<string>> v(200);
bool isMatch(string str1, string str2) {
	if (str1[0] == str2[0] || str1[1] == str2[1]) {
		return true;
	}
	return false;
}
int len = 51;
// bool compute(int i) {

// 	if (i <= 0)
// 		return true;

// 	if (i - 3 >= 0 && isMatch(v[i].top(), v[i - 3].top())) {
// 		v[i - 3].push(v[i].top()); v[i].pop();
// 		if (v[i].empty()) {
// 			for (int k = i + 1; k < len; k++)
// 				v[k - 1] = v[k];
// 			--len;
// 		}
// 		return true;

// 	}
// 	else if (i - 1 >= 0 && isMatch(v[i].top(), v[i - 1].top())) {
// 		v[i - 1].push(v[i].top()); v[i].pop();
// 		if (v[i].empty()) {
// 			for (int k = i + 1; k < len; k++)
// 				v[k - 1] = v[k];
// 			--len;
// 		}
// 		return true;
// 	}
// 	return false;
// }
// bool erase = false;
// void compute(int i) {

// 	if (i <= 0)
// 		return;
// 	int temp = len;

// 	while (!v[i].empty()) {
// 		for (int k = 0; k < v.size(); k++)
// 			if (!v[k].empty())
// 				printf("%s ", v[k].top().c_str());
// 			else
// 				printf("   ");
// 		printf("\n");
// 		for (int k = 0; k < v.size(); k++)
// 			printf("%d ", v[k].size());
// 		printf("\n");
// 		// printf("%d %d %d\n", i, temp, len);
// 		if (i - 3 >= 0 && isMatch(v[i].top(), v[i - 3].top())) {
// 			v[i - 3].push(v[i].top()); v[i].pop();
// 			if (v[i].empty()) {
// 				v.pop_back();
// 			}
// 			compute(i - 3);
// 		}
// 		else if (i - 1 >= 0 && isMatch(v[i].top(), v[i - 1].top())) {
// 			v[i - 1].push(v[i].top()); v[i].pop();
// 			if (v[i].empty()) {
// 				v.pop_back();
// 			}
// 			compute(i - 1);
// 		} else
// 			break;
// 	}
// 	if (v[i].empty()) {
// 		v.pop_back();
// 	}

// }
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	char arr[4];
	while (scanf("%s", arr), arr[0] != '#') {
		v.clear();
		stack<string> s1; s1.push(string(arr));
		v.push_back(s1);
		for (int i = 1; i <= 51; i++) {
			scanf("%s", arr);
			stack<string> s; s.push(string(arr));
			v.push_back(s);
		}

		for (int i = 0; i < v.size(); i++) {
			if (i - 3 >= 0 && isMatch(v[i].top(), v[i - 3].top())) {
				v[i - 3].push(v[i].top()); v[i].pop();
				if (v[i].empty()) {
					v.erase(v.begin() + i);
				}
				i = 0;
			} else if (i - 1 >= 0 && isMatch(v[i].top(), v[i - 1].top())) {
				v[i - 1].push(v[i].top()); v[i].pop();
				if (v[i].empty()) {
					v.erase(v.begin() + i);
				}
				i = 0;
			}
		}
		printf("%d ", v.size());
		if ((int)v.size() == 1)
			printf("pile remaining:");
		else
			printf("piles remaining:");
		for (int i = 0; i < (int)v.size(); i++)
			printf(" %d", v[i].size());
		printf("\n");
	}
}
