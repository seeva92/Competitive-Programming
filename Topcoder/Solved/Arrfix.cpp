#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Arrfix
{
	multiset<int> st;
	bool vis[60];
public:
	int mindiff(vector<int> A, vector<int> B, vector<int> F) {
		memset(vis, 0, sizeof vis);
		for (auto i : F) st.insert(i);
		int len = A.size();
		//Greedy
		for (int i = 0; i < len && st.size() > 0; i++) {
			if ((A[i] != B[i]) && st.find(B[i]) != st.end()) {
				A[i] = B[i];
				st.erase(st.find(B[i]));
				vis[i] = true;
			}
		}
		//Matched
		for (int i = 0; i < len && st.size() > 0; i++) {
			if (!vis[i] && (A[i] == B[i]) && st.find(B[i]) != st.end()) {
				st.erase(st.find(B[i]));
				vis[i] = true;
			}
		}

		for (int i = 0; i < len && st.size() > 0; i++) {
			if (A[i] != B[i] && !vis[i]) {
				A[i] = *st.begin();
				st.erase(st.begin());
				vis[i] = true;
			}
		}
		for (int i = 0; i < len && st.size() > 0; i++) {
			if (!vis[i]) {
				A[i] = *st.begin(); st.erase(st.begin()); vis[i] = true;
			}
		}
		//UnMatched
		int unmatch = 0;
		for (int i = 0; i < len; i++) if (A[i] != B[i]) unmatch++;


		return unmatch;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Arrfix a;
	cout << a.mindiff({1, 3, 3, 3}, {2, 3, 3, 3}, {2, 2});
}
