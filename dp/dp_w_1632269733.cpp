#include <bits/stdc++.h>
#define int long long
#define endl '\n'
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

const int MOD   = 1000000007;
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

template<typename X, typename M>
struct SegTreeLazy {
  using FX = function<X(X, X)>;
  using FA = function<X(X, M)>;
  using FM = function<M(M, M)>;
  int n;
  FX fx      = [](X x1, X x2) -> X { return max(x1, x2); };
  FA fa      = [](X x, M m) -> X { return x + m; };
  FM fm      = [](M m1, M m2) -> M { return m1 + m2; };
  const X ex = numeric_limits<int>::min();
  const M em = 0;
  vector<X> dat;
  vector<M> lazy;
  SegTreeLazy(int n_)
      : n(), dat(n_ * 4, ex), lazy(n_ * 4, em) {
    int x = 1;
    while (n_ > x) x *= 2;
    n = x;
  }
  void set(int i, X x) { dat[i + n - 1] = x; } // i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
  void build() {                               // 初期化！！
    for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }
  void eval(int k) {
    if (lazy[k] == em) return; // 更新するものが無ければ終了
    if (k < n - 1) {           // 葉でなければ子に伝搬
      lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
      lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
    }
    dat[k]  = fa(dat[k], lazy[k]); // 自身を更新
    lazy[k] = em;
  }
  void update(int a, int b, M x, int k, int l, int r) {
    eval(k);
    if (a <= l && r <= b) { // 完全に内側の時
      lazy[k] = fm(lazy[k], x);
      eval(k);
    } else if (a < r && l < b) {                  // 一部区間が被る時
      update(a, b, x, k * 2 + 1, l, (l + r) / 2); // 左の子
      update(a, b, x, k * 2 + 2, (l + r) / 2, r); // 右の子
      dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, M x) { update(a, b, x, 0, 0, n); } // update(a, b,x): [a, b)に xを加える？ O(log(n))
  X query_sub(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) { // 完全に外側の時
      return ex;
    } else if (a <= l && r <= b) { // 完全に内側の時
      return dat[k];
    } else { // 一部区間が被る時
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
  X calc(int a, int b) { return query_sub(a, b, 0, 0, n); } //  [a,b) 全てにfxを作用させた値を取得。O(log(n))
};

class WIntervals {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, M, l, r, a;
    cin >> N >> M;
    VVV<int> val(N + 1);
    rep(i, M) {
      cin >> l >> r >> a;
      val[r].push_back({l, a});
    }
    SegTreeLazy<int, int> seg(N + 1);
    rep(i, N + 1) seg.set(i, 0);
    seg.build();
    rep2(i, 1, N + 1) {
      seg.update(i, i + 1, seg.calc(0, i + 1));
      rfor(j, val[i]) seg.update(j[0], i + 1, j[1]);
    }
    cout << seg.calc(0, N + 1) << endl;
  }
};


signed main() {
  WIntervals solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
