#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt","r",stdin);
	// freopen("2.txt","w",stdout);
	string str;
	while(cin>>str){
		if(str=="0:00") break;
		stringstream ss;
		ss<<str;
		double hr,mins;
		char c;
		ss>>hr; ss>>c; ss>>mins;
		hr = hr * (5 * 6) + mins/2.0;
		mins = mins * 6;
		if(abs(hr-mins)>180){
			printf("%.3f\n",360-abs(hr-mins));
		}else{
			printf("%.3f\n",abs(hr-mins));
		}
	}
}