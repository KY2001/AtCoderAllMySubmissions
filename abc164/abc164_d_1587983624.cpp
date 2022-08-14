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
using ll       = long long;
const int MOD  = (int)(1e13 + 7);
const int MOD2 = 2019;
const int INF  = (int)(1e13 + 7);

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
  x %= MOD2;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD2;
    }
    x = x * x;
    x %= MOD2;
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
  if (n == k || k == 0) return 1;
  if (n < k) return 0;
  return (fac[n - 1] * ((finv[k - 1] * finv[n - k - 1]) % MOD)) % MOD;
}
class DMultipleOf2019 {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    string S;
    cin >> S;
    vector<int> T(S.size() + 1, 0);
    rep(i, S.size()) {
      T[S.size() - (i + 1)] = (T[S.size() - i] + bpm(10, i) * (S[S.size() - (i + 1)] - '0')) % MOD2;
    }
    vector<int> check(2019, 0);
    rep(i, T.size()) {
      check[T[i]]++;
    }
    int ans = 0;
    nCk_init();
    rep(i, 2019) {
      ans += nCk(check[i], 2);
    }
    cout << ans << endl;
  }
};
