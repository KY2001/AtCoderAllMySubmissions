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

class DStaticSushi {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int N, C;
    cin >> N >> C;
    vector<int> x(N);
    vector<int> v(N);
    int ans = 0;
    rep(i, N) cin >> x[i] >> v[i];
    vector<int> cum_sum(N + 1);
    vector<int> cum_sum_inv(N + 1);
    rep(i, N) {
      cum_sum[i + 1] = v[i];
      cum_sum[i + 1] += cum_sum[i];
      cum_sum_inv[i + 1] = v[v.size() - 1 - i];
      cum_sum_inv[i + 1] += cum_sum_inv[i];
    }
    rep(i, N) {
      ans = max(ans, cum_sum[i + 1] - x[i]);
      ans = max(ans, cum_sum_inv[i + 1] - (C - x[N - 1 - i]));
      cum_sum[i + 1] -= x[i];
      cum_sum_inv[i + 1] -= (C - x[N - 1 - i]);
    }
    map<int, vector<int>> to;
    map<int, vector<int>> to2;
    map<int, vector<int>> inv;
    map<int, vector<int>> inv2;
    rep(i, N) to[cum_sum[i + 1]].emplace_back(i);
    rep(i, N) to2[cum_sum[i + 1] - x[i]].emplace_back(i);
    rep(i, N - 1) {
      if (to.count(cum_sum[N - i])) {
        if (to[cum_sum[N - i]].size() > 1) {
          to[cum_sum[N - i]].pop_back();
        } else {
          to.erase(cum_sum[N - i]);
        }
      }
      if (to2.count(cum_sum[N - i] - x[N - i - 1])) {
        if (to2[cum_sum[N - i] - x[N - i - 1]].size() > 1) {
          to2[cum_sum[N - i] - x[N - i - 1]].pop_back();
        } else {
          to2.erase(cum_sum[N - i] - x[N - i - 1]);
        }
      }
      inv[cum_sum_inv[i + 1]].emplace_back(i);
      inv2[cum_sum_inv[i + 1] - (C - x[N - 1 - i])].emplace_back(i);
      ans = max(ans, to.rbegin()->first + inv2.rbegin()->first);
      ans = max(ans, to2.rbegin()->first + inv.rbegin()->first);
    }
    cout << ans << endl;
  }
};


signed main() {
  DStaticSushi solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}