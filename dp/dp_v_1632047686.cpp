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

int MOD   = 1000000007;
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

VV<int> graph;
V<bool> already;
V<mint> ret;
V<mint> ret2;
V<mint> ans;
mint dfs(int now) {
  if (ret[now].x) return now;
  already[now] = true;
  mint val     = 1;
  V<mint> memo;
  rep(i, graph[now].size()) if (!already[graph[now][i]]) val *= (1 + dfs(graph[now][i]).x);
  already[now] = false;
  ret[now]     = val;
  return ret[now];
}

void dfs2(int now) {
  already[now] = true;
  mint val     = 1;
  V<mint> cum_pro1(graph[now].size() + 1, 1);
  V<mint> cum_pro2(graph[now].size() + 1, 1);
  rep(i, graph[now].size()) {
    val *= (1 + ret2[graph[now][i]].x);
    cum_pro1[i + 1]                     = (1 + ret2[graph[now][i]].x);
    cum_pro2[graph[now].size() - 1 - i] = (1 + ret2[graph[now][i]].x);
  }
  rep(i, graph[now].size()) cum_pro1[i + 1] *= cum_pro1[i];
  rep3(i, graph[now].size(), 1) cum_pro2[i - 1] *= cum_pro2[i];
  ans[now] = val;
  rep(i, graph[now].size()) if (!already[graph[now][i]]) {
    ret2[now] = cum_pro1[i] * cum_pro2[i + 1];
    dfs2(graph[now][i]);
  }
  ret2[now]    = ret[now];
  already[now] = false;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, x, y;
  cin >> N >> MOD;
  graph.resize(N);
  already.resize(N);
  ret.resize(N);
  ans.resize(N);
  rep(i, N - 1) {
    cin >> x >> y;
    graph[x - 1].emplace_back(y - 1);
    graph[y - 1].emplace_back(x - 1);
  }
  dfs(0);
  ret2 = ret;
  dfs2(0);
  rfor(i, ans) cout << i << endl;
}