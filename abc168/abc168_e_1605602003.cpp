#include <bits/stdc++.h>
#define int long long
#define stoi stoll
#define rep(i, n) for (int i = 0; i < (int)(n); i++)             // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b) for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

namespace FastPrimeFactorization {

template<typename word, typename dword, typename sword>
struct UnsafeMod {
  UnsafeMod(): x(0) {}

  UnsafeMod(word _x): x(init(_x)) {}

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

using Mod64                    = UnsafeMod<uint64_t, uint128_t, int64_t>;
template<> uint64_t Mod64::mod = 0;
template<> uint64_t Mod64::inv = 0;
template<> uint64_t Mod64::r2  = 0;

using Mod32                    = UnsafeMod<uint32_t, uint64_t, int32_t>;
template<> uint32_t Mod32::mod = 0;
template<> uint32_t Mod32::inv = 0;
template<> uint32_t Mod32::r2  = 0;

bool miller_rabin_primality_test_uint64(uint64_t n) {
  Mod64::set_mod(n);
  uint64_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  Mod64 e{1}, rev{n - 1};
  // http://miller-rabin.appspot.com/  < 2^64
  for (uint64_t a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
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
  for (uint32_t a: {2, 7, 61}) {
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

template<class T>
struct reduction { //reduction: 約分, O(log n)
private:
  int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
  int lcm(int a, int b) { return a * b / gcd(a, b); }

public:
  T first;
  T second;
  reduction(int a, int b): first(a), second(b) { //符号は変わらない
    if (a == 0 or b == 0) {
      first = second = 0;
    } else {
      int GCD = gcd(abs(first), abs(second));
      first /= GCD;
      second /= GCD;
    }
  }
};

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N;
  cin >> N;
  map<pair<int, int>, int> I;
  map<pair<int, int>, int> J;
  vector<vector<pair<int, int>>> IJ(N);
  rep(i, N) {
    int A, B;
    cin >> A >> B;
    reduction<int> rd(A, B);
    if ((A < 0 and B < 0) or (A >= 0 and B >= 0)) {
      I[{abs(rd.first), abs(rd.second)}]++;
      J[{-abs(rd.second), abs(rd.first)}]++;
      IJ[i] = {{abs(rd.first), abs(rd.second)}, {-abs(rd.second), abs(rd.first)}};
    } else {
      I[{-abs(rd.first), abs(rd.second)}]++;
      J[{abs(rd.second), abs(rd.first)}]++;
      IJ[i] = {{-abs(rd.first), abs(rd.second)}, {abs(rd.second), abs(rd.first)}};
    }
  }
  int ans = 1;
  int num = N;
  rep(i, N) {
    int a = J[IJ[i][0]];
    int b = I[IJ[i][0]];
    if (IJ[i][0] == IJ[i][1]) {
      if (a) {
        ans *= (a + 1);
        ans %= MOD;
        num -= a;
        J[IJ[i][0]] = 0;
        J[IJ[i][1]] = 0;
      }
    } else {
      if (a) {
        ans *= (pow_mod(2, a) + pow_mod(2, b) - 1);
        ans %= MOD;
        num -= a + b;
        J[IJ[i][0]] = 0;
        J[IJ[i][1]] = 0;
      }
    }
  }
  ans *= pow_mod(2, num);
  cout << mod(ans - 1, MOD) << endl;
}