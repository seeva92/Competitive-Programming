// BEGIN CUT HERE
// PROBLEM STATEMENT
// For the purposes of this problem, a DNA sequence is a string consisting of the letters A, C, G, and T.
/*
You have been hired by researchers at TopBiologist to help them with some programming tasks. The researchers have found a sequence of uppercase letters, which is given to you in the string sequence. They have asked you to write a program which find the length of the longest DNA sequence that is a substring of sequence.

A substring can be obtained from sequence by deleting some (possibly zero) characters from the beginning or end. For example, suppose sequence is the string "TOPBOATER". Then "TOP", "PBOA", "T", and "AT" are some examples of substrings of sequence. Of these examples, "T" and "AT" are DNA sequences. The answer to the problem would be 2 because "AT" is the longest such sequence and its length is 2.

Please find and return the length of the longest DNA sequence that is a substring of sequence.

DEFINITION
Class:DNASequence
Method:longestDNASequence
Parameters:string
Returns:int
Method signature:int longestDNASequence(string sequence)


CONSTRAINTS
-sequence will contain between 1 and 50 characters, inclusive.
-Each character of sequence will be an upper-case English letter ('A'-'Z').


EXAMPLES

0)
"TOPBOATER"

Returns: 2

This is the example from the problem statement.

1)
"SUSHI"

Returns: 0

None of the substrings of "SUSHI" are DNA sequences, so the answer is 0.

2)
"GATTACA"

Returns: 7



3)
"GOODLUCK"

Returns: 1



4)
"VVZWKCSIQEGANULDLZESHUYHUQGRKUMFCGTATGOHMLKBIRCA"

Returns: 6

*/

// END CUT HERE
// #line 63 "DNASequence.cpp"
#include <string>
#include <vector>
#include <climits>
using namespace std;
class DNASequence {
	public:
	int longestDNASequence(string sequence) {
		int len = sequence.length();
		int max_length = 0;
		for(int i=0;i<len;i++){
			int curr_len = 0;
			for(int j=i;j<len;j++) 
				if(sequence[j]=='A' || sequence[j]=='C' || sequence[j]=='G' || sequence[j]=='T')
					curr_len++;
				else
					break;
			max_length = max(max_length,curr_len);
		}

		return max_length;
	}

};
// int main(){

// }
