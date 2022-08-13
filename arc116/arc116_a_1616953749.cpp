//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
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
const unsigned long long numset[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022ULL}; // 少なくとも 2^64 までは決定的

// long long型の素数判定の場合

unsigned long long mod_mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
  long long ret = a * b - mod * (unsigned long long)((long double)(a) * (long double)(b) / (long double)(mod));
  return ret + mod * (ret < 0) - mod * (ret >= (long long)mod);
}

unsigned long long mod_pow(unsigned long long x, unsigned long long k, unsigned long long mod) {
  unsigned long long res = 1;
  while (k) {
    if (k & 1) res = mod_mul(res, x, mod);
    x = mod_mul(x, x, mod);
    k >>= 1;
  }
  return res;
}

bool is_prime(unsigned long long n) {
  if (n < 2 || ((n % 6 != 1) && (n % 6 != 5))) return (n == 2) || (n == 3);
  unsigned long long d = n - 1, s = 0;
  while (d % 2 == 0) {
    d /= 2;
    s++;
  }
  for (unsigned long long a : numset) {
    if (a % n == 0) return true;
    unsigned long long res = mod_pow(a, d, n);
    if (res == 1) continue;
    bool ok = true;
    for (unsigned int r = 0; r < s; r++) {
      if (res == n - 1) {
        ok = false;
        break;
      }
      res = mod_mul(res, res, n);
    }
    if (ok) return false;
  }
  return true;
}

class AOddVsEven {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int T;
    cin >> T;
    rep(_, T) {
      int N;
      cin >> N;
      if (N % 2 == 0) {
        N /= 2;
        if (is_prime(N) or N == 1) {
          cout << "Same" << endl;
        } else {
          cout << "Even" << endl;
        }
      } else {
        cout << "Odd" << endl;
      }
    }
  }
};


signed main() {
  AOddVsEven solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

