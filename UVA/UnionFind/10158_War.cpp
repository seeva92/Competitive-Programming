#include <bits/stdc++.h>
using namespace std;
vector<int> friends[10009];
bitset<10009> fv, efv, ev;
vector<int> enemies[10009];
set<int> enemyset[10009];
bool isEnemy(int x, int y) {
	if (enemyset[x].find(y) != enemyset[x].end()) return true;
	return false;
}
bool isFriendEnemy(int x, int y) {
	ev[x] = 1;
	for (int i = 0; i < (int)friends[x].size(); i++) {
		if (!ev[friends[x][i]]) {
			if (enemyset[friends[x][i]].find(y) != enemyset[friends[x][i]].end()) return true;
			else isFriendEnemy(friends[x][i], y);
		}
	}
	return false;
}
bool isFriend(int x, int y) {
	fv[x] = 1;
	for (int i = 0; i < (int)friends[x].size(); i++)
		if (!fv[friends[x][i]]) {
			if (friends[x][i] == y) return true;
			else isFriend(friends[x][i], y);
		}
	return false;
}
bool isEnemyFriend(int p, int x, int y) {
	efv[x] = 1;
	for (int i = 0; i < (int)enemies[x].size(); i++)
		if (!efv[enemies[x][i]]) {
			if (p != x && enemies[x][i] == y) return true;
			else isEnemyFriend(x, enemies[x][i], y);
		}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	int c, x, y;
	while (scanf("%d %d %d", &c, &x, &y), c || x || y) {
		fv.reset(); efv.reset(); ev.reset();
		switch (c) {
		case 1:
			if (isEnemy(x, y) || isFriendEnemy(x, y)) printf("-1\n");
			else {
				ev.reset();
				if (isFriendEnemy(y, x)) printf("-1\n");
				else {friends[x].push_back(y); friends[y].push_back(x);}
			}
			break;
		case 2:
			if (isFriend(x, y) || isEnemyFriend(-1, x, y)) printf("-1\n");
			else {
				enemies[x].push_back(y); enemies[y].push_back(x);
				enemyset[x].insert(y); enemyset[y].insert(x);
			}
			break;
		case 3:
			if (x == y || isFriend(x, y) || isEnemyFriend(-1, x, y)) printf("1\n");
			else printf("0\n");
			break;
		case 4:
			if (isEnemy(x, y) || isFriendEnemy(x, y)) printf("1\n");
			else {
				ev.reset();
				if (isFriendEnemy(y, x)) printf("1\n");
				else printf("0\n");
			}
			break;
		}
	}

}
// class UFDS {
// private:
// 	vector<int> v, rank, stsize;
// public:
// 	UFDS(int n) {
// 		v.assign(n, 0); rank.assign(n, 0); stsize.assign(n, 1);
// 		for (int i = 0; i < n; i++) v[i] = i;
// 	}
// 	int findSet(int i) { return v[i] == i ? i : (v[i] = findSet(v[i]));}
// 	bool isSameSet(int i, int j) { return findSet(i) == findSet(j);}
// 	void unionSet(int i, int j) {
// 		int x = findSet(i); int y = findSet(j);
// 		if (x != y) {
// 			if (rank[x] < rank[y]) {
// 				stsize[y] += stsize[x];
// 				v[x] = y;
// 			}
// 			else {
// 				stsize[x] += stsize[y];
// 				v[y] = x;
// 				if (rank[x] == rank[y]) rank[x]++;
// 			}

// 		}
// 	}
// 	int getSize(int i) { return stsize[findSet(i)];}
// };
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int n; scanf("%d", &n);
// 	int c, x, y;
// 	UFDS friends(n);
// 	UFDS enemies(n);
// 	while (scanf("%d %d %d", &c, &x, &y), c || x || y) {
// 		switch (c) {
// 		case 1: if (enemies.isSameSet(x, y)) printf("-1\n");
// 			else friends.unionSet(x, y);
// 			break;
// 		case 2:
// 			if (friends.isSameSet(x, y)) printf("-1\n");
// 			else enemies.unionSet(x, y);
// 			break;
// 		case 3:
// 			if (friends.isSameSet(x, y)) printf("1\n");
// 			else printf("0\n");
// 			break;
// 		case 4:
// 			if (enemies.isSameSet(x, y)) printf("1\n");
// 			else printf("0\n");
// 			break;
// 		}
// 	}

// }