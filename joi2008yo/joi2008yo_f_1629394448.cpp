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
const int INF    = 1e13 + 7;
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

// INFは十分に大きく(>辺の大きさ×経路の長さ)設定しないとバグる.
template<class T> struct Dijkstra {
private:
  int n;
  vector<vector<pair<T, T>>> graph;

public:
  vector<T> shortest_path;
  Dijkstra(vector<vector<pair<T, T>>> &G): n(G.size()) { //
    graph = G;
    shortest_path.assign(n, (T)INF);
  }
  void dijkstra(int s) {
    rep(i, n) {
      shortest_path[i] = (T)INF;
    }
    shortest_path[s] = 0;
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<>> que;
    que.push({0, s});
    while (!que.empty()) {
      pair<T, T> p = que.top();
      que.pop();
      int v = p.second;
      if (shortest_path[v] < p.first) continue;
      for (auto e: graph[v]) {
        if (shortest_path[e.first] > shortest_path[v] + e.second) {
          shortest_path[e.first] = shortest_path[v] + e.second;
          que.push({shortest_path[e.first], e.first});
        }
      }
    }
  }
};

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int n, k, q, a, b, c, d, e;
  cin >> n >> k;
  VV<P<int, int>> graph(n);
  rep(i, k) {
    cin >> q;
    if (q) {
      cin >> c >> d >> e;
      graph[c - 1].push_back({d - 1, e});
      graph[d - 1].push_back({c - 1, e});
    } else {
      cin >> a >> b;
      Dijkstra<int> dij(graph);
      dij.dijkstra(a - 1);
      if (dij.shortest_path[b - 1] == INF) {
        cout << -1 << endl;
      } else {
        cout << dij.shortest_path[b - 1] << endl;
      }
    }
  }
}