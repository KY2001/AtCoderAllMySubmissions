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
  int N, Q;
  cin >> N >> Q;
  vector<int> cum_sum(N + 2, 0);
  int l, r;
  rep(i, Q) {
    cin >> l >> r;
    cum_sum[l] += 1;
    cum_sum[r + 1] -= 1;
  }
  rep(i, N + 1) {
    cum_sum[i + 1] += cum_sum[i];
  }
  FOR(i, 1, N + 1) {
    cout << cum_sum[i] % 2;
  }
  cout << endl;
}
