// BEGIN CUT HERE
// PROBLEM STATEMENT
// For the purposes of this problem, a DNA sequence is a string consisting of the letters A, C, G, and T.
/*
You have been hired to help researchers at TopBiologist uncover the secrets of the human genome. The researchers have identified a DNA sequence, which is given to you in the string sequence. They have asked you to write a program which finds the shortest DNA sequence that is not contained in sequence.

For example, if sequence is the string "AGGTCTA", then one possible answer would be the string "AC". Other solutions, such as "CC", would also be accepted. "AG" would be an invalid answer because "AG" is contained in sequence. "AAA" would also be invalid: although it isn't contained in sequence, it is 3 characters long, and there are better answers which are only 2 characters long.

You are not really sure how this could possibly help anyone's research, but it's not your job to question TopBiologist. Find and return the shortest DNA sequence which is not contained in sequence. If there are multiple possible answers, you may return any of them.

DEFINITION
Class:TopBiologist
Method:findShortestNewSequence
Parameters:string
Returns:string
Method signature:string findShortestNewSequence(string sequence)


NOTES
-Formally, we say that sequence X is contained in sequence Y if we can obtain X by erasing some (possibly none) elements from the beginning and from the end of Y. For example, "AB" is contained in "ABC", but "AC" is not contained in "ABC".


CONSTRAINTS
-sequence will contain between 1 and 2000 characters, inclusive.
-Each character of sequence will be A, C, G, or T.


EXAMPLES

0)
"AGGTCTA"

Returns: "AC"

This is the example from the problem statement. Any of the following answers will be accepted: "AA", "AC", "AT", "CA", "CC", "CG", "GA", "GC", "TG", and "TT".

1)
"AGACGACGGAGAACGA"

Returns: "T"



2)
"A"

Returns: "C"



3)
"AAGATACACCGGCTTCGTG"

Returns: "CAT"

*/

// END CUT HERE
// #line 60 "TopBiologist.cpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TopBiologist {
	string dna = "ACGT";
	string res = "";
	bool flag = true;
	public:		
	void GenerateSeq(string sequence,string newseq,int k){
		if(k==0){
			// cout<<newseq<<endl;
			if(sequence.find(newseq)== string::npos){
				res = newseq;
				flag = false;
				return;
			}
		}else{
			int len = dna.length();
			for(int i=0;i<len ;i++)
				GenerateSeq(sequence,newseq+dna[i],k-1);			
		}
	}	
	string findShortestNewSequence(string sequence) {
		int len = sequence.length();
		for(int i=0;i<len && flag;i++)
			GenerateSeq(sequence,"",i+1);
		return res;
	}
};
// int main(){
// 	TopBiologist tp;
// 	cout<<tp.findShortestNewSequence("AAGATACACCGGCTTCGTG");
// }
