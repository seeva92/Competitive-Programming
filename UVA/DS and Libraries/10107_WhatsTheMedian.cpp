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
#include <map>
#include <queue>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#define getc_unlocked getc
#define putc_unlocked putc
#endif
using namespace std;
int carr[10000 + 10];
void scanint(long long int &x)
{
	register long long int c = getc_unlocked(stdin);
	x = 0;
	for (; (c < 48 || c > 57) && c != EOF; c = getc_unlocked(stdin));
	for (; c > 47 && c < 58; c = getc_unlocked(stdin)) {x = (x << 1) + (x << 3) + c - 48;}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	register long long int n = 0, x = 0;
	register long long  int N;
	register int m1, m2;
	priority_queue<long long int, vector<long long int>, greater<long long int>> minqueue;
	priority_queue<long long int> maxqueue;
	long long int count = 1;
	long long int val1 = 0, val2 = 0;
	while (scanint(n), n != 0) {
		if (((int)maxqueue.size() == (int)minqueue.size())) {
			if (maxqueue.empty())
				maxqueue.push(n);
			else if (minqueue.empty() || n < minqueue.top())
				maxqueue.push(n);
			else {

				maxqueue.push(minqueue.top());
				minqueue.pop();
				minqueue.push(n);
			}
		} else if (((int)maxqueue.size() > (int)minqueue.size())) {
			if (maxqueue.empty() || maxqueue.top() > n) {
				minqueue.push(maxqueue.top());
				maxqueue.pop();
				maxqueue.push(n);
			} else
				minqueue.push(n);
		}
		// if (maxqueue.empty())
		// 	maxqueue.push(n);
		// else {
		// 	if (n <= maxqueue.top()) {
		// 		if (((int)maxqueue.size() == (int)minqueue.size()) < 1)
		// 			maxqueue.push(n);
		// 		else {
		// 			if (!maxqueue.empty()) {
		// 				minqueue.push(maxqueue.top());
		// 				maxqueue.pop();
		// 				maxqueue.push(n);
		// 			} else {
		// 				maxqueue.push(n);
		// 			}

		// 		}
		// 	} else {
		// 		if (((int)minqueue.size() - (int)maxqueue.size()) < 0) {
		// 			minqueue.push(n);
		// 		}
		// 		else {
		// 			if (!minqueue.empty()) {
		// 				maxqueue.push(n);
		// 				minqueue.pop();
		// 				minqueue.push(n);
		// 			} else {
		// 				minqueue.push(n);
		// 			}

		// 		}
		// 	}
		// priority_queue<long long int> temp1 = maxqueue;
		// priority_queue<long long int, vector<long long int>, greater<long long int>> temp2 = minqueue;
		// printf("Case %d:\n", count);
		// while (!temp1.empty()) {
		// 	printf("%ld ", temp1.top()); temp1.pop();
		// }
		// printf("\n");
		// while (!temp2.empty()) {
		// 	printf("%ld ", temp2.top()); temp2.pop();
		// }
		// printf("\n");

		val1 = !maxqueue.empty() ? maxqueue.top() : 0;
		val2 = !minqueue.empty() ? minqueue.top() : 0;
		// cout << "Maxqueue :" << val1 << " Minqueue :" << val2 << '\n';
		// cout << "Answer : ";
		if (count % 2 == 0)
			cout << (val1 + val2) / 2 << '\n';
		else
			cout << val1	 << '\n';
		count++;
	}


}

static struct IO {
	char tmp[1 << 23];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0;
		} return *this;
	}

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {
			s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar();
		}
		return *this;
	}

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			register int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

	defineInFor(int)
	defineInFor(unsigned int)
	defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (register int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

	defineOutFor(int)
	defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
