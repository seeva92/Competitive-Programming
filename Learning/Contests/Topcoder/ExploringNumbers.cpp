#line 5 "ExploringNumbers.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 1000;
class ExploringNumbers {
public:
	bool isPrime(int n) {
		if (n == 1) return false;
		if (n == 2 || n == 3) return true;
		int size = sqrt(n);
		for (int i = 2; i <= size; i++) {
			if (n % i == 0) return false;
		}
		return true;
	}
	inline int getSum(int n) {
		int total = 0;
		while (n) {
			total += ((n % 10) * (n % 10));
			n /= 10;
		}
		return total;
	}
	int numberOfSteps(int n) {
		if (n == 1) return -1;
		if (isPrime(n)) return 1;
		int i, len;
		int temp = n;
		for (i = getSum(n), len = 2; len <= temp && !isPrime(i); i = getSum(i), len++) {
			if (i == 1) return -1;
		}
		if (len > n)  return -1;
		return len;
	}
};
// int main() {
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// 	ExploringNumbers s;
// 	cout << s.numberOfSteps(12366) << endl;
// 	cout << s.numberOfSteps(57) << endl;
// }


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
