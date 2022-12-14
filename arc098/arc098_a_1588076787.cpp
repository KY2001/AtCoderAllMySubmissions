/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

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

class CAttention {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N;
    string S;
    cin >> N >> S;
    vector<int> cum_sum(N + 1, 0);
    rep(i, S.size()) {
      if (S[i] == 'W') cum_sum[i + 1]++;
      cum_sum[i + 1] += cum_sum[i];
    }
    int ans = INF;
    rep(i, S.size()) {
      ans = min(ans, cum_sum[i] + ((int)S.size() - (i + 1) - (cum_sum[S.size()] - cum_sum[i + 1])));
    }
    cout << ans << endl;
  }
};


signed main() {
  CAttention solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
