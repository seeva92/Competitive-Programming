#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define ll long long
using namespace std;
string A,B;
void compute(){
	int len = A.size();
	bool flag =true;
	int uz=0,uo=0,mz=0,mo=0;
	for(int i=0;i<len;i++){
		if(A[i]=='0'){
			if(A[i]==B[i]) mz++;
			else uz++;
		}else{
				if(A[i]==B[i]) mo++;
				else uo++;
		}
	}
	int temp = min(uz,uo);
	int res = temp;
	mz+= temp; mo+= temp;
	uz-= temp; uo-= temp;
	if(uz){
		if(mo){
			res+= uz;
		}else{ cout<<"Unlucky Chef\n"; return;}
	}else if(uo){
		if(mz){
			res+= uo;
		}else{ cout<<"Unlucky Chef\n";return;}
	}
	cout<<"Lucky Chef\n"<<res<<endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\1.txt", "r", stdin);
	freopen("D:\\2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin>>t;
	while (t--) {
		cin>>A>>B;
		if(A==B) cout<<"Lucky Chef\n0\n";
		else if(int(A.size())==1 || int(A.size())!=int(B.size())) cout<<"Unlucky Chef\n";
		else{
			compute();
		}

	}
}
