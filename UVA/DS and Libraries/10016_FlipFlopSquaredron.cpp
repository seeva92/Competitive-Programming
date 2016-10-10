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


long long arr[110][110];
void upside(int n, int r) {
	int start = 1, end = n;
	for (int i = 0; i < r; i++) {
		start++; end--;
	}
	for (int i = start; i <= end; i++) {
		swap(arr[start][i], arr[end][i]);
	}
	for (int i = start + 1, j = end - 1; i < j; i++, j--) {
		swap(arr[i][start], arr[j][start]);
		swap(arr[i][end], arr[j][end]);
	}
}
void leftright(int n, int r) {
	int start = 1, end = n;
	for (int i = 0; i < r; ++i) {
		start++; end--;
	}
	for (int i = start; i <= end; i++) {
		swap(arr[i][start], arr[i][end]);
	}
	for (int i = start + 1, j = end - 1; i < j; i++, j--) {
		swap(arr[start][i], arr[start][j]);
		swap(arr[end][i], arr[end][j]);
	}
}
void diagonal(int n, int r) {
	int start = 1, end = n;
	for (int i = 0; i < r; i++) {
		start++; end--;
	}

	for (int i = start + 1; i < end; i++) {
		swap(arr[start][i], arr[i][start]);
		swap(arr[end][i], arr[i][end]);
	}
	swap(arr[start][end], arr[end][start]);
}
void inverse_diagonal(int n, int r) {
	int start = 1, end = n;
	for (int i = 0; i < r; i++) {
		start++; end--;
	}
	swap(arr[start][start], arr[end][end]);
	for (int i = start + 1, j = end - 1; (i < end) && (j > start); i++, j--) {
		swap(arr[start][i], arr[j][end]);
		swap(arr[i][start], arr[end][j]);
	}
}
void compute(int n, int c, int r) {
	switch (c) {
	case 1: upside(n, r);
		break;
	case 2: leftright(n, r);
		break;
	case 3: diagonal(n, r);
		break;
	case 4: inverse_diagonal(n, r);
		break;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int m, n, t, c, i, j, r;
	// scanf("%d", &m);
	cin >> m;
	while (m--) {
		memset(&arr[0][0], 0, sizeof arr);
		// scanf("%d", &n);
		cin >> n;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> arr[i][j];
		// scanf("%ld", &arr[i][j]);

		r = n % 2 == 0 ? n / 2 : (n / 2) + 1;
		for (int i = 0; i < r; i++) {
			// scanf("%d", &t);
			cin >> t;
			while (t--) {
				// scanf("%d", &c);
				cin >> c;
				compute(n, c, i);
			}
		}
		for (int i = 1; i <= n; i++, cout << '\n') { // printf("\n")) {
			int j;
			for (j = 1; j < n; j++)
				cout << arr[i][j] << " ";
			// printf("%ld ", arr[i][j]);
			cout << arr[i][j];
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
			int sign = +1; \
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

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

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
