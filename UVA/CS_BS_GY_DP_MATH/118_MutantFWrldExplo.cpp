#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
int r, c, x, y; char orient;
char arr[256];
int rect[100][100] = {0};
bool flag = false;
void process(char act) {
	int p_x = x, p_y = y;
	switch (act) {
	case 'L': switch (orient) {
		case 'N': orient = 'W'; break;
		case 'S': orient = 'E'; break;
		case 'W': orient = 'S'; break;
		case 'E': orient = 'N'; break;
		}
		break;
	case 'R':
		switch (orient) {
		case 'N': orient = 'E'; break;
		case 'S': orient = 'W'; break;
		case 'W': orient = 'N'; break;
		case 'E': orient = 'S'; break;
		}
		break;
	case 'F':
		switch (orient) {
		case 'N': y++; break;
		case 'S': y--; break;
		case 'E': x++; break;
		case 'W': x--; break;
		}
		break;
	}
	if (x < 0 || x > r || y < 0 || y > c) {
		if (rect[p_x][p_y] == 0) {
			flag = true; rect[p_x][p_y] = 1; x = p_x; y = p_y;
		} else {
			x = p_x; y = p_y;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	scanf("%d %d", &r, &c);
	while (scanf("%d %d %c", &x, &y, &orient) != EOF) {
		scanf("%s", &arr); int len = strlen(arr);
		flag = false;
		for (int i = 0; i < len; i++) {
			if (!flag) process(arr[i]);
		}
		printf("%d %d %c", x, y, orient);
		if (flag) printf(" LOST");
		printf("\n");
	}
}