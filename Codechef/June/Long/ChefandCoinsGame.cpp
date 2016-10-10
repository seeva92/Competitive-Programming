#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define ll long long
using namespace std;
bitset<100007> bs;
vector<int> primes;
void init(){
	bs.set();
	for (ll i = 2; i < 100007; i++) {
		for(ll j = 2 * i; j<100007; j+=i){
			bs[j] = 0;
		}
		if(bs[i]) primes.push_back(i);
	}

}
int compute(int n){
	int len = primes.size();
	int cnt= 0; int res = 0;
	int temp = sqrt(n)+1;
	for(int i=0;i<len && primes[i]<= temp;i++){
			if((n % primes[i])==0){
				while((n % primes[i])==0){
					cnt++;
					n /= primes[i];
				}
				res ^= cnt;
			}
	}
	if(n!=1) res ^= 1;
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\1.txt", "r", stdin);
	freopen("D:\\2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	int t,n; cin>>t;
	while (t--) {
		cin>>n;
		if(n==1 || compute(n)>0) std::cout << "Chef" << std::endl;
		else std::cout << "Misha" << std::endl;

	}
}
