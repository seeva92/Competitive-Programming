#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) (x<<1)+1
#define EMPTY 10
#define Barbary 0
#define Bucaneer 1
#define Inverse -1
using namespace std;
class STree {
private:
	class Node {
	public:
		int ct, lazy, len;
		Node(int c, int ln, int l) {ct = c, len = ln, lazy = l;}
	};
	vector<int> v; int n; vector<Node> node;
public: STree(vector<int> &vi) {
		v = vi; n = (int)vi.size(); node.assign(4 * n, Node(0, 0, EMPTY));  Build(0, n - 1, 1);
	}
	void Build(int i, int j, int idx) {
		if (i == j) { node[idx].ct = v[i]; node[idx].len =  1;}
		else {
			Build(i, (i + j) / 2, left(idx)); Build((i + j) / 2 + 1, j, right(idx));
			node[idx].ct = node[left(idx)].ct + node[right(idx)].ct;
			node[idx].len = j - i + 1;
			node[idx].lazy = EMPTY;
		}
	}

	void settype(int idx, int type) {
		if (type == -1) {
			switch (node[idx].lazy) {
			case 0: node[idx].lazy = 1; break;
			case 1: node[idx].lazy = 0; break;
			case -1: node[idx].lazy = EMPTY; break;
			case EMPTY: node[idx].lazy = -1; break;
			}
		} else {
			node[idx].lazy = type;
		}

	}
	void change(int idx) {
		switch (node[idx].lazy) {
		case 0: node[idx].ct = 0; break;
		case 1: node[idx].ct = node[idx].len; break;
		case -1: node[idx].ct = node[idx].len - node[idx].ct; break;
		default: return;
		};
		if (node[idx].len != 1) {
			settype(left(idx), node[idx].lazy); settype(right(idx), node[idx].lazy);
		}
		node[idx].lazy = EMPTY;
	}
	void Update(int i, int j, int s, int e, int val, int idx) {
		if (s <= i && j <= e) settype(idx, val);
		change(idx);
		if (s <= i && j <= e) return;
		if (s > j || e < i) return;
		else {
			Update(i, (i + j) / 2, s, e, val, left(idx)); Update((i + j) / 2 + 1, j, s, e, val, right(idx));
			node[idx].ct = node[left(idx)].ct + node[right(idx)].ct;
		}
	}
	int Query(int i, int j, int s, int e, int idx) {
		change(idx);
		if (s <= i && j <= e) return node[idx].ct;
		if (s > j || e < i) return 0;
		else {
			int lt = Query(i, (i + j) / 2, s, e, left(idx));
			int rt = Query((i + j) / 2 + 1, j, s, e, right(idx));
			node[idx].ct = node[left(idx)].ct + node[right(idx)].ct;
			return lt + rt;
		}
	}
	int Query(int i, int j) { return Query(0, n - 1, i, j, 1);}
	void Update(int i, int j, int val) { Update(0, n - 1, i, j, val, 1);}
	void display() { // {printf("Tree\n"); for (auto it : c//t) printf("%d ", it//); printf("\n");
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int test, t, n, len, q, m, i, j; char str[1000]; char c;
	int x = 1;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &m);
		vector<int> v;
		while (m--) {
			scanf("%d %s", &t, &str); len = strlen(str);
			for (i = 0; i < t; i++)
				for (j = 0; j < len; j++) v.push_back(str[j] - '0');
		}
		STree st(v);
		scanf("%d", &q);
		int y = 1;
		printf("Case %d:\n", x++);
		while (q--) {
			scanf(" %c %d %d", &c, &i, &j);
			switch (c) {
			case 'F': st.Update(i, j, Bucaneer); st.display(); break;
			case 'E': st.Update(i, j, Barbary); st.display(); break;
			case 'I': st.Update(i, j, Inverse); st.display(); break;
			case 'S': printf("Q%d: %d\n", y++, st.Query(i, j)); break;
			}
		}
	}

}