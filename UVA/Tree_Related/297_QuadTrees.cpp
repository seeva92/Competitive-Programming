#include <bits/stdc++.h>
using namespace std;
class Tree {
private:
	struct QuadTree {
		int pixels, color;
		QuadTree *q[4];
		QuadTree(int p, int c) { pixels = p, color = c;}
	};
	string str;
public:
	QuadTree *root;
	Tree(char *p) {
		root = NewNode(1024, -1);
		str = string(p);
		int x = 0;
		if (str[x] == 'p') root->color = -1;
		else if (str[x] == 'e') root->color = 0;
		else if (str[x] == 'f') root->color = 1;
		BuildTree(++x, root);
	}
	QuadTree * NewNode(int p, int c) {
		QuadTree * tmp = new QuadTree(p, c);
		for (int i = 0; i < 4; i++) tmp->q[i] = NULL;
		return tmp;
	}
	void BuildTree(int &i, QuadTree * tmp) {
		for (int j = 0; j < 4; j++) {
			if (i == str.length()) return;
			if (str[i] == 'p') {
				tmp->q[j] = NewNode(tmp->pixels / 4, -1); ++i;
				BuildTree(i, tmp->q[j]);
			} else if (str[i] == 'e') {
				tmp->q[j] = NewNode(tmp->pixels / 4, 0); ++i;
			} else if (str[i] == 'f') {
				tmp->q[j] = NewNode(tmp->pixels / 4, 1); ++i;
			}
		}
	}
	int compare(QuadTree *tmp1, QuadTree *tmp2) {
		if (tmp1 == NULL && tmp2 == NULL) return 0;
		if (tmp1 != NULL && tmp1->color == 1) return tmp1->pixels;
		else if (tmp2 != NULL && tmp2->color == 1) return tmp2->pixels;
		int count = 0;
		for (int i = 0; i < 4; i++) {
			if (tmp1 != NULL && tmp2 != NULL) count += compare(tmp1->q[i], tmp2->q[i]);
			else if (tmp1 != NULL) count += compare(tmp1->q[i], tmp2);
			else count += compare(tmp1, tmp2->q[i]);
		}
		return count;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n;
	char s[100100];
	scanf("%d", &n);
	int count = 0;
	while (n--) {
		count = 0;
		scanf("%s", s); Tree t1(s); //t1.display(); printf("\n");
		scanf("%s", s); Tree t2(s); //t2.display(); printf("\n");
		printf("There are %d black pixels.\n", t1.compare(t1.root, t2.root));
	}

}