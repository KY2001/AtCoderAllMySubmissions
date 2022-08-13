// clang-format off
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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
const double EPS = 1e-14;
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
// clang-format on

#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
typedef pair<int, int> Pii;
template<class T> T extgcd(T a, T b, T &x, T &y) {
  for (T u = y = 1, v = x = 0; a;) {
    T q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}
template<class T> T mod_inv(T a, T m) {
  T x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
long long mod_pow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long p   = a % mod;
  while (n) {
    if (n & 1) ret = ret * p % mod;
    p = p * p % mod;
    n >>= 1;
  }
  return ret;
}

template<int mod, int primitive_root>
class NTT {
public:
  int get_mod() const { return mod; }
  void _ntt(vector<long long> &a, int sign) {
    const int n = sz(a);
    assert((n ^ (n & -n)) == 0); //n = 2^k

    const int g = 3;                                   //g is primitive root of mod
    int h       = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
    if (sign == -1) h = (int)mod_inv(h, mod);          //h = h^-1 % mod

    //bit reverse
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
      for (int k = n >> 1; k > (i ^= k); k >>= 1)
        ;
      if (j < i) swap(a[i], a[j]);
    }

    for (int m = 1; m < n; m *= 2) {
      const int m2         = 2 * m;
      const long long base = mod_pow(h, n / m2, mod);
      long long w          = 1;
      rep(x, m) {
        for (int s = x; s < n; s += m2) {
          long long u = a[s];
          long long d = a[s + m] * w % mod;
          a[s]        = u + d;
          if (a[s] >= mod) a[s] -= mod;
          a[s + m] = u - d;
          if (a[s + m] < 0) a[s + m] += mod;
        }
        w = w * base % mod;
      }
    }
    for (auto &x: a)
      if (x < 0) x += mod;
  }
  void ntt(vector<long long> &input) {
    _ntt(input, 1);
  }
  void intt(vector<long long> &input) {
    _ntt(input, -1);
    const int n_inv = mod_inv(sz(input), mod);
    for (auto &x: input) x = x * n_inv % mod;
  }
  // 畳み込み演算を行う
  vector<long long> convolution(const vector<long long> &a, const vector<long long> &b) {
    int ntt_size = 1;
    while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

    vector<long long> _a = a, _b = b;
    _a.resize(ntt_size);
    _b.resize(ntt_size);

    ntt(_a);
    ntt(_b);

    rep(i, ntt_size) {
      (_a[i] *= _b[i]) %= mod;
    }

    intt(_a);
    return _a;
  }
};

long long garner(vector<Pii> mr, int mod) {
  mr.emplace_back(mod, 0);

  vector<long long> coffs(sz(mr), 1);
  vector<long long> constants(sz(mr), 0);
  rep(i, sz(mr) - 1) {
    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
    long long v = (mr[i].second - constants[i]) * mod_inv<long long>(coffs[i], mr[i].first) % mr[i].first;
    if (v < 0) v += mr[i].first;

    for (int j = i + 1; j < sz(mr); j++) {
      (constants[j] += coffs[j] * v) %= mr[j].first;
      (coffs[j] *= mr[i].first) %= mr[j].first;
    }
  }

  return constants[sz(mr) - 1];
}

typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;

//任意のmodで畳み込み演算 O(n log n)
vector<long long> int32mod_convolution(vector<long long> a, vector<long long> b, int mod) {
  for (auto &x: a) x %= mod;
  for (auto &x: b) x %= mod;
  NTT_1 ntt1;
  NTT_2 ntt2;
  NTT_3 ntt3;
  auto x = ntt1.convolution(a, b);
  auto y = ntt2.convolution(a, b);
  auto z = ntt3.convolution(a, b);

  vector<long long> ret(sz(x));
  vector<Pii> mr(3);
  rep(i, sz(x)) {
    mr[0].first = ntt1.get_mod(), mr[0].second = (int)x[i];
    mr[1].first = ntt2.get_mod(), mr[1].second = (int)y[i];
    mr[2].first = ntt3.get_mod(), mr[2].second = (int)z[i];
    ret[i] = garner(mr, mod);
  }

  return ret;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N;
  cin >> N;
  V<int> A(N);
  V<int> B(N);
  rep(i, N) cin >> A[i] >> B[i];
  auto ans = int32mod_convolution(A, B, MOD);
  cout << 0 << endl;
  rep(i, 2 * N - 1) cout << ans[i] << endl;
}