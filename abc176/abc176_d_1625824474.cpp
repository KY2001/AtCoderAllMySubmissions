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

void advance(int score, int x, int y, VV<int> &ans, V<string> &S, priority_queue<V<int>> &pos) {
  if (S[x][y] != '#' and ans[x][y] > score) {
    ans[x][y] = score;
    pos.push({-score, x, y});
    advance(score, x + 1, y, ans, S, pos);
    advance(score, x - 1, y, ans, S, pos);
    advance(score, x, y + 1, ans, S, pos);
    advance(score, x, y - 1, ans, S, pos);
  }
}

void advance2(int score, int x, int y, VV<int> &ans, V<string> &S, priority_queue<V<int>> &pos) {
  if (S[x][y] != '#' and ans[x][y] > score + 1) {
    ans[x][y] = score + 1;
    pos.push({-(score + 1), x, y});
  }
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int H, W;
  cin >> H >> W;
  int Ch, Cw, Dh, Dw;
  cin >> Ch >> Cw >> Dh >> Dw;
  V<string> S(H + 4);
  S[0]     = string(W + 4, '#');
  S[1]     = string(W + 4, '#');
  S[H + 2] = string(W + 4, '#');
  S[H + 3] = string(W + 4, '#');
  rep(i, H) {
    cin >> S[i + 2];
    S[i + 2] = "##" + S[i + 2] + "##";
  }
  VV<int> ans(H + 4, V<int>(W + 4, INF));
  priority_queue<V<int>> pos;
  pos.push({0, Ch + 1, Cw + 1});
  while (pos.size()) {
    V<int> now = pos.top();
    now[0] *= -1;
    pos.pop();
    advance(now[0], now[1] + 1, now[2], ans, S, pos);
    advance(now[0], now[1] - 1, now[2], ans, S, pos);
    advance(now[0], now[1], now[2] + 1, ans, S, pos);
    advance(now[0], now[1], now[2] - 1, ans, S, pos);
    rep(i, 5) rep(j, 5) {
      advance2(now[0], now[1] - 2 + i, now[2] - 2 + j, ans, S, pos);
    }
  }
  if (ans[Dh + 1][Dw + 1] == INF) {
    cout << "-1" << endl;
  } else {
    cout << ans[Dh + 1][Dw + 1] << endl;
  }
}