#include <bits/stdc++.h>
using namespace std;
void f(int num) {
	while (num) {
		int i;
		for(i=0;(1<<i)<=num;++i);
		cout<<2;
		if (i-1==0) cout<<"(0)";
		else if (i - 1 > 1) {
			cout << "("; f(i-1); cout<<")";}
		num-=(1<<(i-1)); if(num) cout<<"+";
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);	
	int arr[] = {137,1315,73,136,255,1384,16385};
	int len = sizeof arr / sizeof arr[0];
	for (int i=0;i<len;i++) {
		cout<<arr[i]<<"="; f(arr[i]); cout<<endl;
	}
}