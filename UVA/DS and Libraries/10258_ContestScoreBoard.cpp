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
struct Contestant {
	int no;
	int solved[12] = {0};
	int failed[12] = {0};
	int count = 0;
	int total = 0;
};
bool compare(Contestant c1, Contestant c2) {
	if (c1.count < c2.count)
		return false;
	else if (c1.count == c2.count) {
		if (c1.total > c2.total)
			return false;
		else if (c1.total == c2.total) {
			if (c1.no > c2.no)
				return false;
			return true;
		}
		return true;
	}
	return true;
}
#define PENALTY 20
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t;
	string str;
	cin >> t;
	cin.ignore(1000, '\n');
	getline(cin, str);

	stringstream ss;
	register int no, prob, ms;
	register char c;
	while (t--) {
		map<int, Contestant> mp;
		while (getline(cin, str)) {
			if (str.back() == '\r')
				str.pop_back();

			if (str == "")
				break;
			ss << str;
			ss >> no >> prob >> ms;
			ss >> c;
			Contestant contestant;

			if (mp.find(no) == mp.end()) {
				contestant.no = no;
			} else {
				contestant = mp[no];
			}
			if (c == 'C') {
				if (contestant.solved[prob] == 0) {
					contestant.solved[prob] = 1;
					contestant.count++;
					contestant.total += ms;
					contestant.total += (contestant.failed[prob] * PENALTY);
				}
			} else if (c == 'I') {
				if (contestant.solved[prob] == 0) {
					contestant.failed[prob]++;
				}
			}
			mp[no] = contestant;
		}

		vector<Contestant> conlist;
		for (map<int, Contestant>::iterator it = mp.begin(); it != mp.end(); it++)
			conlist.push_back(it->second);

		sort(conlist.begin(), conlist.end(), compare);
		for (auto it : conlist)
			cout << it.no << " " << it.count << " " << it.total << '\n';
		if (t != 0)
			cout << '\n';
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
