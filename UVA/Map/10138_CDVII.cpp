#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
int timings[24];
char colon;
struct tollrec {
	string car;
	int mm, dd, hh, mins, loc;
	int seconds;
	bool enter = true;
};
bool compare(tollrec a, tollrec b) {
	if (a.car < b.car)
		return true;
	else if (a.car == b.car) {
		if (a.mm < b.mm)
			return true;
		else if (a.mm == b.mm) {
			if (a.dd < b.dd)
				return true;
			else if (a.dd == b.dd) {
				if (a.hh < b.hh)
					return true;
				else if (a.hh == b.hh) {
					if (a.mins <= b.mins)
						return true;
				}
			}
		}
	}
	return false;
}
string car;
int mm, dd, hh, mins, loc;
string enter;

int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif

	string str;


	int n;
	cin >> n; cin.ignore();
	getline(cin, str);

	while (n--) {
		memset(timings, 0, sizeof timings);
		getline(cin, str);
		stringstream ss; ss << str;
		for (int i = 0; i < 24; i++) {
			ss >> timings[i];
		}
		std::vector<tollrec> v;
		map<string, double> mp;
		map<string, int> count;
		while (getline(cin, str), str != "") {
			ss.clear();
			ss << str;
			ss >> car; ss >> colon;
			ss >> mm >> colon >> dd >> colon >> hh >> colon >> mins >> enter >> loc;
			tollrec rec;

			rec.car = car; rec.mm == mm; rec.dd = dd; rec.hh = hh; rec.mins = mins; rec.loc = loc;
			rec.enter = enter == "enter" ? true : false;
			v.push_back(rec);
		}
		sort(v.begin(), v.end(), compare);
		// for (auto it : v) {
		// 	if (it.car == "6D51YFQB")
		// 		cout << it.car << " " << it.mm << " " << it.dd << " " << it.hh << " " << it.mins << " " << it.enter << " " << it.loc << '\n';
		// }
		for (int i = 0; i < (int)(v.size() - 1);) {
			if (v[i].car == v[i + 1].car) {
				if (v[i].enter && !v[i + 1].enter) {
					mp[v[i].car] += (abs(v[i + 1].loc - v[i].loc)) * timings[v[i].hh];
					count[v[i].car]++;
					i += 2;
					continue;
				}
			}

			i++;
		}
		for (auto it : mp) {
			printf("%s $%0.2f\n", it.first.c_str(), ((it.second / double(100)) + count[it.first] + 2.0));
		}
		if (n != 0)
			printf("\n");
	}
}

