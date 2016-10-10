#line 5 "Genetics.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class Genetics {
public:
	string getOffspring(string g1, string g2, string dom) {
		string res = "";
		for (int i = 0; i < int(g1.size()); i++) {
			if (g1[i] == g2[i]) res += g1[i];
			else if (dom[i] == 'D') {
				if ('A' <= g1[i] && g1[i] <= 'Z') res += g1[i];
				else if ('A' <= g2[i] && g2[i] <= 'Z') res += g2[i];
			} else {
				if ('a' <= g1[i] && g1[i] <= 'z') res += g1[i];
				else if ('a' <= g2[i] && g2[i] <= 'z') res += g2[i];
			}
		}
		return res;
	}
};
