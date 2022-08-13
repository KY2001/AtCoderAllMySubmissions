#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)            // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++) // [a, b)
#define rep3(i, a, b)                                           // reversed [a, b] so [b, b-1, ... a]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 998244353;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

#define MAX_ 5000
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
  if (n == k or k == 0) return 1;
  return (fac[n - 1] * ((finv[k - 1] * finv[n - k - 1]) % MOD)) % MOD;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  nCk_init();
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<vector<int>> proceed(N + 1, vector<int>(K + 10, 0));
  rep(i, N) proceed[i][0] = 1;
  rep(i, N) {
    rep(j, K) {
      proceed[i][j + 1] = proceed[i][j] * A[i];
      proceed[i][j + 1] %= MOD;
    }
  }
  rep(i, K + 1) {
    rep(j, N) {
      proceed[j + 1][i] += proceed[j][i];
      proceed[j + 1][i] %= MOD;
    }
  }
  rep2(X, 1, K + 1) {
    int ans = 0;
    rep(k, X + 1) {
      int temp = nCk(X, k);
      temp *= proceed[N][k];
      temp %= MOD;
      temp *= proceed[N][X - k];
      temp %= MOD;
      ans += temp;
      ans %= MOD;
    }
    ans -= pow_mod(2, X) * proceed[N][X];
    ans *= inv_list[1];
    cout << mod(ans, MOD) << endl;
  }
}