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

int dp[60][60][2560]{};
signed main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  rep(i, N) {
    cin >> x[i];
  }
  dp[1][1][x[0]] = 1;
  FOR(i, 1, N) {
    dp[i + 1][1][x[i]] = 1;
    rep(j, 51) {
      rep(k, 2501) {
        dp[i + 1][j][k] += dp[i][j][k];
        dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
      }
    }
  }
  int ans = 0;
  FOR(i, 1, 51) {
    ans += dp[N][i][A * i];
  }
  cout << ans << endl;
}