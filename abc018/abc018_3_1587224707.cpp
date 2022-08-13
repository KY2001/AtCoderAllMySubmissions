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
int two_dim_cum(int i, int j, int k, vector<vector<int>> &table, vector<vector<int>> &table2) {
  return (table[i + k - 1][j + k - 1] + table[i - k][j - k] - table[i - k][j + k - 1] - table[i + k - 1][j - k]) + table2[i][j + k] + table2[i][j - k] + table2[i + k][j] + table2[i - k][j];
  ;
  ;
  ;
}
signed main() {
  int R, C, K;
  cin >> R >> C >> K;
  vector<vector<int>> table(1503, vector<int>(1503, 0));
  vector<vector<int>> table2(1503, vector<int>(1503, 0));
  int start = 500;
  rep(i, R) {
    string temp;
    cin >> temp;
    rep(j, C) {
      if (temp[j] == 'x') {
        table[start + i + 1][start + j + 1]  = 1;
        table2[start + i + 1][start + j + 1] = 1;
      }
    }
  }
  rep(i, R + 1) {
    rep(j, C) {
      table[start + i][start + j + 1] += table[start + i][start + j];
    }
  }
  rep(i, R) {
    rep(j, C + 1) {
      table[start + i + 1][start + j] += table[start + i][start + j];
    }
  }
  int ans = 0;
  FOR(i, start + K, start + R - K + 2) {
    FOR(j, start + K, start + C - K + 2) {
      if (two_dim_cum(i, j, K - 1, table, table2) == 0) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;
}
