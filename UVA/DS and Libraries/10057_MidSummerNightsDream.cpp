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
#include <unordered_map>
#ifndef ONLINE_JUDGE
#define getc_unlocked getc
#define putc_unlocked putc
#endif
using namespace std;
int carr[65536 + 10];
void scanint(int &x)
{
	register int c = getc_unlocked(stdin);
	x = 0;
	for (; (c < 48 || c > 57) && c != EOF; c = getc_unlocked(stdin));
	for (; c > 47 && c < 58; c = getc_unlocked(stdin)) {x = (x << 1) + (x << 3) + c - 48;}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	register int n = 0, x = 0;
	register int N;
	register int m1, m2;
	while (scanint(n), n != 0) {
		N = n;
		memset(carr, 0, sizeof carr);
		while (n--) {
			scanint(x);
			carr[x]++;
		}
		register int i;
		register int m1Idx = 0, m2Idx = 0;
		register int m1pos = 0, m2pos = 0;
		bool m1flag = false, m2flag = false;
		if (N % 2 == 0) {
			for (i = 0; i <= 65537; i++) {
				if (!m1flag)
					m1pos += carr[i];
				if (!m2flag)
					m2pos += carr[i];
				if (!m1flag && m1pos >= (N / 2)) {
					m1flag = true;
					m1Idx = i;
				}
				if (!m2flag && m2pos >= (N / 2 + 1)) {
					m2flag = true;
					m2Idx = i;
					break;
				}
			}
			// printf("%d", m1Idx);
			cout << m1Idx;
			if (m1Idx != m2Idx)
				cout << " " << carr[m1Idx] + carr[m2Idx];

			// printf(" %d", carr[m1Idx] + carr[m2Idx]);
			else
				cout << " " << carr[m1Idx];

			// printf(" %d", carr[m1Idx]);
			// printf(" %d\n", m2Idx - m1Idx + 1);
			cout << " " << m2Idx - m1Idx + 1 << '\n';

		} else {
			for (i = 0; i <= 65537; i++) {
				m1pos += carr[i];
				if (m1pos > (N / 2)) {
					m1Idx = i; break;
				}
			}
			// printf("%d", m1Idx);
			// printf(" %d", carr[m1Idx]);
			// printf(" 1\n");
			cout << m1Idx << " " << carr[m1Idx] << " " << 1 << '\n';

		}
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
