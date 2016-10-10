#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
vector<string> str;
string temp;
int mem[1007][1007];
int compute(int i,int j,int k){	
	if(i==j) return 0;
	if(i>j) return 0;
	if(mem[i][j]!=-1) return mem[i][j];
	temp = str[j]; reverse(temp.begin(),temp.end());
	if(str[i] == temp)
		return compute(i+1,j-1);
	return mem[i][j]=min(1+compute(i+1,j),1+compute(i,j-1));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\1.txt", "r", stdin);
	freopen("E:\\2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		memset(mem,-1,sizeof mem);
		str.clear();
		for(int i=0;i<n;i++){
			cin>>temp; str.push_back(temp);
		}
		cout<<compute(0,int(str.size())-1,0)<<endl;
	}

}