#include "bits/stdc++.h"
#define int long long
#define For(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define Max(x) *max_element(ALL(x))
#define Min(x) *min_element(ALL(x))
#define Lower_bound(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define Upper_bound(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int
#define Endl endl

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

signed main() {
  int n = in();
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  vector<int> ans(n);
  if (n % 2 == 1) {
    ans[n / 2] = a[0];
    For(i, 1, n) {
      if (i % 2) {
        ans[n / 2 + (i + 1) / 2] = a[i];
      } else {
        ans[n / 2 - i / 2] = a[i];
      }
    }
  } else {
    rep(i, n) {
      if (i % 2 == 0) {
        ans[n / 2 - 1 + (i + 2) / 2] = a[i];
      } else {
        ans[n / 2 - (i + 1) / 2] = a[i];
      }
    }
  }
  rep(i, n - 1) {
    cout << ans[i] << " ";
  }
  cout << ans[n - 1] << endl;
}
