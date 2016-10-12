#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
string L1, L2, L3;
int T, N;
bool can(string & res) {
	for (auto i : res) if (i == '1') return true;
	return false;
}
inline void flip(string & res) {
	for (auto & i : res)
		if (i == '0') i = '1';
		else i = '0';
}
inline bool comp2s(string & l) {
	bool carry = true;
	for (auto &i : l) {
		if (!carry) break;
		if (i == '1') i = '0';
		else {
			i = '1'; carry = false;
		}
	}
	return carry;
}
inline string andy(string a, string b) {
	if (a.size() != b.size()) {
		cout << "and faile"; return b;
	}
	for (int i = 0; i < int(a.size()); i++) {
		if (a[i] != b[i]) b[i] = '0';
	}
	return b;
}
inline string diff(string a, string b) {
	if (int(a.size()) != int(b.size())) {
		cout << "diff faile"; return b;
	}
	for (int i = 0; i < int(a.size()); i++) {
		if (a[i] - 48 > b[i] - 48) b[i] = '1';
		else if (a[i] == b[i]) b[i] = '0';
		else {
			size_t pos = a.find('1', i);
			a[pos] = '0';
			for (int j = i; j < pos; j++) a[j] = '1';
			b[i] = '1';
		}
	}
	return b;
}
void compute() {
	int c = 0;
	string L2B; N--;
	string l1, l2, l3, l2b;
	while (can(L1) || can(L2) || can(L3)) {
		c++;

		l1 = L1, l2 = L2, l3 = L3, l2b = L2B = L2;
		cout << "Init " << c << " " << L3 << " " << L2 << " " << L1 << '\n';
		flip(L3); flip(L2); flip(L2B); flip(L1);
		cout << "Flip " << c << " " << L3 << " " << L2 << " " << L1 << '\n';
		bool carry = comp2s(L3);
		cout << "Comps " << c << " " << L3;
		bool moveto = false;
		L3 = andy(l3, L3);
		if (carry) {
			carry = comp2s(L2);
			cout << " " << L2;
			if (!carry && N > 0) moveto = true;
		}
		L2 = andy(l2, L2);
		L2B = andy(l2b, L2B);
		if (carry) {
			carry = comp2s(L1);
			cout << " " << L1;
			if (carry) L1 = L1 + '1';
		}
		L1 = andy(l1, L1);
		cout << "\nAnd " << c << " " << L3 << " " << L2 << " " << L1 << '\n';
		if (moveto) {
			l3 += l2;
			L3 += L2;
			cout << l2b << " " << L2B << '\n';
			l2 = l2b;
			L2 = L2B;
			cout << "Andap " << c << " " << L3 << " " << L2 << " " << L1 << '\n';
			N--;
		}
		string temp = diff(l3 + l2 + l1, L3 + L2 + L1);
		cout << "Act " << c << " " << temp << "\n";
		L3 = temp.substr(0, L3.size());
		L2 = temp.substr(L3.size(), L2.size());
		L1 = temp.substr(int(L3.size()) + int(L2.size()), L1.size());
		cout << "Sub " << c << " " << L3 << " " << L2 << " " << L1 << '\n';
		string sl1 = L1, sl2 = L2, sl3 = L3;
		reverse(sl1.begin(), sl1.end());
		reverse(sl2.begin(), sl2.end());
		reverse(sl3.begin(), sl3.end());
		cout << "Unreversed " << sl1 << " "; for (int i = 0; i <= N; i++) cout << sl2; cout << " " << sl3 << '\n';
		// break;
		// if (c > 20) break;
	}
	cout << "Result " << c - 1 << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> L1 >> L2 >> L3 >> N;
		reverse(L1.begin(), L1.end());
		reverse(L2.begin(), L2.end());
		reverse(L3.begin(), L3.end());
		compute();
	}
}

// 001 100 011 4
