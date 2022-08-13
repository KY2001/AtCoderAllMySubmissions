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
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  rep(i, N) cin >> a[i];
  rep(i, N) cin >> b[i];
  int sum_a = accumulate(ALL(a), 0LL);
  int sum_b = accumulate(ALL(b), 0LL);
  if (sum_b < sum_a) {
    cout << "No" << endl;
    return 0;
  }
  int k     = sum_b - sum_a;
  int num_a = 0, num_b = 0;
  rep(i, N) {
    if (a[i] >= b[i]) {
      num_b += (a[i] - b[i]);
    } else {
      if ((b[i] - a[i]) % 2) {
        num_a += (b[i] - a[i] + 1) / 2;
        num_b += 1;
      } else {
        num_a += (b[i] - a[i]) / 2;
      }
    }
  }
  if ((k - num_a) * 2 == (k - num_b) and k >= num_a) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
