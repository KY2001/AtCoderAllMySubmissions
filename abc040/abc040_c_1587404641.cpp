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
  int N = in();
  vector<int> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  vector<int> ans(N, 0);
  ans[1] = abs(a[1] - a[0]);
  FOR(i, 2, N) {
    ans[i] = min(ans[i - 2] + abs(a[i - 2] - a[i]), ans[i - 1] + abs(a[i] - a[i - 1]));
  }
  cout << ans[N - 1] << endl;
}
