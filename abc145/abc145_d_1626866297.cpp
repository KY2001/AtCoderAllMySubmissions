#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;
int MOD = 1e9 + 7;

#define MAX_ 1000000
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
  if (n < k or n < 0 or k < 0) return 0;
  return (fac[n - 1] * ((finv[k - 1] * finv[n - k - 1]) % MOD)) % MOD;
}

signed main() {
  int X, Y;
  cin >> X >> Y;
  nCk_init();
  if ((2 * X - Y) % 3 == 0 and (-X + 2 * Y) % 3 == 0 and (2 * X - Y) / 3 >= 0 and (-X + 2 * Y) / 3 >= 0) {
    cout << nCk((2 * X - Y) / 3 + (-X + 2 * Y) / 3, (-X + 2 * Y) / 3) << endl;
  } else {
    cout << 0 << endl;
  }
}