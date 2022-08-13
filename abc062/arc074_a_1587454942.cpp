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
  int H, W;
  int ans = INF;
  cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0) {
    cout << 0 << endl;
    return 0;
  } else {
    int height1 = H / 2;
    int height2 = H - height1;
    rep(i, W - 1) {
      ans = min(ans, (max(height1 * (i + 1), max(height2 * (i + 1), (W - i - 1) * H)) - min(height1 * (i + 1), min(height2 * (i + 1), (W - i - 1) * H))));
    }
    height1  = W / 2;
    height2  = W - height1;
    int temp = H;
    H        = W;
    W        = temp;
    rep(i, W - 1) {
      ans = min(ans, (max(height1 * (i + 1), max(height2 * (i + 1), (W - i - 1) * H)) - min(height1 * (i + 1), min(height2 * (i + 1), (W - i - 1) * H))));
    }
  }
  cout << ans << endl;
}
