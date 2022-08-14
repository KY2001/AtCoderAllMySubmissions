#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

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
int sum(int N) {
  int p = (N * (N + 1) / 2) % MOD;
  return (N * (N + 1) / 2);
}
signed main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  FOR(i, K, N + 2) {
    ans -= sum(i - 1);
    ans += sum(N);
    ans -= sum(N - i);
    ans += 1;
    ans %= MOD;
  }
  cout << ans << endl;
}