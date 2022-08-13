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
  int n = in();
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  int cost1    = 0;
  int cost2    = 0;
  int temp_sum = 0;
  rep(i, n) {
    temp_sum += a[i];
    if (i % 2 == 0) {
      if (temp_sum <= 0) {
        cost1 -= temp_sum - 1;
        temp_sum = 1;
      }
    } else {
      if (temp_sum >= 0) {
        cost1 += temp_sum + 1;
        temp_sum = -1;
      }
    }
  }
  temp_sum = 0;
  rep(i, n) {
    temp_sum += a[i];
    if (i % 2 == 1) {
      if (temp_sum <= 0) {
        cost2 -= temp_sum - 1;
        temp_sum = 1;
      }
    } else {
      if (temp_sum >= 0) {
        cost2 += temp_sum + 1;
        temp_sum = -1;
      }
    }
  }
  cout << min(cost1, cost2) << endl;
}
