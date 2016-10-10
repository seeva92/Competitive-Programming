#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  string str;
  priority_queue<int, vector<int>, greater<int>> p;
  vector<pair<string, int>> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    if (str == "insert") {
      cin >> x;
      p.push(x);
      v.push_back(make_pair(str, x));
    } else if (str == "removeMin") {
      if (p.empty()) {
        p.push(0);
        v.push_back(make_pair("insert", 0));
      }
      p.pop();
      v.push_back(make_pair(str, 0));
    } else {
      cin >> x;
      while (!p.empty() && p.top() < x) {
        p.pop();
        v.push_back(make_pair("removeMin", 0));
      }

      if (p.empty() || p.top() > x) {
        p.push(x);
        v.push_back(make_pair("insert", x));
      }
      v.push_back(make_pair(str, x));
    }
  }
  cout << int(v.size()) << endl;
  for (auto it : v) {
    cout << it.first;
    if (it.first != "removeMin")
      cout << " " << it.second;
    cout << '\n';
  }
  // cin >> n;
}
