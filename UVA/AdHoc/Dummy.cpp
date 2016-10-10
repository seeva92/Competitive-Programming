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
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	double pi = 2 * acos(0.0); // this is a more accurate way to compute pi
	// int n; scanf("%d", &n);
	printf("%.100lf\n",pi);
}