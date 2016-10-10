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
using namespace std;
inline bool isWon(int arr[]) {
	for (int i = 0; i < 26; i++)
		if (arr[i] != 0)
			return false;
	return true;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	string input;
	string guess;
	int allowed = 7;
	int game;
	while (cin >> game >> input >> guess, game != -1) {
		int arr[26] = {0};
		int i, len, guessess = 0;
		len = input.length();

		for (i = 0; i < len; i++)
			arr[input[i] - 'a']++;

		set<char> s(guess.begin(), guess.end());
		string temp = guess;
		len = temp.length();
		guess.clear();
		for (i = 0; i < len; i++)
			if (s.find(temp[i]) != s.end())
			{
				guess.push_back(temp[i]);
				s.erase(s.find(temp[i]));
			}


		// cout << guess << '\n';
		len = guess.length();

		for (i = 0; i < len && guessess < allowed && !isWon(arr); i++)
			if (arr[guess[i] - 'a'] != 0)
				arr[guess[i] - 'a'] = 0;
			else
				guessess++;

		cout << "Round " << game << '\n';

		bool flag = isWon(arr);
		// cout << guessess << " " << i;
		if (flag && guessess < allowed) {
			cout << "You win." << '\n';
		} else if (!flag && guessess < allowed)
			cout << "You chickened out." << '\n';
		else
			cout << "You lose." << '\n';

	}
}