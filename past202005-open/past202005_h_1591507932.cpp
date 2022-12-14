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
template <class T>
struct trio {
  T first{};
  T second{};
  T third{};
};
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

class H {
public:
  static void solve(istream &cin, ostream &cout) {
    int N, L;
    cin >> N >> L;
    vector<bool> grid(200000, false);
    rep(i, N) {
      int x;
      cin >> x;
      grid[x] = true;
    }
    int T1, T2, T3;
    cin >> T1 >> T2 >> T3;
    vector<int> dis(200000, INF);
    dis[0]         = 0;
    deque<int> pos = {0};
    int ans        = INF;
    while (pos.size()) {
      int now = pos[0];
      pos.pop_front();
      if (now > L) continue;
      int ex = 0;
      if (grid[now]) {
        ex = T3;
      }
      if (now == L) ans = min(ans, dis[now] + ex);
      if (dis[now] + T1 + ex < dis[now + 1]) {
        dis[now + 1] = dis[now] + T1 + ex;
        pos.emplace_back(now + 1);
      }
      if (dis[now] + T1 + T2 + ex < dis[now + 2]) {
        dis[now + 2] = dis[now] + T1 + T2 + ex;
        pos.emplace_back(now + 2);
        if (L == now + 1) {
          ans = min(ans, dis[now] + T1 / 2 + T2 / 2 + ex);
        }
      }
      if (dis[now] + T1 + 3 * T2 + ex < dis[now + 4]) {
        dis[now + 4] = dis[now] + T1 + 3 * T2 + ex;
        pos.emplace_back(now + 4);
        if (L == now + 1) {
          ans = min(ans, dis[now] + T1 / 2 + T2 / 2 + ex);
        } else if (L == now + 2) {
          ans = min(ans, dis[now] + T1 / 2 + T2 + T2 / 2 + ex);
        } else if (L == now + 3) {
          ans = min(ans, dis[now] + T1 / 2 + 2 * T2 + T2 / 2 + ex);
        }
      }
    }
    cout << ans << endl;
  }
};


signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  H solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
