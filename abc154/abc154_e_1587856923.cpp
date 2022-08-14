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

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}
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

#define MAX_ 500000
int inv_list[MAX_]; //inv_list[i-1] = inverse of i
int fac[MAX_];
int finv[MAX_];
void nCk_init() {
  inv_list[0] = fac[0] = finv[0] = 1;
  for (int i = 0; i < MAX_ - 1; i++) {
    inv_list[i + 1] = MOD - ((inv_list[(MOD % (i + 2)) - 1] * (MOD / (i + 2))) % MOD);
    fac[i + 1]      = (fac[i] * (i + 2)) % MOD;
    finv[i + 1]     = (finv[i] * inv_list[i + 1]) % MOD;
  }
}
int nCk(int n, int k) {
  if (n <= k || k <= 0) {
    return 1;
  }
  return (fac[n - 1] * ((finv[k - 1] * finv[n - k - 1]) % MOD)) % MOD;
}

class EAlmostEverywhereZero {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    nCk_init();
    string S;
    int K;
    cin >> S >> K;
    int ans = 0;
    FOR(i, 1, S.size()) {
      if (i >= K)
        ans += nCk(i - 1, K - 1) * bpm(9, K);
    }
    vector<int> product(S.size());
    vector<int> cum_sum(S.size(), 0);
    rep(i, S.size()) {
      product[i] = stoi(string(1, S[i]));
    }
    rep(i, S.size() - 1) {
      cum_sum[i + 1] = product[i + 1];
      cum_sum[i + 1] += cum_sum[i];
    }
    if (K == 1) {
      ans += product[0];
    } else if (K == 2) {
      int i = 0;
      FOR(j, i + 1, S.size()) {
        if (cum_sum[i] != 0 || j == i + 1) {
          ans += 9 * (product[i] - 1) + product[j];
        } else {
          ans += 9 * product[i];
        }
      }
    } else {
      int i = 0;
      FOR(j, i + 1, S.size() - 1) {
        FOR(k, j + 1, S.size()) {
          if (cum_sum[j] != 0 && j != i + 1 && k != j + 1) {
            ans += 81* product[i];
          } else if (cum_sum[j] == 0 && cum_sum[k] != 0 && j != i + 1) {
            ans += (product[i] - 1) * 81 + product[j] * 9;
          } else {
            ans += (product[i] - 1) * 81 + (product[j] - 1) * 9 + product[k];
          }
        }
      }
    }
    cout << ans << endl;
  }
};
