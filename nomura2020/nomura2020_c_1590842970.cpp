/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl                endl

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int x, int y) {                                                             //return x^y in order(log(y))
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}

class CFolia {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    N++;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> cum(N);
    rep(i, N) {
      cum[i] = A[i];
    }
    rep(i, N - 1) {
      cum[N - 2 - i] += cum[N - i - 1];
    }
    int sum = 0;
    int now = 1;
    rep(i, N) {
      sum += now;
      now -= A[i];
      if (i == N - 1) break;
      if (now <= 0) {
        cout << -1 << endl;
        return;
      }
      if (now * 2 <= cum[i + 1]) {
        now *= 2;
      } else {
        now = cum[i + 1];
      }
    }
    if (now < 0) {
      cout << -1 << endl;
      return;
    }
    cout << sum << endl;
  }
};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  CFolia solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
