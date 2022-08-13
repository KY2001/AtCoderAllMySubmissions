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
const int INF    = (int)1e10;
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

template <class T> struct BIT {
private:
  vector<T> data;
  int n;
  int s = 1;

public:
  BIT(int n) : n(n) {
    data.assign(n, 0);
    while (s * 2 <= n) { s *= 2; };
  }
  T sum(int R) { // return sum of [0, R);
    T ret = 0;
    for (--R; R >= 0; R = (R & (R + 1)) - 1) ret += data[R];
    return ret;
  }
  T sum(int L, int R) { return sum(R) - sum(L); } //return sum of [L, R);
  void add(int ind, T val) {
    for (; ind < n; ind |= ind + 1) data[ind] += val;
  }
  T at(int ind) { return sum(ind, ind + 1); }
  T operator[](const int ind) { return at(ind); }
  int LOWER_BOUND_(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = s; k > 0; k /= 2)
      if (x + k - 1 <= n - 1 && data[x + k - 1] < w) {
        w -= data[x + k - 1];
        x += k;
      }
    return x;
  }
};

class FMaxMatrix {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, M, Q;
    cin >> N >> M >> Q;
    V<int> T(Q);
    V<int> X(Q);
    V<int> Y(Q);
    map<int, int> nums;
    map<int, int> num;
    nums[INF]++;
    nums[-INF]++;
    nums[0]++;
    rep(i, Q) {
      cin >> T[i] >> X[i] >> Y[i];
      X[i]--;
      nums[Y[i]]++;
    }
    int now = 0;
    FOR(i, nums) {
      num[i.fi] = now;
      now++;
    }
    int ans = 0;
    BIT<int> a(now);
    BIT<int> aa(now);
    BIT<int> b(now);
    BIT<int> bb(now);
    a.add(num[0], N);
    b.add(num[0], M);
    V<int> A(N);
    V<int> B(M);
    rep(i, Q) {
      if (T[i] == 1) {
        int c = nums.lower_bound(A[X[i]])->fi;
        int d = nums.lower_bound(Y[i])->fi;
        if (Y[i] > A[X[i]]) {
          ans += (Y[i] - A[X[i]]) * b.sum(num[c]);
          ans += Y[i] * b.sum(num[c], num[d]);
          ans -= bb.sum(num[c], num[d]);
        } else if (Y[i] < A[X[i]]) {
          ans += (Y[i] - A[X[i]]) * b.sum(num[c]);
          ans -= Y[i] * b.sum(num[d], num[c]);
          ans += bb.sum(num[d], num[c]);
        }
        a.add(num[Y[i]], 1);
        aa.add(num[Y[i]], Y[i]);
        a.add(num[A[X[i]]], -1);
        aa.add(num[A[X[i]]], -A[X[i]]);
        A[X[i]] = Y[i];
      } else {
        int c = nums.lower_bound(B[X[i]])->fi;
        int d = nums.lower_bound(Y[i])->fi;
        if (Y[i] > B[X[i]]) {
          ans += (Y[i] - B[X[i]]) * a.sum(num[c]);
          ans += Y[i] * a.sum(num[c], num[d]);
          ans -= aa.sum(num[c], num[d]);
        } else if (Y[i] < B[X[i]]) {
          ans += (Y[i] - B[X[i]]) * a.sum(num[c]);
          ans -= Y[i] * a.sum(num[d], num[c]);
          ans += aa.sum(num[d], num[c]);
        }
        b.add(num[Y[i]], 1);
        bb.add(num[Y[i]], Y[i]);
        b.add(num[B[X[i]]], -1);
        bb.add(num[B[X[i]]], -B[X[i]]);
        B[X[i]] = Y[i];
      }
      cout << ans << endl;
    }
  }
};


signed main() {
  FMaxMatrix solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

