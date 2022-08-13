// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("unroll-loops")
#define int long long
//#define double __float80
using namespace std;
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define rfor(i, a) for (auto &i: a)
#define all(obj) begin(obj), end(obj)
#define _max(x) *max_element(all(x))
#define _min(x) *min_element(all(x))
#define _sum(x) accumulate(all(x), 0LL)

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
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

int cnt;
void dfs(int j, int k, VV<int> &check) {
  check[j][k] = 0;
  cnt--;
  if (check[j + 1][k]) dfs(j + 1, k, check);
  if (check[j - 1][k]) dfs(j - 1, k, check);
  if (check[j][k + 1]) dfs(j, k + 1, check);
  if (check[j][k - 1]) dfs(j, k - 1, check);
}

bool yes;
void dfs2(int j, int k, VV<int> &check) {
  if (j == 0 or k == 5 or j == 5 or k == 0) {
    yes = true;
    return;
  }
  check[j][k] = 1;
  if (!check[j + 1][k]) dfs2(j + 1, k, check);
  if (!check[j - 1][k]) dfs2(j - 1, k, check);
  if (!check[j][k + 1]) dfs2(j, k + 1, check);
  if (!check[j][k - 1]) dfs2(j, k - 1, check);
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int ans = 0;
  VV<int> A(4, V<int>(4));
  rep(i, 4) rep(j, 4) cin >> A[i][j];
  rep(i, (1 << 16)) {
    VV<int> check(6, V<int>(6));
    cnt = 0;
    rep(j, 16) if ((i >> j) & 1) check[j / 4 + 1][j % 4 + 1]++, cnt++;
    VV<int> check2 = check;
    rep2(j, 1, 5) rep2(k, 1, 5) if (A[j - 1][k - 1] and !check[j][k]) goto label;
    rep2(j, 1, 5) rep2(k, 1, 5) if (check[j][k]) {
      dfs(j, k, check);
      goto label2;
    }
  label2:;
    rep2(j, 1, 5) rep2(k, 1, 5) if (!check2[j][k]) {
      yes = false;
      dfs2(j, k, check2);
      if (!yes) goto label;
    }
    if (cnt == 0) {
      ans++;
    }
  label:;
  }
  cout << ans << endl;
}