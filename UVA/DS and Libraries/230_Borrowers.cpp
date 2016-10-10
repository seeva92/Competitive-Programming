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
#include <unordered_map>
using namespace std;
struct Book {
	string title;
	string author;
	int state;
};
bool comparator(const Book &a, const Book &b) {
	int auth = (int)a.author.compare(b.author);
	int tit = (int)a.title.compare(b.title);
	if (auth == 0) {
		if (tit <= 0)
			return true;
		else
			return false;
	} else if (auth < 0)
		return true;

	return false;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	string str;
	vector<Book> v;
	while (getline(cin, str)) {
		if (str.back() == '\r')
			str.pop_back();
		if (str == "END")
			break;
		size_t found = str.find("\"", 1);
		Book b;
		b.title = str.substr(1, found - 1);
		b.author = str.substr(found + 5);
		b.state = 0;
		// cout << b.title << " " << b.author << endl;
		v.push_back(b);
	}
	sort(v.begin(), v.end(), comparator);
	unordered_map<string, int> titleIndex;
	for (int i = 0; i < (int)v.size(); i++)
		titleIndex[v[i].title] = i;

	// for (int i = 0; i < (int)v.size(); i++)
	// 	cout << v[i].title << " " << v[i].author << " " << v[i].state << endl;


	string cmd;
	while (getline(cin, str)) {
		if (str.back() == '\r')
			str.pop_back();
		// cout << str << endl;
		if (str == "END")
			break;
		// for (int i = 0; i < (int)v.size(); i++)
		// 	cout << v[i].title << " " << v[i].author << " " << v[i].state << endl;
		// 	cout << endl;
		if (str.find("BORROW") != -1)
			v[titleIndex[str.substr(8, str.find_last_of("\"") - 8)]].state = 1;
		else if (str.find("RETURN") != -1)
			v[titleIndex[str.substr(8, str.find_last_of("\"") - 8)]].state = 2;
		else {

			for (int i = 0; i < (int)v.size(); i++)
				if (v[i].state == 2) {
					int j;
					for (j = i - 1; j >= 0 && v[j].state != 0; j--);
					if (j < 0)
						cout << "Put \"" << v[i].title << "\" first\n";
					else
						cout << "Put \"" << v[i].title << "\" after \"" << v[j].title << "\"\n";
					v[i].state = 0;
				}
			cout << "END" << endl;
		}

	}
}