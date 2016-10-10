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
class ST {
private:
	int *st;
	int size;
	void Build(int a[], int index, int start, int end) {
		if (start > end)
			return;
		if (start == end) {
			st[index] = a[start];
			return;
		}
		int mid = start + (end - start) / 2;
		Build(a, 2 * index + 1, start, mid);
		Build(a, 2 * index + 2, mid + 1, end);
		st[index] = st[2 * index + 1] + st[2 * index + 2];
	}


public:
	ST(int a[], int size) {
		this->size = (2 * (int)pow(2, (int)ceil(log2(size)))) - 1;
		st = new int[this->size + 10];
		memset(st, 0, sizeof(int) * (this->size + 10));
		Build(a, 0, 0, size - 1);
	}
	ST() {

	}
	long long GetSum(int start, int end, int i, int j, int idx) {
		if (start > end)
			return 0;
		if (i > end || j < start)
			return 0;
		if (i <= start && end <= j)
			return st[idx];

		int mid = start + (end - start) / 2;

		long long total = GetSum(start, mid, i, j, 2 * idx + 1) + GetSum(mid + 1, end, i, j, 2 * idx + 2);
		return total;
	}
	void Update(int start, int end, int pos, int val, int idx) {
		if (start > end)
			return;
		if (start == end) {
			st[idx] += val;
			return;
		}
		int mid = start + (end - start) / 2;
		if (pos <= mid)
			Update(start, mid, pos, val, 2 * idx + 1);
		else
			Update(mid + 1, end, pos, val, 2 * idx + 2);

		st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
	}
	// long long GetSumRange(int i,int j){
	// 	return GetSum(i)-GetSum(j-1);
	// }
	// void Update(int idx,int value){
	// 	idx++;
	// 	while(idx<=size){
	// 		bit[idx]+=value;
	// 		idx+= (idx & -idx);
	// 	}
	// }
	// void Display(){
	// 	for(int i=1;i<=this->size;i++)
	// 		cout<<bit[i]<<" ";
	// }

};
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int a[] = {3, 6, 5, 1, 8, 9, 2, 4, 7, 10};
	ST st(a, sizeof a / sizeof a[0]);
	cout<<st.GetSum(0,9,0,0,0)<<endl;
	cout<<st.GetSum(0,9,0,1,0)<<endl;

	cout<<st.GetSum(0,9,0,9,0)<<endl;

	cout<<st.GetSum(0,9,5,9,0)<<endl;
	cout<<st.GetSum(0,9,0,4,0)<<endl;

	// cout<<st.GetSum(1)<<endl;
	// cout<<st.GetSum(2)<<endl;
	// cout<<st.GetSum(3)<<endl;
	// cout<<st.GetSum(4)<<endl;
	// cout<<st.GetSum(5)<<endl;
	// cout<<st.GetSum(6)<<endl;
	// cout<<st.GetSum(7)<<endl;
	// cout<<st.GetSum(8)<<endl;
	// cout<<st.GetSum(9)<<endl;
	// cout<<st.GetSumRange(9,0)<<endl;

	// st.Display();

}