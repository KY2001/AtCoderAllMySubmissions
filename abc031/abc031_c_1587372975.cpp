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
  int ans = -INF;
  rep(i, N) {
    int A = -INF;
    int T;
    rep(j, N) {
      if (i != j) {
        int A_temp = 0;
        int T_temp = 0;
        for (int k = min(i, j); k <= max(i, j); k++) {
          if ((k - min(i, j)) % 2 == 0) {
            T_temp += a[k];
          } else {
            A_temp += a[k];
          }
        }
        if (A_temp > A) {
          A = A_temp;
          T = T_temp;
        }
      }
    }
    ans = max(ans, T);
  }
  cout << ans << endl;
}
