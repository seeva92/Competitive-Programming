#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
struct P {
	int x, y;
};
struct T {
	P a, b, c;
};
struct Q {
	P a, b, c, d;
};
double getArea(T tmp) {
	return abs((tmp.a.x * (tmp.b.y - tmp.c.y)) - (tmp.a.y * (tmp.b.x - tmp.c.x)) + (1 * ((tmp.b.x * tmp.c.y) - (tmp.b.y * tmp.c.x)))) / double(2.0);
}
double eps = 1e-9;
int main() {
// #ifndef ONLINE_JUDGE
	// freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	// freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
// #endif
	int t;
	int x, y;
	scanf("%d", &t);
	while (t--) {
		T tr1, tr2;
		Q quad;
		scanf("%d %d %d %d %d %d", &tr1.a.x, &tr1.a.y, &tr1.b.x, &tr1.b.y, &tr1.c.x, &tr1.c.y);
		// printf("%d %d %d %d %d %d\n", tr1.a.x, tr1.a.y, tr1.b.x, tr1.b.y, tr1.c.x, tr1.c.y);
		scanf("%d %d %d %d %d %d", &tr2.a.x, &tr2.a.y, &tr2.b.x, &tr2.b.y, &tr2.c.x, &tr2.c.y);
		// printf("%d %d %d %d %d %d\n", tr2.a.x, tr2.a.y, tr2.b.x, tr2.b.y, tr2.c.x, tr2.c.y);
		scanf("%d %d %d %d %d %d %d %d", &quad.a.x, &quad.a.y, &quad.b.x, &quad.b.y, &quad.c.x, &quad.c.y, &quad.d.x, &quad.d.y);
		// printf("%d %d %d %d %d %d %d %d", quad.a.x, quad.a.y, quad.b.x, quad.b.y, quad.c.x, quad.c.y, quad.d.x, quad.d.y);
		double tr1_a = getArea(tr1);
		double tr2_a = getArea(tr2);
		double fs1, fs2, ss1, ss2;
		T tmp;
		tmp.a = quad.a; tmp.b = quad.b; tmp.c = quad.c;
		fs1 = getArea(tmp);
		tmp.a = quad.a; tmp.b = quad.d; tmp.c = quad.c;
		fs2 = getArea(tmp);
		tmp.a = quad.b; tmp.b = quad.c; tmp.c = quad.d;
		ss1 = getArea(tmp);
		tmp.a = quad.b; tmp.b = quad.a; tmp.c = quad.d;
		ss2 = getArea(tmp);
		if ((fs1 == tr1_a && fs2 == tr2_a) || (fs2 == tr1_a && fs1 == tr2_a))
			cout << "Yes";
		else if ((ss1 == tr1_a && ss2 == tr2_a) || (ss2 == tr1_a && ss1 == tr2_a))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}

}