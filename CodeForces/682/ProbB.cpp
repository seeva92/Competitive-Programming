#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
int arr[100007];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  int res = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= res)
      res++;
  }
  cout << res << endl;
}
