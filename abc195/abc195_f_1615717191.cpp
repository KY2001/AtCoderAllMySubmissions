//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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
const int INF    = 10000000000007; // 1e13 + 7
const int INF2    = LLONG_MAX; // 9.2e18
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

namespace FastPrimeFactorization {

template <typename word, typename dword, typename sword>
struct UnsafeMod {
  UnsafeMod() : x(0) {}

  UnsafeMod(word _x) : x(init(_x)) {}

  bool operator==(const UnsafeMod &rhs) const {
    return x == rhs.x;
  }

  bool operator!=(const UnsafeMod &rhs) const {
    return x != rhs.x;
  }

  UnsafeMod &operator+=(const UnsafeMod &rhs) {
    if ((x += rhs.x) >= mod) x -= mod;
    return *this;
  }

  UnsafeMod &operator-=(const UnsafeMod &rhs) {
    if (sword(x -= rhs.x) < 0) x += mod;
    return *this;
  }

  UnsafeMod &operator*=(const UnsafeMod &rhs) {
    x = reduce(dword(x) * rhs.x);
    return *this;
  }

  UnsafeMod operator+(const UnsafeMod &rhs) const {
    return UnsafeMod(*this) += rhs;
  }

  UnsafeMod operator-(const UnsafeMod &rhs) const {
    return UnsafeMod(*this) -= rhs;
  }

  UnsafeMod operator*(const UnsafeMod &rhs) const {
    return UnsafeMod(*this) *= rhs;
  }

  UnsafeMod pow(uint64_t e) const {
    UnsafeMod ret(1);
    for (UnsafeMod base = *this; e; e >>= 1, base *= base) {
      if (e & 1) ret *= base;
    }
    return ret;
  }

  word get() const {
    return reduce(x);
  }

  static constexpr int word_bits = sizeof(word) * 8;

  static word modulus() {
    return mod;
  }

  static word init(word w) {
    return reduce(dword(w) * r2);
  }

  static void set_mod(word m) {
    mod = m;
    inv = mul_inv(mod);
    r2  = -dword(mod) % mod;
  }

  static word reduce(dword x) {
    word y = word(x >> word_bits) - word((dword(word(x) * inv) * mod) >> word_bits);
    return sword(y) < 0 ? y + mod : y;
  }

  static word mul_inv(word n, int e = 6, word x = 1) {
    return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
  }

  static word mod, inv, r2;

  word x;
};

using uint128_t = __uint128_t;

using Mod64 = UnsafeMod<uint64_t, uint128_t, int64_t>;
template <>
uint64_t Mod64::mod = 0;
template <>
uint64_t Mod64::inv = 0;
template <>
uint64_t Mod64::r2 = 0;

using Mod32 = UnsafeMod<uint32_t, uint64_t, int32_t>;
template <>
uint32_t Mod32::mod = 0;
template <>
uint32_t Mod32::inv = 0;
template <>
uint32_t Mod32::r2 = 0;

bool miller_rabin_primality_test_uint64(uint64_t n) {
  Mod64::set_mod(n);
  uint64_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  Mod64 e{1}, rev{n - 1};
  // http://miller-rabin.appspot.com/  < 2^64
  for (uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
    if (n <= a) break;
    uint64_t t = d;
    Mod64 y    = Mod64(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool miller_rabin_primality_test_uint32(uint32_t n) {
  Mod32::set_mod(n);
  uint32_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  Mod32 e{1}, rev{n - 1};
  for (uint32_t a : {2, 7, 61}) {
    if (n <= a) break;
    uint32_t t = d;
    Mod32 y    = Mod32(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(uint64_t n) {
  if (n == 2) return true;
  if (n == 1 || n % 2 == 0) return false;
  if (n < uint64_t(1) << 31) return miller_rabin_primality_test_uint32(n);
  return miller_rabin_primality_test_uint64(n);
}

uint64_t pollard_rho(uint64_t n) {
  if (is_prime(n)) return n;
  if (n % 2 == 0) return 2;
  Mod64::set_mod(n);
  uint64_t d;
  Mod64 one{1};
  for (Mod64 c{one};; c += one) {
    Mod64 x{2}, y{2};
    do {
      x = x * x + c;
      y = y * y + c;
      y = y * y + c;
      d = __gcd((x - y).get(), n);
    } while (d == 1);
    if (d < n) return d;
  }
  assert(0);
}

vector<uint64_t> prime_factor(uint64_t n) {
  if (n <= 1) return {};
  uint64_t p = pollard_rho(n);
  if (p == n) return {p};
  auto l = prime_factor(p);
  auto r = prime_factor(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}
}; // namespace FastPrimeFactorization
int ans = 0;
inline void dfs(V<V<uint64_t>> &primefactors, int now, unordered_map<int, bool> &temp) {
  FOR(i, primefactors[now]) {
    if (temp.count(i)) {
      return;
    }
  }
  FOR(i, primefactors[now]) {
    temp[i] = true;
  }
  ans++;
  rep2(i, now + 1, primefactors.size()) {
    dfs(primefactors, i, temp);
  }
  FOR(i, primefactors[now]) {
    temp.erase(i);
  }
}

class FCoprimePresent {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ans = 0;
    int A, B;
    cin >> A >> B;
    V<V<uint64_t>> primefactors(B - A + 1);
    rep2(i, A, B + 1) primefactors[i - A] = FastPrimeFactorization::prime_factor(i);
    if (A == 1) primefactors[0] = {1};
    unordered_map<int, bool> temp;
    rep(i, B - A + 1) dfs(primefactors, i, temp);
    cout << ans + 1 << endl;
  }
};


signed main() {
  FCoprimePresent solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

