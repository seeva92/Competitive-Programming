#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define ll long long
using namespace std;
int arr[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ll n; ll x; cin>>n;
	ll total = 0;
	for(int i=0;i<n;i++) {
		cin>>x; total+=x;
	}
	cout<<max(n,(total+1)/2)<<endl;
}