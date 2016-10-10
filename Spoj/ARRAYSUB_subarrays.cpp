#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int arr[1000001];
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\1.txt", "r", stdin);
	freopen("E:\\2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n,k; cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	cin>>k;
	priority_queue<pair<int,int>> p;
	int i;
	for(i=0;i<n && i<k; i++) p.push({arr[i],i});
	cout<<p.top().first;
	for(;i<n;i++){
		p.push({arr[i],i});
		while(!p.empty() && p.top().second<(i-k+1)) p.pop();
		cout<<" "<<p.top().first;
	}
}