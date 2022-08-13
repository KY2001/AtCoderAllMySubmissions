#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int bpm(int x, unsigned int y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (unsigned int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}

typedef unsigned int ull;
const ull B1 = 100000007;
bool contain(string &a, string &b) {
  int al = a.length(), bl = b.length();
  if (al > bl) return false;
  ull t = 1;
  for (int i = 0; i < al - 1; i++) t *= B1;
  ull ah1 = 0, bh1 = 0, ah2 = 0, bh2;
  for (int i = 0; i < al; i++) ah1 = ah1 * B1 + a[i];
  for (int i = 0; i < al - 1; i++) ah2 = ah2 * B1 + a[i];
  for (int i = 0; i < al; i++) bh1 = bh1 * B1 + b[i];
  bh2 = (bh1 - b[al - 1]) / B1;
  for (int i = 0; i + al <= bl; i++) {
    if (ah1 == bh1 and ah2 == bh2) return true;
    if (i + al < bl) {
      bh2 = bh1 - b[i] * t;
      bh1 = bh1 * B1 + b[i + al] - b[i] * (t * B1);
    }
  }
  return false;
}

signed main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  string R{};
  rep(i, N - 1) {
    R = string(1, S[N - (i + 1)]) + R;
    S.pop_back();
    if (contain(R, S)) {
      ans = max(ans, (int)R.length());
    } else {
      R.pop_back();
    }
  }
  cout << ans << endl;
}
