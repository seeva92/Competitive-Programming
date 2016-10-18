#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int T, N;
vi arr(100007);
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		int mxsum = INT_MIN, curr = 0, possum = 0; bool flag = false, zflag = false;
		int mxval = INT_MIN;
		for (int i = 0; i < N; i++) {
			if (arr[i] > 0) { flag = true; possum += arr[i];}
			if (arr[i] == 0) zflag = true;
			mxval = max(mxval, arr[i]);
			curr += arr[i];
			if (curr < 0) curr = 0;
			mxsum = max(curr, mxsum);
		}
		if (mxsum == 0) {
			if (zflag) cout << mxsum << " ";
			else cout << mxval << " ";
		} else
			cout << mxsum << " ";
		if (flag) cout << possum << '\n';
		else cout << mxval << '\n';
	}

}
