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

class EPatisserieABC2 {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, K;
    cin >> N >> K;
    int sum = 0;
    int p   = 3 * N;
    rep2(k, 3, 3 * N + 1) {
      if (3 <= k and k <= N + 2) {
        sum += (k - 2) * (k - 1) / 2;
      } else if (k >= N + 3 and k <= 2 * N) {
        sum += -k * k + 3 * N * k + 3 * k - N * (N + 3) * 3 / 2 - 2;
      } else {
        sum += (3 * N + 1 - k) * (3 * N + 2 - k) / 2;
      }
      if (sum >= K) {
        if (3 <= k and k <= N + 2) {
          sum -= (k - 2) * (k - 1) / 2;
        } else if (k >= N + 3 and k <= 2 * N) {
          sum -= -k * k + 3 * N * k + 3 * k - N * (N + 3) * 3 / 2 - 2;
        } else {
          sum -= (3 * N + 1 - k) * (3 * N + 2 - k) / 2;
        }
        p = k;
        break;
      }
    }
    K -= sum;
    int sum2 = 0;
    int num  = 1;
    rep2(i, max(0LL, p - 2 * N - 1), min(p, N)) {
      sum2 += p - 2 - i;
      if (sum2 >= K) {
        sum2 -= p - 2 - i;
        K -= sum2;
        num = i + 1;
        break;
      }
    }
    cout << num << " " << max(p - num - N + K - 1, K) << " " << p - num - max(p - num - N + K - 1, K) << endl;
  }
};


signed main() {
  EPatisserieABC2 solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

