#line 5 "GerrymanderEasy.cpp"
#include <bits/stdc++.h>
using namespace std;
class GerrymanderEasy {
public:
	double getmax(vector <int> A, vector <int> B, int K) {
		double eps = 1e-9;
		long long btotal = 0, bsupport = 0, ctotal, csupport;
		bool flag = true;
		int len = int(A.size());
		for (int i = 0; i < len; i++) {
			ctotal = 0; csupport = 0;
			for (int j = i, k = 1; j < len; j++, k++) {
				ctotal += A[j]; csupport += B[j];
				// cout << ctotal << " " << csupport << " " << k << endl;
				if (k >= K) {
					if (flag) {
						flag = false;
						btotal = ctotal; bsupport = csupport;
					}
					else {
					double left = (double)csupport / (double)ctotal;
						double right = (double)bsupport / (double)btotal;
						if (left >= (right+eps)) {
							btotal = ctotal;
							bsupport = csupport;
							// cout << "Best " << btotal << " " << bsupport << endl;
						}
					}

				}
			}
			// cout << endl;
		}
		return (double)bsupport / (double)btotal;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
