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
struct Team {
	string name;
	int scored = 0;
	int suffered = 0;
	int points = 0;
	int played = 0;
	int difference = 0;
	int idx = 0;
};
int getpoints(int goal1, int goal2) {
	if (goal1 == goal2)
		return 1;
	else if (goal1 > goal2)
		return 3;
	return 0;
}
bool compare(Team team1, Team team2) {
	if (team1.points > team2.points)
		return true;
	else if (team1.points == team2.points) {
		if (team1.difference > team2.difference)
			return true;
		else if (team1.difference == team2.difference) {
			if (team1.scored > team2.scored)
				return true;
			else if (team1.scored == team2.scored) {
				transform(team1.name.begin(), team1.name.end(), team1.name.begin(), ::tolower);
				transform(team2.name.begin(), team2.name.end(), team2.name.begin(), ::tolower);
				if (team1.name <= team2.name)
					return true;
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	register int g, t;

	string str;
	register int goal1, goal2;
	char c;
	cin >> g >> t;
	while (g || t) {
		map<string, int> teamMap;
		vector<Team> teamList;
		int idx = 0;
		while (g--) {
			cin >> str;
			Team team; team.name = str; team.idx = idx;
			teamList.push_back(team);
			teamMap[str] = idx++;
		}
		while (t--) {
			cin >> str >> goal1 >> c >> goal2;
			Team & team = teamList[teamMap[str]];
			team.scored += goal1;
			team.suffered += goal2;
			team.points += getpoints(goal1, goal2);
			team.played++; team.difference = team.scored - team.suffered;



			cin >> str;
			Team &team1 = teamList[teamMap[str]];
			team1.scored += goal2;
			team1.suffered += goal1;
			team1.points += getpoints(goal2, goal1);
			team1.played++; team1.difference = team1.scored - team1.suffered;
		}


		stable_sort(teamList.begin(), teamList.end(), compare);
		double result = 0.0f;
		char na[] = "N/A";
		for (int i = 1; i <= (int)teamList.size(); i++) {
			result = ((double(teamList[i - 1].points)) / (double(teamList[i - 1].played * 3))) * (double(100));
			if (i - 2 >= 0) {
				if ((teamList[i - 1].points == teamList[i - 2].points) && (teamList[i - 1].difference == teamList[i - 2].difference) && (teamList[i - 1].scored == teamList[i - 2].scored))
					printf("%19s%4d%4d%4d%4d%4d ", teamList[i - 1].name.c_str(), teamList[i - 1].points, teamList[i - 1].played, teamList[i - 1].scored, teamList[i - 1].suffered, teamList[i - 1].difference);
				else
					printf("%2d.%16s%4d%4d%4d%4d%4d ", i, teamList[i - 1].name.c_str(), teamList[i - 1].points, teamList[i - 1].played, teamList[i - 1].scored, teamList[i - 1].suffered, teamList[i - 1].difference);
			} else
				printf("%2d.%16s%4d%4d%4d%4d%4d ", i, teamList[i - 1].name.c_str(), teamList[i - 1].points, teamList[i - 1].played, teamList[i - 1].scored, teamList[i - 1].suffered, teamList[i - 1].difference);

			if (result != result)
				printf("%6s\n", na);
			else
				printf("%6.2f\n", result);
		}
		cin >> g >> t;
		if (g != 0 && t != 0)
			printf("\n");

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
