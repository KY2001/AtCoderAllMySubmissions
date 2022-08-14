#include <bits/stdc++.h>
#pragma GCC optimize ("-Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
#define int long long
using namespace std;
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define all(obj) begin(obj), end(obj)

const int MOD   = 1000000007;
const int INF    = 1e9;
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

struct Rolling_Hash {
  string S;
  vector<int> MODs = {998244353}, B = {1007};
  vector<vector<int>> H;
  vector<vector<int>> pow;
  Rolling_Hash(string &s): S(s) {
    H.assign(MODs.size(), vector<int>(S.size() + 1));
    for (int i = 0; i < MODs.size(); i++)
      for (int j = 1; j <= S.size(); j++) H[i][j] = (H[i][j - 1] * B[i] + S[j - 1]) % MODs[i];
    pow.assign(MODs.size(), vector<int>(S.size() + 1, 1));
    for (int i = 0; i < MODs.size(); i++)
      for (int j = 0; j < S.size(); j++) pow[i][j + 1] = (pow[i][j] * B[i]) % MODs[i];
  }
  vector<int> Hash(int L, int R) { // [L, R)のハッシュ値の配列を返す。全て一致すればok
    vector<int> ret;
    for (int i = 0; i < MODs.size(); i++) ret.emplace_back((H[i][R] - H[i][L] * pow[i][R - L]) % MODs[i]);
    for (int i = 0; i < MODs.size(); i++) ret[i] = ret[i] >= 0 ? ret[i] : ret[i] + MODs[i];
    return ret;
  }
  bool contain(Rolling_Hash S2) { // ローリングハッシュ型のS2を含むか判別
    for (int i = 0; i + S2.S.size() < H[0].size(); i++) {
      if (Hash(i, i + S2.S.size()) == S2.Hash(0, S2.S.size())) {
        return true;
      }
    }
    return false;
  }
};

class FStringsOfEternity {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    string s, t;
    cin >> s >> t;
    string S = s + s;
    while (S.size() < 3 * t.size()) S += s;
    int L_init = 0, R_init = (int)(S.size() / t.size()); // [L_init, R_init]で広義単調増加
    while (S.size() < 5 * t.size()) S += s;
    Rolling_Hash rhS(S);
    Rolling_Hash rht(t);
    int l = L_init - 1, r = R_init + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      string temp;
      rep(i, mid) temp += t;
      Rolling_Hash rh(temp);
      if (rhS.contain(rh)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    L_init = l, R_init = (int)(S.size() / t.size()); // [L_init, R_init]で広義単調増加
    int l2 = L_init - 1, r2 = R_init + 1;
    while (r2 - l2 > 1) {
      int mid = (l2 + r2) / 2;
      string temp;
      rep(i, mid) temp += t;
      Rolling_Hash rh(temp);
      if (rhS.contain(rh)) {
        l2 = mid;
      } else {
        r2 = mid;
      }
    }
    cout << (l2 == l ? l : -1) << endl;
  }
};


signed main() {
  FStringsOfEternity solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
