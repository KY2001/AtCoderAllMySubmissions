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

void dijkstra(int x, int y, int dis, V<string> &c, VV<int> &distance, VV<int> &shortest_path, priority_queue<V<int>, VV<int>, greater<>> &pos) {
  if (c[x][y] != '#' and shortest_path[x][y] > dis + (c[x][y] - '0')) {
    shortest_path[x][y] = dis + (c[x][y] - '0');
    pos.push({shortest_path[x][y], x, y});
  }
}

bool task1(int x, int y, int &X, int &Y, int &now, VV<int> &shortest_path, V<string> &c) {
  if (now - (c[X][Y] - '0') == shortest_path[x][y]) {
    now -= (c[X][Y] - '0');
    X = x, Y = y;
    return true;
  }
  return false;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, si, sj;
  cin >> N >> si >> sj;
  V<string> c(N + 2);
  c[0]     = string(N + 2, '#');
  c[N + 1] = string(N + 2, '#');
  rep(i, N) {
    cin >> c[i + 1];
    c[i + 1] = '#' + c[i + 1] + '#';
  }
  VVV<int> cross_point = {{{si + 1, sj + 1}}};
  rep2(i, 1, N + 1) {
    rep2(j, 1, N + 1) {
      if (c[i][j] != '#' and c[i][j + 1] != '#') {
        cross_point.emplace_back();
        while (1) {
          if (c[i + 1][j] != '#' or c[i - 1][j] != '#') {
            cross_point[cross_point.size() - 1].push_back({i, j});
          }
          if (c[i][j + 1] == '#') break;
          j++;
        }
      }
    }
  }
  rep2(i, 1, N + 1) {
    rep2(j, 1, N + 1) {
      if (c[j][i] != '#' and c[j + 1][i] != '#') {
        cross_point.emplace_back();
        while (1) {
          if (c[j][i + 1] != '#' or c[j][i - 1] != '#') {
            cross_point[cross_point.size() - 1].push_back({j, i});
          }
          if (c[j + 1][i] == '#') break;
          j++;
        }
      }
    }
  }
  map<V<int>, int> check;
  V<int> ok(cross_point.size());
  ok[0] = 1;
  VV<int> to_go;
  FOR(i, cross_point)
  FOR(j, i)
  check[j]++;
  to_go.emplace_back(cross_point[0][0]);
  check[cross_point[0][0]] = 0;
  rep(j, cross_point.size()) {
    FOR(k, cross_point[j]) {
      if (k == cross_point[0][0]) {
        ok[j] = true;
      }
    }
  }
  while (1) {
    if (_sum(ok) == ok.size()) break;
    map<V<int>, int> now;
    rep(i, cross_point.size()) if (not ok[i]) {
      FOR(j, cross_point[i])
      now[j]++;
    }
    int maxi = 0;
    FOR(i, now)
    chmax(maxi, i.se);
    FOR(i, now)
    if (i.se == maxi) {
      to_go.emplace_back(i.fi);
      rep(j, cross_point.size()) {
        FOR(k, cross_point[j])
        if (k == i.fi) ok[j] = 1;
      }
      break;
    }
  }
  int n                     = to_go.size();
  check                     = {};
  rep(i, n) check[to_go[i]] = i;
  VV<int> distance(n, V<int>(n, INF));
  VV<string> path(n, V<string>(n));
  rep(i, n) {
    priority_queue<V<int>, VV<int>, greater<>> pos;
    pos.push({0, to_go[i][0], to_go[i][1]});
    VV<int> shortest_path(N + 2, V<int>(N + 2, INF));
    shortest_path[to_go[i][0]][to_go[i][1]] = 0;
    while (pos.size()) {
      int x = pos.top()[1], y = pos.top()[2], dis = pos.top()[0];
      if (check.count({x, y})) chmin(distance[i][check[{x, y}]], dis);
      pos.pop();
      dijkstra(x + 1, y, dis, c, distance, shortest_path, pos);
      dijkstra(x - 1, y, dis, c, distance, shortest_path, pos);
      dijkstra(x, y + 1, dis, c, distance, shortest_path, pos);
      dijkstra(x, y - 1, dis, c, distance, shortest_path, pos);
    }
    rep(j, n) {
      if (i == j) continue;
      int x = to_go[j][0], y = to_go[j][1], now = distance[i][j];
      while (now) {
        if (task1(x + 1, y, x, y, now, shortest_path, c)) {
          path[i][j] += 'U';
          continue;
        }
        if (task1(x - 1, y, x, y, now, shortest_path, c)) {
          path[i][j] += 'D';
          continue;
        }
        if (task1(x, y + 1, x, y, now, shortest_path, c)) {
          path[i][j] += 'L';
          continue;
        }
        if (task1(x, y - 1, x, y, now, shortest_path, c)) {
          path[i][j] += 'R';
          continue;
        }
      }
      reverse(ALL(path[i][j]));
    }
  }
  string ans;
  V<bool> already(n);
  int now = 0;
  int s   = 0;
  rep(i, n) if (to_go[i][0] == si + 1 and to_go[i][1] == sj + 1) {
    s            = i;
    now          = s;
    already[now] = true;
    break;
  }
  rep(i, n) {
    rep(j, n) {
      if (not already[j]) {
        already[j] = true;
        ans += path[now][j];
        now = j;
      }
    }
  }
  ans += path[now][s];
  cout << ans << endl;
}