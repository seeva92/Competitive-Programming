#include <climits>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
ll arr[1007][1007];
ll seg[1007 * 1007 * 8];
int a1, b1, a2, b2;
void build(int idx, int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2)
    return;
  if (x1 == x2 && y1 == y2) {
    seg[idx] = arr[x1][y1];
    return;
  }
  build(4 * idx - 2, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
  build(4 * idx - 1, (x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
  build(4 * idx, x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
  build(4 * idx + 1, (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);
  seg[idx] = max(max(seg[4 * idx], seg[4 * idx - 1]),
                 max(seg[4 * idx - 2], seg[4 * idx + 1]));
}
ll query(int idx, int x1, int y1, int x2, int y2) {
  if (a1 > x2 || a2 < x1 || b1 > y2 || b2 < y1 || x1 > x2 || y1 > y2)
    return INT_MIN;
  if (a1 <= x1 && x2 <= a2 && b1 <= y1 && y2 <= b2)
    return seg[idx];

  return max(
      max(query(4 * idx - 2, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2),
          query(4 * idx - 1, (x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2)),
      max(query(4 * idx, x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2),
          query(4 * idx + 1, (x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2)));
}
void preprocess(int N, int M) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      if (i - 1 >= 0)
        arr[i][j] += arr[i - 1][j];
      if (j - 1 >= 0)
        arr[i][j] += arr[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0)
        arr[i][j] -= arr[i - 1][j - 1];
    }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
  freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, a, b, Q;
  cin >> N >> M;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }
  build(1, 0, 0, N - 1, M - 1);
  preprocess(N, M);
  cin >> Q;
  for (size_t i = 0; i < Q; i++) {
    cin >> a >> b;
    if (a == 1 && a == b)
      cout << "0\n";
    else {
      int res = INT_MAX;
      for (size_t j = 0; j < N - a + 1; j++) {
        for (size_t k = 0; k < M - b + 1; k++) {
          a1 = j, b1 = k, a2 = a1 + a - 1, b2 = b1 + b - 1;
          int temp = query(1, 0, 0, N - 1, M - 1);
          int expected = a * b * temp;
          int available = arr[a2][b2];
          if (a1 - 1 >= 0)
            available -= arr[a1 - 1][b2];
          if (b1 - 1 >= 0)
            available -= arr[a2][b1 - 1];
          if (a1 - 1 >= 0 && b1 - 1 >= 0)
            available += arr[a1 - 1][b1 - 1];
          if (res > (expected - available))
            res = expected - available;
        }
      }
      cout << res << endl;
    }
  }
}
