#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
// 	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
// #endif
	string str, ph;
	cin >> str >> ph; int counter = 0;
	size_t f = str.find(ph);

	while (f != string::npos) {
		counter++;
		f = str.find(ph, f + ph.length());
	}
	printf("%d\n", counter);
}
