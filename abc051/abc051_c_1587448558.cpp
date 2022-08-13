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
string ans;
signed main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  ans = "";
  rep(i, ty - sy) {
    ans += 'U';
  }
  rep(i, tx - sx) {
    ans += "R";
  }
  rep(i, ty - sy) {
    ans += 'D';
  }
  rep(i, tx - sx + 1) {
    ans += "L";
  }
  rep(i, ty - sy + 1) {
    ans += 'U';
  }
  rep(i, tx - sx + 1) {
    ans += "R";
  }
  ans += "D";
  ans += "R";
  rep(i, ty - sy + 1) {
    ans += 'D';
  }
  rep(i, tx - sx + 1) {
    ans += "L";
  }
  cout << ans + "U" << endl;
}
