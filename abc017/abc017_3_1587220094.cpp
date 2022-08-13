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
  int N, M;
  cin >> N >> M;
  vector<int> cum_sum(M + 2, 0);
  rep(i, N) {
    int L, R, score;
    cin >> L >> R >> score;
    cum_sum[1] += score;
    cum_sum[L] -= score;
    cum_sum[R + 1] += score;
    cum_sum[M + 1] -= score;
  }
  rep(i, M + 1) {
    cum_sum[i + 1] += cum_sum[i];
  }
  cout << MAX(cum_sum) << endl;
  return 0;
}
