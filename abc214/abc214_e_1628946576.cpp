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

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int T;
  cin >> T;
  rep(_, T) {
    int N;
    cin >> N;
    V<int> L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];
    deque<int> x(2 * N + 1, INF);
    rep(i, N) x[i]     = L[i];
    rep(i, N) x[i + N] = R[i];
    sort(ALL(x));
    VV<int> LL(N), RR(N);
    rep(i, N) LL[i] = {L[i], (R[i] - L[i] + 1)};
    rep(i, N) RR[i] = {R[i], (R[i] - L[i] + 1)};
    sort(ALL(LL));
    sort(ALL(RR));
    V<int> X = {x[0]};
    while (x.size()) {
      if (X[X.size() - 1] != x[0]) {
        X.emplace_back(x[0]);
      }
      x.pop_front();
    }
    int k = X.size();
    V<double> zaatu(k + 1);
    LL.push_back({(int)(1e13 + 7), 1});
    RR.push_back({(int)(1e13 + 7), 1});
    int l = 0, r = 0;
    rep(i, k) {
      if (X[i] == LL[l][0] and X[i + 1] != LL[l][0]) {
        while (LL[l][0] == X[i]) {
          zaatu[i] += 1 / (double)LL[l][1];
          l++;
        }
      }
      if (X[i] == RR[r][0] and X[i + 1] != RR[r][0]) {
        while (X[i] == RR[r][0]) {
          zaatu[i + 1] += 1 / (double)RR[r][1];
          r++;
        }
      }
    }
    rep(i, k) zaatu[i + 1] += zaatu[i];
    rep(i, k - 1) {
      if (X[i + 1] - X[i] + 1 < zaatu[i]) {
        cout << "No" << endl;
        goto label;
      }
    }
    cout << "Yes" << endl;
  label:;
  }
}