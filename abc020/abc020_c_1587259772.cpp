#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}
int calc(int i, int j, vector<vector<int>> &table, int x) {
  if (table[i][j] == 1) {
    return 1;
  } else if (table[i][j] == 2) {
    return x;
  } else {
    return 1;
  }
}
bool judge(vector<vector<int>> &table, int x, int T) {
  pair<int, int> start, goal;
  rep(i, table.size() - 1) {
    rep(j, table[0].size() - 1) {
      if (table[i + 1][j + 1] == 3) {
        start = {i + 1, j + 1};
      } else if (table[i + 1][j + 1] == 4) {
        goal = {i + 1, j + 1};
      }
    }
  }
  vector<vector<int>> minimum(table.size(), vector<int>(table[0].size(), INF));
  minimum[start.first][start.second] = 0;
  deque<pair<int, int>> pos          = {{start.first, start.second}};
  while (!pos.empty()) {
    int i = pos[0].first;
    int j = pos[0].second;
    pos.pop_front();
    int cost;
    if (table[i + 1][j]) {
      cost = calc(i + 1, j, table, x);
      if (minimum[i][j] + cost < minimum[i + 1][j]) {
        minimum[i + 1][j] = minimum[i][j] + cost;
        pos.emplace_back(i + 1, j);
      }
    }
    if (table[i - 1][j]) {
      cost = calc(i - 1, j, table, x);
      if (minimum[i][j] + cost < minimum[i - 1][j]) {
        minimum[i - 1][j] = minimum[i][j] + cost;
        pos.emplace_back(i - 1, j);
      }
    }
    if (table[i][j + 1]) {
      cost = calc(i, j + 1, table, x);
      if (minimum[i][j] + cost < minimum[i][j + 1]) {
        minimum[i][j + 1] = minimum[i][j] + cost;
        pos.emplace_back(i, j + 1);
      }
    }
    if (table[i][j - 1]) {
      cost = calc(i, j - 1, table, x);
      if (minimum[i][j] + cost < minimum[i][j - 1]) {
        minimum[i][j - 1] = minimum[i][j] + cost;
        pos.emplace_back(i, j - 1);
      }
    }
  }
  return minimum[goal.first][goal.second] <= T;
}

int bisect(int L, int R, vector<vector<int>> &table, int T) {
  int mid = (L + R) / 2;
  if (judge(table, mid, T)) {
    if (!judge(table, mid + 1, T)) {
      return mid;
    } else {
      return bisect(mid, R, table, T);
    }
  } else {
    return bisect(L, mid, table, T);
  }
}

signed main() {
  int H, W, T;
  cin >> H >> W >> T;
  vector<vector<int>> table(H + 2, vector<int>(W + 2, 0));
  rep(i, H) {
    string temp;
    cin >> temp;
    rep(j, W) {
      if (temp[j] == '.') {
        table[i + 1][j + 1] = 1;
      } else if (temp[j] == '#') {
        table[i + 1][j + 1] = 2;
      } else if (temp[j] == 'S') {
        table[i + 1][j + 1] = 3;
      } else {
        table[i + 1][j + 1] = 4;
      }
    }
  }
  cout << bisect(0, 10000000000, table, T) << endl;
}
