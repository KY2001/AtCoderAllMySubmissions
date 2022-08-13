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
int inv_list[MAX_]{}; //inv_list[i-1] = inverse of i
void inv_continuous(int n) {
  inv_list[0] = 1;
  for (int i = 0; i < n; i++) {
    inv_list[i + 1] = MOD - (inv_list[(MOD % (i + 2)) - 1] * (MOD / (i + 2)) % MOD);
  }
}
int nCk_order_k(int n, int k) {
  k = min(n - k, k);
  inv_continuous(k);
  int nCk = 1;
  for (int i = 0; i < k; i++) {
    nCk = (((nCk * (n - i)) % MOD) * inv_list[i]) % MOD;
  }
  return nCk;
}
signed main() {
  int W, H;
  cin >> W >> H;
  cout << nCk_order_k(W + H - 2, H - 1) << endl;
}
