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
int bpm(int x, int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
  }
  return ans;
}
template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}

signed main() {
  int ans = 0;
  string S;
  cin >> S;
  int all = bpm(2, (signed)S.size() - 1);
  rep(i, S.size()) {
    int num_of_plus = S.size() - 1 - i;
    string S_i      = "";
    S_i += S[i];
    rep(j, num_of_plus + 1) {
      if (j == num_of_plus) {
        ans += stoi(S_i) * bpm(10, j) * bpm(2, i);
      } else {
        ans += stoi(S_i) * bpm(10, j) * (all / min(all, bpm(2, j + 1)));
      }
    }
  }
  cout << ans << endl;
}
