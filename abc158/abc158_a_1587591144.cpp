/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author KY2001
 */

#include <fstream>
#include <iostream>

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

class AStationAndBus {
public:
  void solve(std::istream &cin, std::ostream &cout) {
    string S;
    cin >> S;
    if (S[0] != S[1] || S[1] != S[2]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
};

signed main() {
  AStationAndBus solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  return 0;
}
