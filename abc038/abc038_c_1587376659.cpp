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

signed main() {
  int N = in();
  vector<int> a_(N);
  vector<int> a(N);
  rep(i, N) {
    cin >> a_[i];
  }
  rep(i, N - 1) {
    a[i + 1] = a_[i + 1] - a_[i];
  }
  a[0]    = 0;
  int num = 0;
  rep(i, N) {
    FOR(j, i, N) {
      if (a[min(N - 1, j + 1)] <= 0 || j == N - 1) {
        num += (j - i + 1) * (j - i + 2) / 2;
        i = j;
        break;
      }
    }
  }
  cout << num << endl;
}
