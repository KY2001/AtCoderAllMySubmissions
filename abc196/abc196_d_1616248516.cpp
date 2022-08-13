//@Author: KeinYukiyoshi

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
const int INF    = (int)1e18;
const int INF2    = 10000000000007; // 1e13 + 7
const int INF3    = LLONG_MAX; // 9.2e18
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
int ans = 0;
void dfs(VV<bool> &already, VV<int> &already2, int A, int H, int W, int now, map<VV<int>, bool> &temp) {
  if (temp.count(already2)) return;
  if (now == A) {
    temp[already2] = true;
    ans++;
    return;
  }
  temp[already2] = true;
  rep(i, H) rep(j, W - 1) {
    if (!already[i][j] and !already[i][j + 1]) {
      already[i][j]     = true;
      already[i][j + 1] = true;
      already2[i][j]    = 1;
      dfs(already, already2, A, H, W, now + 1, temp);
      already2[i][j]    = 0;
      already[i][j]     = false;
      already[i][j + 1] = false;
    }
  }
  rep(i, H - 1) rep(j, W) {
    if (!already[i][j] and !already[i + 1][j]) {
      already[i][j]     = true;
      already[i + 1][j] = true;
      already2[i][j]    = 2;
      dfs(already, already2, A, H, W, now + 1, temp);
      already2[i][j]    = 0;
      already[i][j]     = false;
      already[i + 1][j] = false;
    }
  }
}

class DHanjo {
public:
  static void solve(istream &cin, ostream &cout) {
    ans = 0;
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    map<VV<int>, bool> temp;
    VV<bool> already(H, V<bool>(W));
    VV<int> already2(H, V<int>(W));
    dfs(already, already2, A, H, W, 0, temp);
    cout << ans << endl;
  }
};


signed main() {
  DHanjo solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

