#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
bool visited[2500];
int ntyp[2500];
vector<int> v[2500];
bool dfs(int i,int p,int typ) {
	visited[i] = 1;
	ntyp[i] = typ;
	for (auto it : v[i]) {
		if (!visited[it]) {
			if (dfs(it,i,!typ)) return true;
		} else if (it != p && ntyp[i]==ntyp[it]) {
				return true;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\1.txt", "r", stdin);
	freopen("E:\\2.txt", "w", stdout);
#endif
	int t, n, e, x, y; cin >> t;
	for(int a=1;a<=t;a++) {
		cin >> n >> e;
		for (int i = 0; i < 2500; i++) v[i].clear();
		memset(visited, 0, sizeof visited);
		memset(ntyp, -1, sizeof ntyp);
		for (int i = 0; i < e; i++) {
			cin >> x >> y; v[x].push_back(y); v[y].push_back(x);
		}	
		int i;	
		for(i=1;i<=n;i++){
			if(!visited[i]){
				if(dfs(i,0,1)) break;
			} 
		}
		cout<<"Scenario #"<<a<<":\n";
		if(i<=n)
			cout<<"Suspicious bugs found!\n";
		else
			cout<<"No suspicious bugs found!\n";

	}


}