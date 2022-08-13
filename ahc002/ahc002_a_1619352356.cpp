// clang-format off
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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
// const int INF    = (int)1e18;
const int INF    = 1000000007; // 1e13 + 7
// const int INF    = LLONG_MAX; // 9.2e18
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
int score;
double start;
double Start;
string ans;

inline void dfs(int y, int x, int now, string &road, V<bool> &already, VV<int> &t, VV<int> &p) {
  if (already[t[y][x]]) return;
  already[t[y][x]] = true;
  now += p[y][x];
  if (now > score) {
    score = now;
    ans   = road;
  }
  if (((clock() - start) / CLOCKS_PER_SEC) > 0.003) {
    already[t[y][x]] = false;
    return;
  }
  deque<P<double, char>> temp;
  temp.emplace_back(rand(), 'D');
  temp.emplace_back(rand(), 'U');
  temp.emplace_back(rand(), 'R');
  temp.emplace_back(rand(), 'L');
  sort(ALL(temp), greater{});
  while (temp.size()) {
    road += temp[0].se;
    if (temp[0].se == 'D') dfs(y + 1, x, now, road, already, t, p);
    if (temp[0].se == 'U') dfs(y - 1, x, now, road, already, t, p);
    if (temp[0].se == 'R') dfs(y, x + 1, now, road, already, t, p);
    if (temp[0].se == 'L') dfs(y, x - 1, now, road, already, t, p);
    road.pop_back();
    temp.pop_front();
  }
  already[t[y][x]] = false;
}

signed main() {
  srand(time(nullptr));
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Start = clock();
  score = 0;
  int sx, sy;
  cin >> sx >> sy;
  sx++, sy++;
  VV<int> t(52, V<int>(52));
  VV<int> p(52, V<int>(52));
  rep(i, 50) rep(j, 50) cin >> t[i + 1][j + 1];
  rep(i, 50) rep(j, 50) t[i + 1][j + 1]++;
  rep(i, 50) rep(j, 50) cin >> p[i + 1][j + 1];
  string road;
  V<bool> already(2501);
  already[0] = true;
  rep(i, INF) {
    if ((clock() - Start) / CLOCKS_PER_SEC > 1.95) {
      // cout << i << endl;
      break;
    }
    start = clock();
    dfs(sx, sy, 0LL, road, already, t, p);
  }
  cout << ans << endl;
  // cout << score << endl;
}