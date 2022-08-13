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

int ceil_(int a, int b) { return (a + (b - 1)) / b; }
int positive_surplus(int &a) { return (a + MOD) % MOD; }
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
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

signed main() {
  string X;
  cin >> X;
  int N     = X.size();
  int num_S = 0;
  int num_T = 0;
  int ans   = 0;
  rep(i, N) {
    if (X[i] == 'S') {
      FOR(j, i, N) {
        if (X[j] == 'S') {
          num_S++;
          if (j == N - 1) goto label;
        } else {
          i = j;
          break;
        }
      }
      FOR(j, i, N) {
        if (X[j] == 'T') {
          num_T++;
        } else {
          i = j - 1;
          ans += 2 * min(num_S, num_T);
          num_S = 0;
          num_T = 0;
          break;
        }
        if (j == N - 1) {
          ans += 2 * min(num_S, num_T);
        }
      }
    }
  }
label:
  cout << N - ans << endl;
}
