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
// const int INF    = 1e18;
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

template<class T> struct two_dim_cum_sum {
  int H, W;
  vector<vector<T>> cum_sum;
  two_dim_cum_sum(vector<vector<T>> &data): H(data.size()), W(data[0].size()) { // dataはH+1, W+1の大きさ
    cum_sum = data;
    for (int i = 1; i < H; i++)
      for (int j = 1; j < W - 1; j++) cum_sum[i][j + 1] += cum_sum[i][j];
    for (int i = 1; i < H - 1; i++)
      for (int j = 1; j < W; j++) cum_sum[i + 1][j] += cum_sum[i][j];
  }
  T get(int x1, int y1, int x2, int y2) { return cum_sum[x2][y2] - cum_sum[x2][y1 - 1] - cum_sum[x1 - 1][y2] + cum_sum[x1 - 1][y1 - 1]; } //引数は全て+1された状態で, (x2, y2)を含む
};

signed main() {
  int H, W, c;
  cin >> H >> W;
  VV<int> C1(H + 1, V<int>(W + 1));
  VV<int> C2(H + 1, V<int>(W + 1));
  rep(i, H) rep(j, W) {
    if ((i + j) % 2) {
      cin >> C1[i + 1][j + 1];
    } else {
      cin >> C2[i + 1][j + 1];
    }
  }
  int ans = 0;
  two_dim_cum_sum<int> White(C1);
  two_dim_cum_sum<int> Black(C2);
  rep2(y1, 1, H + 1) rep2(x1, 1, W + 1) rep2(y2, 1, H + 1) rep2(x2, 1, W + 1) {
    if (not(y2 >= y1 and x2 >= x1)) continue;
    if (White.get(y1, x1, y2, x2) == Black.get(y1, x1, y2, x2)) {
      ans = max(ans, (y2 - y1 + 1) * (x2 - x1 + 1));
    }
  }
  cout << ans << endl;
}