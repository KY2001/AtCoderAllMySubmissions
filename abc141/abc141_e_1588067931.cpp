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

const int MAX_ = 5000 + 10;
int Z[MAX_];
void Z_algorithm(string &S) { //length of size must be length of string
  fill(begin(Z), end(Z), 0);
  int c = 0;
  for (int i = 1; i < S.size(); i++) {
    if (i + Z[i - c] < c + Z[c]) {
      Z[i] = Z[i - c];
    } else {
      int j = max(0LL, c + Z[c] - i);
      while (i + j < S.size() and S[j] == S[i + j]) ++j;
      Z[i] = j;
      c    = i;
    }
  }
  Z[0] = S.size();
}

signed main() {
  int N;
  string S;
  cin >> N >> S;
  string temp{};
  int ans = 0;
  rep(i, N) {
    temp = string(1, S[i]) + temp;
    Z_algorithm(temp);
    rep(j, temp.size()) if (Z[j] <= j) ans = max(ans, Z[j]);
  }
  cout << ans << endl;
}
