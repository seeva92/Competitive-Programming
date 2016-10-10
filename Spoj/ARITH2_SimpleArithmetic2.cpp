#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
long compute(char op, long val1, long val2) {
	switch (op) {
	case '+': return val1 + val2;
	case '-': return val1 - val2;
	case '*': return val1 * val2;
	case '/': return val1 / val2;
	}
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	// ios::sync_with_stdio(false); cin.tie(0);
	int t; scanf("%d",&t);
	while (t--) {
		long x; char op;
		long res;
		scanf("%ld %c",&x,&op); res = x;
		while (op != '=') {
			scanf("%ld",&x);
			res = compute(op, res, x);
			scanf(" %c",&op);
		}		
		printf("%ld\n",res);
	}

}