#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <climits>
#include <sstream>
using namespace std;
int main() {
	//std::ios_base::sync_with_stdio(false);
	freopen("1.txt", "r", stdin);
	freopen("3.txt", "w", stdout);
	int n, p;
	char temp[500];
	stringstream ss;
	scanf("%d %d\n", &n, &p);
	int idx = 1;
	// printf("%d %d", n, p);
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			gets(temp);
		}
		double price;
		int mArr;
		string str;
		int comp = INT_MIN;
		double compPrice = 0.0;
		int compIndex;
		int i;
		double epsilon = 0.0001;
		for (i = 0; i < p; i++) {
			gets(temp);

			scanf("%f %d\n", &price, &mArr);
			if (mArr > comp) {
				comp = mArr; compPrice = price; str = {temp};
			} else if (mArr == comp) {
				if (compPrice > price)
				{
					compPrice = price; str = {temp};
				}
			}

			for (int j = 0; j < mArr; j++) {
				gets(temp);
			}
		}
		// printf("RFP #%d\n%s\n\n", idx, str[compIndex].c_str());
		cout << "RFP #" << idx << '\n' << str << "\n";
		idx++;
		scanf("%d %d\n", &n, &p);
		if (n != 0)
			cout << '\n';
	}
	return 0;
}