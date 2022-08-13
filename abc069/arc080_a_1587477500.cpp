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
  int N = in();
  vector<int> a(N);
  int two    = 0;
  int four   = 0;
  int others = 0;
  rep(i, N) {
    cin >> a[i];
    if (a[i] % 4 == 0) {
      four++;
    } else if (a[i] % 2 == 0) {
      two++;
    } else {
      others++;
    }
  }
  if (two == 0) {
    if (four >= N / 2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }
  N -= two;
  if (four >= (N + 1) / 2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
