// clang-format off
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define stoi stoll
#define Endl endl
#define itn int
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
#define LOWER_BOUND(A, key) distance(begin(A), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(begin(A), upper_bound(ALL(A), key))

const int MOD   = 1000000007;
// const int MOD    = 998244353;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-8;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
int _mod(int &a) {a = a >= 0 ? a % MOD : a - (MOD * _ceil(a, MOD));return a;}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
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
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, M, K;
  cin >> M >> N >> K;
  VV<int> J(M + 1, V<int>(N + 1, 0));
  VV<int> O(M + 1, V<int>(N + 1, 0));
  VV<int> I(M + 1, V<int>(N + 1, 0));
  rep(i, M) {
    string temp;
    cin >> temp;
    rep(j, N) {
      if (temp[j] == 'J') {
        J[i + 1][j + 1]++;
      } else if (temp[j] == 'O') {
        O[i + 1][j + 1]++;
      } else {
        I[i + 1][j + 1]++;
      }
    }
  }
  two_dim_cum_sum<int> j(J);
  two_dim_cum_sum<int> o(O);
  two_dim_cum_sum<int> i(I);
  rep(_, K) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << j.get(a, b, c, d) << " " << o.get(a, b, c, d) << " " << i.get(a, b, c, d) << endl;
  }
}