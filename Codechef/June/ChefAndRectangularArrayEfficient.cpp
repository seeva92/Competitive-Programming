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
ll arr[1007][1007], temp[1007][1007], temp1[1007][1007];
ll sub_max[1007][1007];
void preprocess(int N, int M) {

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      temp[i][j] = arr[i][j];
      if (i - 1 >= 0)
        arr[i][j] += arr[i - 1][j];
      if (j - 1 >= 0)
        arr[i][j] += arr[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0)
        arr[i][j] -= arr[i - 1][j - 1];
    }
}
void compute(int N, int M, int a, int b) {
  a--;
  b--;
  // cout << "Computing " << endl;
  for (int j = 0; j < M; j++) {
    deque<int> q;
    int i;
    for (i = 0; i < N && i <= a; i++) {
      while (!q.empty() && temp[q.back()][j] <= temp[i][j])
        q.pop_back();
      q.push_back(i);
      sub_max[i][j] = temp[q.front()][j];
      temp1[i][j] = sub_max[i][j];
    }
    for (; i < N; i++) {
      while (!q.empty() && q.front() < (i - a))
        q.pop_front();
      while (!q.empty() && temp[q.back()][j] <= temp[i][j])
        q.pop_back();
      q.push_back(i);
      sub_max[i][j] = temp[q.front()][j];
      temp1[i][j] = sub_max[i][j];
    }
  }
  // for (int i = 0; i < N; i++, cout << '\n')
  // for (int j = 0; j < M; j++)
  // cout << sub_max[i][j] << " ";

  for (int j = 0; j < N; j++) {
    deque<int> q;
    int i;
    for (i = 0; i < M && i <= b; i++) {
      while (!q.empty() && temp1[j][q.back()] <= temp1[j][i])
        q.pop_back();
      q.push_back(i);
      sub_max[j][i] = temp1[j][q.front()];
    }
    for (; i < M; i++) {
      while (!q.empty() && q.front() < (i - b))
        q.pop_front();
      while (!q.empty() && temp1[j][q.back()] <= temp1[j][i])
        q.pop_back();
      q.push_back(i);
      sub_max[j][i] = temp1[j][q.front()];
    }
  }
  // for (int i = 0; i < N; i++, cout << '\n')
  // for (int j = 0; j < M; j++)
  // cout << sub_max[i][j] << " ";
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
  preprocess(N, M);
  int a1, b1, a2, b2;
  cin >> Q;
  for (size_t i = 0; i < Q; i++) {
    cin >> a >> b;
    if (a == 1 && a == b)
      cout << "0\n";
    else {
      compute(N, M, a, b);
      int res = INT_MAX;
      for (size_t j = 0; j < N - a + 1; j++) {
        for (size_t k = 0; k < M - b + 1; k++) {
          a1 = j, b1 = k, a2 = a1 + a - 1, b2 = b1 + b - 1;
          int expected = a * b * sub_max[a2][b2];
          // cout << j << " " << k << " " << sub_max[a2][b2] << endl;
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
