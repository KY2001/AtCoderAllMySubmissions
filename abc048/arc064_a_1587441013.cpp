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
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  int ans = 0;
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;
  }
  FOR(i, 1, N) {
    if (a[i] + a[i - 1] > x) {
      ans += a[i] + a[i - 1] - x;
      a[i] = x - a[i - 1];
    }
  }
  cout << ans << endl;
}
