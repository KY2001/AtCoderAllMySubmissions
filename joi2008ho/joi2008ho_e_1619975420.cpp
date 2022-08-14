//@Author: KeinYukiyoshi

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
// const int INF    = (int)1e18;
// const int INF    = 10000000000007; // 1e13 + 7
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

template <class T> int Lower_bound(vector<T> &A, T key) { //key以上の最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(ALL(A), key));
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Lower_bound_reverse(vector<T> &A, T key) { //key以下の最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Upper_bound(vector<T> &A, T key) { //keyより大きい最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key));
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Upper_bound_reverse(vector<T> &A, T key) { //keyより小さい最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

void dfs(int y, int x, VV<int> &already, VV<int> &check) {
  if (already[y + 1][x + 1]) return;
  if (check[y][x]) return;
  already[y + 1][x + 1]++;
  dfs(y + 1, x, already, check);
  dfs(y - 1, x, already, check);
  dfs(y, x + 1, already, check);
  dfs(y, x - 1, already, check);
}
class E {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int w, h, n;
    cin >> w >> h >> n;
    V<int> x1(n);
    V<int> y1(n);
    V<int> x2(n);
    V<int> y2(n);
    V<int> x(2 * n);
    V<int> y(2 * n);
    rep(i, n) {
      cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
      x[i] = x1[i], x[i + n] = x2[i];
      y[i] = y1[i], y[i + n] = y2[i];
    }
    x.emplace_back(0);
    y.emplace_back(0);
    x.emplace_back(w);
    y.emplace_back(h);
    sort(ALL(x));
    sort(ALL(y));
    int N = 2 * n + 2;
    VV<int> check(N, V<int>(N));
    rep(i, n) {
      rep2(j, Lower_bound(x, x1[i]), Lower_bound_reverse(x, x2[i])) {
        check[Lower_bound(y, y1[i])][j]++;
        check[Lower_bound_reverse(y, y2[i])][j]--;
      }
    }
    rep(i, N - 1) rep(j, N) check[i + 1][j] += check[i][j];
    VV<int> already(N + 2, V<int>(N + 2, 1));
    rep(i, N) rep(j, N) already[i + 1][j + 1] = 0;
    int ans                                   = 0;
    rep(i, N - 1) rep(j, N - 1) if (!check[i][j] and !already[i + 1][j + 1]) {
      ans++;
      dfs(i, j, already, check);
    }
    cout << ans << endl;
  }
};


signed main() {
  E solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}


