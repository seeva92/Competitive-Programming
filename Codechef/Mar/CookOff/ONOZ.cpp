#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
int arr[110][110];
int l, r;
bool ispalin(string str) {
	r = str.size();
	for (l = 1; l < r; l++) if (str[l] != str[l - 1]) return false;
	return true;
}
void init() {
	int l, r;
	string str;
	for (int i = 0; i < 110; i++) {
		stringstream ss; ss << i;
		ss >> str;
		if (!ispalin(str)) continue;
		for (int j = 0; j < 110; j++) {
			stringstream sj; sj << j;
			if (!ispalin(str + sj.str())) continue;
			else {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i < 110; i++) {
		arr[0][i] += arr[0][i - 1];
		arr[i][0] += arr[i - 1][0];
	}

	for (int i = 1; i < 110; i++)
		for (int j = 1; j < 110; j++)
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	memset(arr, 0, sizeof arr);
	init();
	int t; cin>>t;
	int h,m;
	while(t--){
		cin>>h>>m;
		cout<<arr[h-1][m-1]<<endl;
	}

}