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

  vector<vector<int>> b(2, vector<int>(3));
  vector<vector<int>> c(3, vector<int>(2));
  rep(i, 2) {
    rep(j, 3) { cin >> b[i][j]; }
  }
  rep(i, 3) {
    rep(j, 2) { cin >> c[i][j]; }
  }
  vector<pair<int, int>> p;
  rep(i, 3) {
    rep(j, 3) { p.emplace_back(i, j); }
  }
  int chokudai = 1000;
  int chokuko  = 0;
  int chokudai_temp;
  int chokuko_temp;
  vector<vector<int>> check(3, vector<int>(3));
  do {
    chokudai_temp = 0;
    chokuko_temp  = 0;
    rep(i, 5) {
      check[p[i].first][p[i].second] = 1;
    }
    FOR(i, 5, 9) {
      check[p[i].first][p[i].second] = 0;
    }
    rep(i, 2) {
      rep(j, 3) {
        if (check[i][j] == check[i + 1][j]) {
          chokudai_temp += b[i][j];
        } else {
          chokuko_temp += b[i][j];
        }
      }
    }
    rep(i, 3) {
      rep(j, 2) {
        if (check[i][j] == check[i][j + 1]) {
          chokudai_temp += c[i][j];
        } else {
          chokuko_temp += c[i][j];
        }
      }
    }
    if ((chokudai_temp - chokuko_temp) < (chokudai - chokuko) && chokudai > chokuko) {
      chokudai = chokudai_temp;
      chokuko  = chokuko_temp;
    }
  } while (next_permutation(ALL(p)));
  cout << chokudai << endl;
  cout << chokuko << endl;
}
