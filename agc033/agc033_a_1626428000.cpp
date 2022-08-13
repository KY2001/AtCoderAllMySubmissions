// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
//#define double __float80
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
const int INF    = 1e18;
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-20;
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
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

void check(int now, int x, int y, priority_queue<V<int>, VV<int>, greater<V<int>>> &pos, VV<int> &a) {
  if (a[x][y] > now + 1 and a[x][y] != -1) {
    a[x][y] = now + 1;
    pos.push({now + 1, x, y});
  }
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int H, W;
  cin >> H >> W;
  V<string> A(H);
  rep(i, H) cin >> A[i];
  VV<int> a(H + 2, V<int>(W + 2, INF));
  rep(i, W + 2) a[0][i]     = -1;
  rep(i, W + 2) a[H + 1][i] = -1;
  rep(i, H + 2) {
    a[i][0]     = -1;
    a[i][W + 1] = -1;
  }
  rep(i, H) rep(j, W) if (A[i][j] == '#') {
    a[i + 1][j + 1] = 0;
  }
  priority_queue<V<int>, VV<int>, greater<V<int>>> pos;
  rep(i, H) rep(j, W) {
    if (a[i + 1][j + 1] == 0) pos.push({a[i + 1][j + 1], i + 1, j + 1});
  }
  while (pos.size()) {
    V<int> now = pos.top();
    pos.pop();
    check(now[0], now[1] + 1, now[2], pos, a);
    check(now[0], now[1] - 1, now[2], pos, a);
    check(now[0], now[1], now[2] + 1, pos, a);
    check(now[0], now[1], now[2] - 1, pos, a);
  }
  int ans = 0;
  rep(i, H) rep(j, W) if (a[i + 1][j + 1] > ans) {
    ans = a[i + 1][j + 1];
  }
  cout << ans << endl;
}