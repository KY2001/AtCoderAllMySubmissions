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
#define rfor(i, a) for (auto &i: a)
#define all(obj) begin(obj), end(obj)
#define _max(x) *max_element(all(x))
#define _min(x) *min_element(all(x))
#define _sum(x) accumulate(all(x), 0LL)

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
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

vector<bool> is_prime;
void enumerate_primes(int R) {
  is_prime.assign(R + 1, true);
  for (int i = 2; i < (int)sqrt(R) + 2; i++)
    if (is_prime[i])
      for (int j = 2; j * i <= R; j++) is_prime[j * i] = false;
}

bool judge_prime(int n) {
  if ((n % 2 == 0 && n != 2) || n == 1) return false;
  for (int k = 3; k < (int)sqrt((double(n))) + 2; k += 2)
    if (n % k == 0) return false;
  return true;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N;
  cin >> N;
  V<int> A(N), B(N), div;
  rep(i, N) cin >> A[i] >> B[i];
  enumerate_primes((int)(sqrt(1e9)) + 2);
  map<int, int> cnt;
  rep2(i, 2, (int)(sqrt(1e9)) + 2) {
    if (!is_prime[i]) continue;
    rep(j, N) {
      if (A[j] % i and B[j] % i) break;
      if (j == N - 1) cnt[i]++;
    }
  }
  rfor(i, A) if (judge_prime(i)) cnt[i]++;
  rfor(i, B) if (judge_prime(i)) cnt[i]++;
  rfor(i, cnt) div.emplace_back(i.fi);
  int ans = 1;
  rep(i, 1 << div.size()) {
    int check = 1;
    rep(j, div.size()) check *= (i >> j) & 1 ? div[j] : 1;
    rep(j, N) {
      if (A[j] % check and B[j] % check) break;
      if (j == N - 1) chmax(ans, check);
    }
  }
  cout << ans << endl;
}