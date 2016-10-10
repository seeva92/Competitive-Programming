// BEGIN CUT HERE
// PROBLEM STATEMENT
// Fox Ciel has a collection of bags.
Each of those bags contains some gemstones.
You are given the contents of the bags as a vector <string> bags.
Each element of bags represents one of the bags.
Different characters represent different gemstone types.
For example, if bags[2]="ABAC", we know that bag 2 contains two gems of type A, one gem of type B, and one gem of type C.


There are at most 16 different types of gems.
Gems of the same type always have the same weight.
Gems of different types always have different weights.
Each weight is some positive real number.


Fox Ciel wants to identify the heaviest of all her bags.
(It is possible that multiple bags are tied for being the heaviest.
In that case, Ciel wants to identify any one of those bags.)


Ciel has only one tool she can use while solving this task: a tiny balance scale.
The scale is so small that the only thing she can do is to compare the weights of two gems.
I.e., in each weighing she will take two gems of different types, place each of them onto one of the pans of the scale, determine which type of gems weighs more, and then she'll return both gems to their original places.
Ciel can use the scale arbitrarily many times.


You are given the vector <string> bags, but you don't know anything about the weights of the gems.
Return "Possible" if you can be sure that Ciel will be able to identify the heaviest bag.
Otherwise, return "Impossible".
In other words, return "Impossible" if there is some combination of weights of gemstone types such that Ciel won't be able to determine with certainty which bag is the heaviest one.

DEFINITION
Class:FoxAndGemstone
Method:isPossible
Parameters:vector <string>
Returns:string
Method signature:string isPossible(vector <string> bags)


CONSTRAINTS
-bags will contain between 2 and 50 elements, inclusive.
-Each element in bags will contain between 1 and 50 elements, inclusive.
-Each character in bags will be one of the first 16 uppercase English letters ('A'-'P').


EXAMPLES

0)
{"AB", "AC"}

Returns: "Possible"

Ciel just needs to compare a gem of type B and a gem of type C.
If B is heavier, bag 0 is the heaviest bag.
Otherwise, bag 1 is the heaviest bag.

1)
{"A", "BC"}

Returns: "Impossible"

This is an interesting situation.
For some combinations of weights Fox Ciel will find the heaviest bag.
For example, if she discovers that A < B, she can be certain that the bag "BC" is heavier than the bag "A".


However, there are some combinations of weights for which Ciel won't be successful.
For example, suppose she weighs the gems and she finds out that A > B > C.
Given the above information, it is possible that A > B+C, but it is also possible that A < B+C.
In this situation, Ciel has no way of telling which bag is the heavier one.

2)
{"A", "B", "C", "AB", "AC", "BC", "ABC"}

Returns: "Possible"

Here Ciel doesn't need the scale at all, she can simply choose the last bag.

3)
{"AB","AC","AD","BC","BD","CD"}

Returns: "Possible"



4)
{"AB", "CD"}

Returns: "Impossible"



5)
{"A", "A", "A"}

Returns: "Possible"



// END CUT HERE
#line 103 "FoxAndGemstone.cpp"
#include <string>
#include <vector>
#include <bits/stdc++.h>
class FoxAndGemstone {
	public:
	string isPossible(vector <string> bags) {
		
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	
}
