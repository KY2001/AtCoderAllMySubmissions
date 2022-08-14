#include "bits/stdc++.h"
#define int long long
#define For(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define Max(x) *max_element(ALL(x))
#define Min(x) *min_element(ALL(x))
#define Lower_bound(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define Upper_bound(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

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

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int Lcm(int a, int b) {
  if (!(a % gcd(a, b))) {
    return (a / gcd(a, b) * b);
  } else if (!(b % gcd(a, b))) {
    return (b / gcd(a, b) * a);
  } else {
    return a * b / gcd(a, b);
  }
}
class CMultipleClocks {
public:
  void solve(std::istream &cin, std::ostream &cout) {
    int N;
    cin >> N;
    int ans = 1;
    rep(i, N) {
      int temp;
      cin >> temp;
      ans = Lcm(temp, ans);
    }
    cout << ans << endl;
  }
};
