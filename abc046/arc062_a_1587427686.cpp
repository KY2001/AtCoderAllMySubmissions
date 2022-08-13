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

int bisect(int L, int R, int t, int a, int T, int A) {
  int mid = (L + R) / 2;
  if ((T * mid >= t && A * mid >= a) && !(T * (mid - 1) >= t && A * (mid - 1) >= a)) {
    return mid;
  } else if (T * (mid - 1) >= t && A * (mid - 1) >= a) {
    return bisect(L, mid, t, a, T, A);
  } else {
    return bisect(mid, R, t, a, T, A);
  }
}

signed main() {
  int N = in();
  vector<int> T(N);
  vector<int> A(N);
  rep(i, N) {
    cin >> T[i];
    cin >> A[i];
  }
  int t = T[0];
  int a = A[0];
  FOR(i, 1, N) {
    int mid = bisect(0, 1000000000000000010, t, a, T[i], A[i]);
    t       = T[i] * mid;
    a       = A[i] * mid;
  }
  cout << a + t << endl;
}
