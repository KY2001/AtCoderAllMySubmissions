#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)             // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b) for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD = 998244353;
const int INF = (int)(1e13 + 7);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num

signed main() {
  int N, K;
  cin >> N >> K;
  int ans           = INF;
  vector<int> plus  = {0};
  vector<int> minus = {0};
  rep(i, N) {
    int x;
    cin >> x;
    if (x >= 0) {
      plus.emplace_back(x);
    } else {
      minus.emplace_back(abs(x));
    }
  }
  sort(ALL(minus));
  int s = (int)minus.size() - 1;
  rep(i, K + 1) {
    if (i == plus.size()) { break; }
    if (K - i <= s) {
      ans = min(ans, max(plus[i], minus[K - i]) + 2 * min(plus[i], minus[K - i]));
    }
  }
  cout << ans << endl;
}
