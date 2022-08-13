// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
using namespace std;
#define stoi stoll
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
const int INF    = 10000000000007; // 1e13 + 7
const int INF2    = LLONG_MAX; // 9.2e18
const double EPS = 1e-8;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on
bool out_of_border(int a, int b) {
  return a < 0 or a > 10000 or b < 0 or b > 10000;
}
bool in(int a, int b, int c, int d, int x, int y) { // (x, y) in (a, b)×(c, d)
  return a <= x and x <= c and b <= y and y <= d;
}
bool duplicate(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2) {
  return in(a1, b1, c1, d1, a2, b2) or in(a1, b1, c1, d1, c2, d2) or
         in(a1, b1, c1, d1, a2, d2) or in(a1, b1, c1, d1, c2, b2);
}
bool duplicate2(int a1, int b1, int c1, int d1, int a2, int b2, int c2,
                int d2) {
  return duplicate(a1, b1, c1, d1, a2, b2, c2, d2) or
         duplicate(a2, b2, c2, d2, a1, b1, c1, d1);
}
signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  V<int> x(n);
  V<int> y(n);
  V<int> r(n);
  V<V<int>> ans(n, V<int>(4));
  rep(i, n) cin >> x[i] >> y[i] >> r[i];
  V<P<int, int>> r_num(n);
  rep(i, n) r_num[i] = {r[i], i};
  sort(ALL(r_num));
  rep(i, n) {
    int now = r_num[i].se;
    bool possible = false;
    rep3(length, sqrt(r[now]), 1) {
      if (possible)
        break;
      ans[now] = {x[now], y[now], x[now] + length, y[now] + length};
      possible = true;
      rep(j, n) {
        if (now == j)
          continue;
        if (out_of_border(ans[now][2], ans[now][3]) or
            (x[now] == 0 and y[now] < 300)) {
          possible = false;
          break;
        }
        if (duplicate2(ans[now][0], ans[now][1], ans[now][2], ans[now][3],
                       ans[j][0], ans[j][1], ans[j][2], ans[j][3])) {
          possible = false;
          break;
        }
      }
    }
    if (!possible) {
      ans[now] = {0, i, 1, i + 1};
    }
  }
  FOR(i, ans) {
    cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << endl;
  }
}