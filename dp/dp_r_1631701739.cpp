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
#define rep4(i, a) for (auto &i: a)
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

template<class T>
struct matrix {
  int row;    // 行
  int column; // 列
  vector<vector<T>> M;
  matrix(vector<vector<T>> &m): row(m.size()), column(m[0].size()) { M = m; }
  matrix add(matrix &m) { // M += m
    for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++) M[i][j] += m.M[i][j];
    return M;
  }
  matrix subtract(matrix &m) { // M -= m
    for (int i = 0; i < row; i++)
      for (int j = 0; j < column; j++) M[i][j] -= m.M[i][j];
    return M;
  }
  void multiply_from_right(matrix &m) { //M = M*m O(n^3)
    vector<vector<T>> temp(row, vector<T>(m.column));
    for (int i = 0; i < row; i++)
      for (int j = 0; j < m.column; j++)
        for (int k = 0; k < column; k++) {
          temp[i][j] += M[i][k] * m.M[k][j];
        }
    M = temp, row = M.size(), column = M[0].size();
  }
  void multiply_from_left(matrix &m) { //M = m*M O(n^3)
    matrix<T> temp = m;
    temp.multiply_from_right(*this);
    *this = temp;
  }
  void pow(int b) { // M = pow(M, n) O(n^3log(b))
    int n = row;
    vector<vector<T>> temp(n, vector<T>(n));
    for (int i = 0; i < n; i++) temp[i][i] = 1;
    matrix<T> ret(temp);
    for (; b; b >>= 1, this->multiply_from_right(*this)) {
      if (b & 1) ret.multiply_from_right(*this);
    }
    *this = ret;
  }
  void show() {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) cout << M[i][j] << " ";
      cout << endl;
    }
  }
};

VV<mint> a;

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, K;
  cin >> N >> K;
  a.resize(N, V<mint>(N));
  rep4(i, a) rep4(j, i) cin >> j;
  matrix<mint> M(a);
  M.pow(K);
  mint ans = 0;
  rep4(i, M.M) rep4(j, i) ans += j;
  cout << ans << endl;
}