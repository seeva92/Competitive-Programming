#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
using namespace std;
double epsilon = 0.001;
int main() {
	std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	int months, depCount;
	double payment, loanAmount;
	int m;
	double depValue, carAmount, prevdepValue;

	while (1) {
		cin >> months >> payment >> loanAmount >> depCount;
		if (months < 0)
			break;

		double loanArr[months + 1];
		double carArr[months + 1];
		double interestArr[months + 1];
		loanArr[0] = loanAmount;
		double monthlyPayment = loanAmount / months;
		for (int i = 1; i <= months; i++) {
			loanArr[i] = loanArr[i - 1] - monthlyPayment;
		}
		fill(interestArr, interestArr + months + 1, -1);

		for (int i = 0; i < depCount; i++) {
			cin >> m >> depValue;	interestArr[m] = depValue;
		}
		double minusone = -1;
		for (int i = 1; i <= months; i++)
		{
			if (abs(interestArr[i] - (double)(-1)) < epsilon)
				interestArr[i] = interestArr[i - 1];

		}
		carArr[0] = (loanAmount + payment) - ((loanAmount + payment) * interestArr[0]);

		for (int i = 1; i <= months; i++)
			carArr[i] = carArr[i - 1] - (carArr[i - 1] * interestArr[i]);

		int idx = -1;
		for (int i = 0; i <= months; i++)
		{
			if (loanArr[i] < carArr[i])
			{
				idx = i;
				break;
			}
		}

		if (idx == 1)
			cout << "1 month" << '\n';
		else
			cout << idx << " months" << '\n';

	}
	return 0;
}