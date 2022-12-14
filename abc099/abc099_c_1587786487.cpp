/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

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

class CStrangeBank {
public:
  void solve(std::istream &cin, std::ostream &cout) {
    int N;
    cin >> N;
    vector<int> money(100000, INF);
    money[0] = 0;
    int k;
    rep(i, 100000 - 10) {
      money[i + 1] = min(money[i] + 1, money[i + 1]);
      k            = 6;
      while (i + k < money.size()) {
        money[i + k] = min(money[i] + 1, money[i + k]);
        k *= 6;
      }
      k = 9;
      while (i + k < money.size()) {
        money[i + k] = min(money[i] + 1, money[i + k]);
        k *= 9;
      }
    }
    cout << money[N] << endl;
  }
};


signed main() {
  CStrangeBank solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}