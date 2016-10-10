
// END CUT HERE
#line 98 "FriendlyRobot.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
class FriendlyRobot {
	int mem[310][310];
	int n;
	string s;
public:
	int solve(int idx, int mod) {
		if (idx == n) return 0;
		if (mem[idx][mod] != -1) return mem[idx][mod];
		mem[idx][mod] = 0;
		int x = 0, y = 0;
		for (int i = idx; i < n; i++) {
			switch (s[i]) {
			case 'U': ++x; break;
			case 'D': --x; break;
			case 'L': --y; break;
			case 'R': ++y; break;
			}
			if ((abs(x) + abs(y)) & 1) continue;
			if ((abs(x) + abs(y)) / 2 > mod) continue;
			mem[idx][mod] = max(mem[idx][mod], 1 + solve(i + 1, mod - ((abs(x) + abs(y)) / 2)));
		}
		return mem[idx][mod];
	}
	int findMaximumReturns(string instructions, int changesAllowed) {
		memset(mem, -1, sizeof mem);
		s = instructions;
		n = s.size();
		return solve(0, changesAllowed);
	}
};
