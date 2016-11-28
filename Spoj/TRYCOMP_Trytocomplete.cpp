#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
struct node {
	node *child[26];
	int flag;
	int res;
	string s;
};
node * head;
int n, q; string s;
string result; int resc = 0;
inline node * newnode() {
	node *temp = new node();
	memset(temp->child, 0, sizeof temp->child);
	temp->res = 0;
	temp->flag = 0;
	return temp;
}
void init() { head = newnode(); }

inline int insert(node *temp, int i, string & str) {
	if (i == str.size()) {
		temp->flag++;
		if (temp->flag == temp->res) {
			if (str < temp->s || temp->s.empty())
				temp->s = str;
		} else if (temp->flag > temp->res) {
			temp->s = str;
			temp->res = temp->flag;
		}
		return temp->res;
	}
	if (temp->child[str[i] - 'a'] == NULL) temp->child[str[i] - 'a'] = newnode();
	temp = temp->child[str[i] - 'a'];

	int c = insert(temp, i + 1, str);
	if (c == temp->res) {
		if (str < temp->s || temp->s.empty())
			temp->s = str;
	} else if (c > temp->res) {
		temp->s = str;
		temp->res = c;
	}
	return temp->res;
}
inline void query(string & pref) {
	node *temp = head; bool flag = true;
	for (auto i : pref) {
		if (temp->child[i - 'a'] == NULL) {
			flag = false; break;
		}
		temp = temp->child[i - 'a'];
	}
	if (flag) {
		cout << temp->s << " " << temp->res << '\n';
	} else cout << "-1\n";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> n;
	while (n--) {
		cin >> s;
		insert(head, 0, s);
	}
	cin >> q;
	while (q--) {
		cin >> s;
		query(s);
	}
}
