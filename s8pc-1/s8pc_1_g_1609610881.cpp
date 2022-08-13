/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

// clang-format off
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
#define Endl endl
#define itn int
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define _max(x) *max_element(ALL(x))
#define _min(x) *min_element(ALL(x))
#define _sum(x) accumulate(ALL(x), 0LL)

const int MOD   = 1000000007;
// const int MOD    = 998244353;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-8;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int _mod(int a) {return a >= 0 ? a % MOD : a - (MOD * _ceil(a, MOD));}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

class GRevengeOfTravelingSalesmanProblem {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, M;
    cin >> N >> M;
    VV<P<int, int>> dis(N, V<P<int, int>>(N, P<int, int>(INF, 0)));
    rep(i, M) {
      int s, t, d, time;
      cin >> s >> t >> d >> time;
      s--, t--;
      dis[s][t] = {d, time};
      dis[t][s] = {d, time};
    }
    VV<P<int, int>> dp((1 << N), V<P<int, int>>(N, P<int, int>(INF, 0)));
    rep(i, N) dp[0][0] = {0, 1};
    rep(i, (1 << N) - 1) {
      rep(j, N) {   // from
        rep(k, N) { // to
          if (((i >> k) & 1) == 0 and dp[i][j].fi + dis[j][k].fi <= dis[j][k].se) {
            if (dp[i | (1 << k)][k].fi == dp[i][j].fi + dis[j][k].fi) {
              dp[i | (1 << k)][k].se += dp[i][j].se;
            } else if (dp[i | (1 << k)][k].fi > dp[i][j].fi + dis[j][k].fi) {
              dp[i | (1 << k)][k].fi = dp[i][j].fi + dis[j][k].fi;
              dp[i | (1 << k)][k].se = dp[i][j].se;
            }
          }
        }
      }
    }
    if (dp[(1 << N) - 1][0].fi >= INF) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << dp[(1 << N) - 1][0].fi << " " << dp[(1 << N) - 1][0].se << endl;
    }
  }
};


signed main() {
  GRevengeOfTravelingSalesmanProblem solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}