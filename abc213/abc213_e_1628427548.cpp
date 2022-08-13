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

void task1(int x, int y, int dis, V<string> &grid, VV<int> &shortest, priority_queue<V<int>, VV<int>, greater<>> &pos) {
  if (grid[x][y] == 'A') {
    return;
  } else if (grid[x][y] == '.' and shortest[x][y] > dis) {
    shortest[x][y] = dis;
    pos.push({dis, x, y});
  }
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int H, W;
  cin >> H >> W;
  V<string> grid(H + 4);
  VV<int> shortest(H + 4, V<int>(W + 4, INF));
  grid[0]     = string(W + 4, 'A');
  grid[1]     = string(W + 4, 'A');
  grid[H + 2] = string(W + 4, 'A');
  grid[H + 3] = string(W + 4, 'A');
  rep(i, H) cin >> grid[i + 2];
  rep(i, H) grid[i + 2] = "AA" + grid[i + 2] + "AA";
  priority_queue<V<int>, VV<int>, greater<>> pos;
  pos.push({0, 2, 2});
  shortest[2][2] = 0;
  while (pos.size()) {
    int x = pos.top()[1], y = pos.top()[2], dis = pos.top()[0];
    pos.pop();
    task1(x + 1, y, dis, grid, shortest, pos);
    task1(x - 1, y, dis, grid, shortest, pos);
    task1(x, y + 1, dis, grid, shortest, pos);
    task1(x, y - 1, dis, grid, shortest, pos);
    rep(i, 5) rep(j, 5) {
      if (i == 0 and j == 0) continue;
      if (i == 0 and j == 4) continue;
      if (i == 4 and j == 0) continue;
      if (i == 4 and j == 4) continue;
      if (grid[x - 2 + i][y - 2 + j] == '#' and shortest[x - 2 + i][y - 2 + j] > dis + 1) {
        shortest[x - 2 + i][y - 2 + j] = dis + 1;
        pos.push({dis + 1, x - 2 + i, y - 2 + j});
      }
    }
  }
  cout << shortest[H + 1][W + 1] << endl;
}