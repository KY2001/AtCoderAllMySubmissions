/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author KY2001
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

class CFlipFlipAndFlip {
public:
  int solve(std::istream &cin, std::ostream &cout) {
    int N, M;
    cin >> N >> M;
    vector<int> around(9, 0);
    if (N == 1 && M == 1) {
      around[0] = 1;
    } else if (N == 1 && M == 2 || M == 1 && N == 2) {
      around[1] = 2;
    } else if (N == 1 || M == 1) {
      around[1] = 2;
      around[2] = max(M - 2, N - 2);
    } else {
      around[3] = 4;
      around[5] = 2 * (N - 2) + 2 * (M - 2);
      around[8] = (N - 2) * (M - 2);
    }

    int ans = 0;
    rep(i, 9) {
      if ((i + 1) % 2 == 1) {
        ans += around[i];
      }
    }
    cout << ans << endl;
  }
};


signed main() {
	CFlipFlipAndFlip solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}