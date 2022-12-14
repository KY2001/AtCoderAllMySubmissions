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
const int MOD   = (int)(1e9 + 7);
const int INF   = (int)(1e13 + 7);
const double PI = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow(int x, int y) {                                                             //return x^y in order(log(y))
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
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

class DPreparingBoxes {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<int> ball(N, 0);
    for (int i = N - 1; i >= 0; i--) {
      int now = 0;
      for (int j = i; j < N; j += (i + 1)) {
        now += ball[j];
      }
      if (now % 2 != a[i]) {
        ball[i] = 1;
      }
    }
    cout << accumulate(ALL(ball), 0LL) << endl;
    rep(i, N) {
      if (ball[i]) {
        cout << 1;
        if (i != N - 1) {
          cout << " ";
        }
      }
    }
    cout << endl;
  }
};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  DPreparingBoxes solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
