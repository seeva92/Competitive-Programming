#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	//freopen("1.txt", "r", stdin);
	double h, u, d, f;
	cin >> h >> u >> d >> f;
	while (h != 0) {
		double initH = 0.0;
		double climbed = 0.0;
		double currH = 0.0;
		double prevClimbDist = 0.0;
		f = f / (double(100));
		// cout << "F " << f << '\n';
		int i;
		for (i = 1; ; i++) {
			climbed = 0.0;
			if (i == 1) {
				climbed += u;
				prevClimbDist = climbed;
			} else {
				// cout << "Reduce " << prevClimbDist * f;
				double temp = (prevClimbDist - (u * f));
				// cout << " Climbed " << temp << '\n';
				climbed += temp < (double(0.0)) ? (double(0.0)) : temp;
				prevClimbDist = temp < (double(0.0)) ? (double(0.0)) : temp;
			}

			currH = (initH + climbed);
			// cout << initH << " " << climbed << " " << currH << " ";
			// cout << currH - d << '\n';
			if (currH > h)
				break;

			currH -= d;
			if (currH < (double(0.0)))
				break;


			initH = currH;
		}
		if (currH > h)
			cout << "success on day " << i << '\n';
		else
			cout << "failure on day " << i << '\n';

		cin >> h >> u >> d >> f;
	}
	return 0;
}