#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, j, k, l, n, m, t;
  cin >> t;
  double u, v, w, U, V, W, Volume, a, b = 12;
  // Volume = sqrt(4*u*u*v*v*w*w- u*u*sqr((v*v+w*w - U*U)) - v*v*sqr((w*w+u*u -
  // V*V)) - w*w*sqr((u*u + v*v - W*W)) + (v*v +w*w - U*U)*(w*w+u*u-
  // V*V)*(u*u+v*v - W*W))/12;
  while (t--) {
    cin >> u >> v >> w >> W >> V >> U;
    a = 4 * (pow(u, 2) * pow(v, 2) * pow(w, 2)) -
        pow(u, 2) * pow((pow(v, 2) + pow(w, 2) - pow(U, 2)), 2) -
        pow(v, 2) * pow((pow(w, 2) + pow(u, 2) - pow(V, 2)), 2) -
        pow(w, 2) * pow((pow(u, 2) + pow(v, 2) - pow(W, 2)), 2) +
        (pow(v, 2) + pow(w, 2) - pow(U, 2)) *
            (pow(w, 2) + pow(u, 2) - pow(V, 2)) *
            (pow(u, 2) + pow(v, 2) - pow(W, 2));
    Volume = sqrt(a);
    Volume /= b;
    cout << setprecision(4) << fixed << Volume << endl;
  }
}
