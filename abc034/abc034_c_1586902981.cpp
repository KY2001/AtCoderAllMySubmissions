#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SQR(x) (x) * (x)
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);
template <typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
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
  return (fac[n - 1] * ((finv[k - 1] * finv[n - k - 1]) % MOD)) % MOD;
}

signed main() {
  int W, H;
  cin >> W >> H;
  nCk_init();
  cout << nCk(W + H - 2, W - 1) << endl;
}
