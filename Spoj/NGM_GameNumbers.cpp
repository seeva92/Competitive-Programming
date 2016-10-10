#include <iostream>
#include <cstdio>
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	long long num;
	scanf("%lld", &num);
	if(num%10>0){
		printf("1\n%lld",num%10);
	}else
		printf("2\n");

}
