#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
class BIT{
private:
	int *bit;
	int size;
	void Build(int a[],int size){
		for(int i=0;i<size;i++)
			Update(i,a[i]);
	}
	
	
public:
	BIT(int a[],int size){
		this->size = size;
		bit = new int[size+1];
		cout<<size<<'\n';
		memset(bit,0,sizeof(int)*(size+1));
		Build(a,size);
	}
	BIT(){

	}
	long long GetSum(int idx){
		idx++;
		long long total=0;
		while(idx>0){
			total+=bit[idx];
			idx-= (idx& -idx);
		}
		return total;
	}
	long long GetSumRange(int i,int j){
		return GetSum(i)-GetSum(j-1);
	}
	void Update(int idx,int value){
		idx++;
		while(idx<=size){
			bit[idx]+=value;
			idx+= (idx & -idx);
		}
	}
	void Display(){
		for(int i=1;i<=this->size;i++)
			cout<<bit[i]<<" ";
	}
	
};
int main(){
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int a[]={3,6,5,1,8,9,2,4,7,10};
	BIT bit(a,sizeof a/sizeof a[0]);
	cout<<bit.GetSum(0)<<endl;
	cout<<bit.GetSum(1)<<endl;
	cout<<bit.GetSum(2)<<endl;
	cout<<bit.GetSum(3)<<endl;
	cout<<bit.GetSum(4)<<endl;
	cout<<bit.GetSum(5)<<endl;
	cout<<bit.GetSum(6)<<endl;
	cout<<bit.GetSum(7)<<endl;
	cout<<bit.GetSum(8)<<endl;
	cout<<bit.GetSum(9)<<endl;
	cout<<bit.GetSumRange(9,0)<<endl;

	bit.Display();
	
}