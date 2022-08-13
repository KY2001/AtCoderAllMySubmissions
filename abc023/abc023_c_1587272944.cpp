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

signed main() {
  int R, C, K, N;
  cin >> R >> C >> K >> N;
  vector<vector<int>> grid(R);
  vector<int> row(R, 0);
  vector<int> column(C, 0);
  int r, c;
  rep(i, N) {
    cin >> r >> c;
    grid[r - 1].emplace_back(c - 1);
    row[r - 1] += 1;
    column[c - 1] += 1;
  }
  vector<int> column_num(N, 0);
  for (auto &i : column) {
    column_num[i] += 1;
  }
  int ans = 0;
  int ind;
  rep(i, R) {
    ans += column_num[K - row[i]];
    for (auto &j : grid[i]) {
      if (column[j] == K - row[i]) {
        ans -= 1;
      } else if (column[j] == K - row[i] + 1) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;
}