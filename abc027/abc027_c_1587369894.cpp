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
  int N   = in();
  int dis = floor(log2((double)N));
  int aoki, takahashi;
  if (dis % 2 == 0) {
    takahashi = 1;
    aoki      = 0;
  } else {
    takahashi = 0;
    aoki      = 1;
  }
  int num = 1;
  rep(i, 1000000) {
    if (i % 2 == 0) {
      num = num * 2 + takahashi;
    } else {
      num = num * 2 + aoki;
    }
    if (num > N) {
      break;
    }
  }
  if ((int)log2((double)num) == dis) {
    if (dis % 2 == 0) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
  } else {
    if (dis % 2 == 0) {
      cout << "Aoki" << endl;
    } else {
      cout << "Takahashi" << endl;
    }
  }
}