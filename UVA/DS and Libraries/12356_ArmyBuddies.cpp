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
// 	//My Approach

// int main() {
// 	// std::ios_base::sync_with_stdio(false);
// 	// freopen("1.txt", "r", stdin);
// 	// freopen("2.txt", "w", stdout);

// 	int n, b, l, r;
// 	while (scanf("%d %d", &n, &b), n || b) {
// 		set<int> st;
// 		for (int i = 1; i <= n; i++)
// 			st.insert(i);


// 		for (int i = 1; i <= b; i++) {
// 			scanf("%d %d", &l, &r);

// 			set<int>::iterator left = st.lower_bound(l);
// 			set<int>::iterator right = st.upper_bound(r);
// 			set<int>::iterator leftBefore = prev(left, 1); //leftBefore--;
// 			// set<int>::iterator rightAfter = next(right, 1); //rightAfter++;
// 			if (left == st.begin())
// 				printf("* ");
// 			else
// 				printf("%d ", *leftBefore);

// 			if (right == st.end())
// 				printf("*\n");
// 			else
// 				printf("%d\n", *right);

// 			st.erase(left, right);
// 			// cout << *leftBefore << " " << *rightAfter << '\n';
// 			// for (auto it = st.begin(); it != st.end(); it++)
// 			// 	cout << *it << " "; cout << endl;


// 		}
// 		printf("-\n");
// 	}

// }

//Optimised Approach
int L[(int)1e5 + 10];
int R[(int)1e5 + 10];
int main() {
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);

	int n, b, l, r;
	while (scanf("%d %d", &n, &b), n || b) {
		memset(L,0,sizeof L);
		memset(R,0,sizeof R);
		for (int i = 1; i <= n; i++) {
			L[i] = i - 1; R[i] = i + 1;
		}

		for (int i = 1; i <= b; i++) {
			scanf("%d %d", &l, &r);
			if (L[l] < 1)
				printf("* ");
			else
				printf("%d ", L[l]);

			if (R[r] > n)
				printf("*\n");
			else
				printf("%d\n", R[r]);

			L[R[r]] = L[l];
			R[L[l]] = R[r];
		}
		printf("-\n");

	}
}