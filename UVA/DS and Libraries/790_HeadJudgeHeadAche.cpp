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
#define penalty 1200
struct Team {
	int no;
	int solved[10] = {0};
	int failed[10] = {0};
	int count = 0;
	long long seconds = 0;
};
struct Input {
	int no;
	char prob;
	long long seconds;
	char status;
};
bool compare(Team team1, Team team2) {
	if (team1.count < team2.count)
		return false;
	else if (team1.count == team2.count) {
		if (team1.seconds > team2.seconds)
			return false;
		else if (team1.seconds == team2.seconds) {
			if (team1.no > team2.no)
				return false;
			return true;
		}
		return true;
	}
	return true;
}
bool comparebyseconds(Input team1, Input team2) {
	if (team1.seconds < team2.seconds)
		return true;
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif

	int no, h, m;
	char status, prob;
	char t[10];
	char buffer[100];
	int T;
	string str;
	stringstream ss;
	cin >> T;
	int temp = T;
	cin.ignore(1000, '\n');
	getline(cin, str);
	while (T--) {
		map<int, Team> teamMap;
		int maxTeam = 0;
		vector<Input> inputlist;

		//Reading the input
		while (getline(cin, str)) {
			if (str.back() == '\r')
				str.pop_back();
			if (str == "")
				break;
			ss << str;
			ss >> no; ss >> prob; ss >> t; ss >> status;
			sscanf(t, "%d:%d", &h, &m);
			if (maxTeam < no)
				maxTeam = no;
			Input input;
			input.no = no; input.prob = prob; input.seconds = (h * 60 * 60) + (m * 60);
			input.status = status;
			inputlist.push_back(input);
		}
		//Sort the input by time
		stable_sort(inputlist.begin(), inputlist.end(), comparebyseconds);

		// Processing the input list
		for (auto it : inputlist) {
			// cout << it.no << " " << it.prob << " " << it.seconds << " " << it.status << "\n";
			Team team;
			if (teamMap.find(it.no) == teamMap.end()) {
				team.no = it.no;
				if (it.status == 'Y') {
					team.solved[(it.prob) - 'A'] = 1;
					team.count++;
					team.seconds = it.seconds;
				}
				else
					team.failed[(it.prob) - 'A'] += 1;
			} else {
				team = teamMap[it.no];
				if (it.status == 'Y') {
					if (team.solved[(it.prob) - 'A'] == 0) {
						team.solved[(it.prob) - 'A'] = 1;
						team.count++;
						team.seconds += it.seconds;
						team.seconds += (team.failed[(it.prob) - 'A'] * penalty);
					}
				} else {
					if (team.solved[(it.prob) - 'A'] == 0) {
						team.failed[(it.prob) - 'A'] += 1;
					}
				}
			}
			teamMap[it.no] = team;
		}

		//Building the list of teams
		vector<Team> teamlist;
		for (auto it : teamMap) {
			teamlist.push_back(it.second);
		}
		for (int i = 1; i <= maxTeam; i++) {
			if (teamMap.find(i) != teamMap.end())
				continue;
			Team team;
			team.no = i;
			teamMap[i] = team;
			teamlist.push_back(team);
		}
		sort(teamlist.begin(), teamlist.end(), compare);

		int rank;
		//Print appropriately
		cout << "RANK TEAM PRO/SOLVED TIME\n";
		int size = (int)teamlist.size();
		for (int i = 0; i < size; i++) {
			if (i != 0 && teamlist[i].count == teamlist[i - 1].count && teamlist[i].seconds == teamlist[i - 1].seconds) {
				printf("%4d %4d", rank, teamlist[i].no);
			} else {
				printf("%4d %4d", i + 1, teamlist[i].no);
				rank = i + 1;
			}

			if (teamlist[i].count != 0) {
				printf(" %4d %10ld", teamlist[i].count, teamlist[i].seconds / 60);
			}
			printf("\n");
		}
		if (T != 0)
			printf("\n");
	}


// teamlist.assign(teamMap.begin(), teamMap.end());

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
