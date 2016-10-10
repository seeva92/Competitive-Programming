// BEGIN CUT HERE
// PROBLEM STATEMENT
// An ordered triple (a, b, c) is called a triangle triple if a, b, c are positive integers such that there is a triangle with side lengths a, b, c and a positive area.

For example, (4, 5, 6) and (5, 4, 6) are two different triangle triples.
On the other hand, (1, 2, 3) and (47, 5, 5) are not triangle triples.

You are given the ints A, B, and C.
Let X be the number of triangle triples (a, b, c) such that 1 <= a <= A, 1 <= b <= B, and 1 <= c <= C.
Compute and return the value (X modulo 1,000,000,007).

DEFINITION
Class:TriangleTriples
Method:count
Parameters:int, int, int
Returns:int
Method signature:int count(int A, int B, int C)


CONSTRAINTS
-A will be between 1 and 1,000,000,000, inclusive.
-B will be between 1 and 1,000,000,000, inclusive.
-C will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
1
10
20

Returns: 10

We have 10 such triples: (1,1,1), (1,2,2), (1,3,3), ..., (1,10,10).

1)
2
2
1000000000

Returns: 6

This time we have: (1,1,1), (1,2,2), (2,1,2), (2,2,1), (2,2,2) and (2,2,3).

2)
10
10
10

Returns: 505



3)
1
1
1

Returns: 1



4)
123456789
987654321
555555555

Returns: 64296241



// END CUT HERE
#line 75 "TriangleTriples.cpp"
#include <string>
#include <vector>
#include <bits/stdc++.h>
class TriangleTriples {
	public:
	int count(int A, int B, int C) {
		
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	
}
