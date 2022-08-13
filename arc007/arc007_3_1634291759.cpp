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
double _mod(double a, int mod = MOD) { return fmod(a, mod) >= 0 ? fmod(a, mod) : fmod(a, mod) + mod; }
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};

template<typename Iterator>
inline bool next_combination(const Iterator first, const Iterator last, int num) {
  Iterator k = first + num;
  if ((first == last) || (first == k) || (last == k))
    return false;
  Iterator itr1 = first;
  Iterator itr2 = last;
  ++itr1;
  if (last == itr1)
    return false;
  itr1 = last;
  --itr1;
  itr1 = k;
  --itr2;
  while (first != itr1) {
    if (*--itr1 < *itr2) {
      Iterator j = k;
      while (!(*itr1 < *j)) ++j;
      std::iter_swap(itr1, j);
      ++itr1;
      ++j;
      itr2 = k;
      std::rotate(itr1, j, last);
      while (last != j) {
        ++j;
        ++itr2;
      }
      std::rotate(k, itr2, last);
      return true;
    }
  }
  std::rotate(first, k, last);
  return false;
}

class C {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    string c;
    cin >> c;
    int N = c.size();
    rep2(i, 1, N + 1) {
      V<int> comb;
      rep(j, N + 1) comb.emplace_back(j);
      do {
        V<bool> check(2 * N);
        rep(j, i) {
          rep(k, N) if (c[k] == 'o') check[comb[j] + k] = true;
        }
        int cnt = 0;
        rep(j, 2 * N) {
          if (check[j]) {
            cnt++;
          } else {
            cnt = 0;
          }
          if (cnt >= N) {
            cout << i << endl;
            return;
          }
        }
      } while (next_combination(all(comb), i));
    }
  }
};


signed main() {
  C solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
