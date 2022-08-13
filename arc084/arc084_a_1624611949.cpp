//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
// #define double __float80
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
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-2;
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
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

class ELogs {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, K;
    cin >> N >> K;
    V<double> A(N);
    rep(i, N) cin >> A[i];
    double L = 0, R = (3 * 1e9); // [L_init, R_init]で広義単調増加
    while (R - L > EPS) {
      double mid = (L + R) / 2;
      int ret    = 0;
      rep(i, N) ret += (int)ceil(A[i] / mid) - 1;
      if (ret <= K) {
        R = mid;
      } else {
        L = mid;
      }
    }
    cout << (int)ceil(L) << endl;
  }
};


signed main() {
  ELogs solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
// #define double __float80
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
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-2;
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
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

class ELogs {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, K;
    cin >> N >> K;
    V<double> A(N);
    rep(i, N) cin >> A[i];
    double L = 0, R = (3 * 1e9); // [L_init, R_init]で広義単調増加
    while (R - L > EPS) {
      double mid = (L + R) / 2;
      int ret    = 0;
      rep(i, N) ret += (int)ceil(A[i] / mid) - 1;
      if (ret <= K) {
        R = mid;
      } else {
        L = mid;
      }
    }
    cout << (int)ceil(L) << endl;
  }
};


signed main() {
  ELogs solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}

</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-06-25 18:05:49+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/arc084/tasks/arc084_a">C - Snuke Festival</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/arc084/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">0</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">6854 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp:97:11: error: redefinition of ‘const long long int MOD’
   97 | const int MOD   = 1000000007;
      |           ^~~
./Main.cpp:22:11: note: ‘const long long int MOD’ previously defined here
   22 | const int MOD   = 1000000007;
      |           ^~~
./Main.cpp:101:14: error: redefinition of ‘const double EPS’
  101 | const double EPS = 1e-2;
      |              ^~~
./Main.cpp:26:14: note: ‘const double EPS’ previously defined here
   26 | const double EPS = 1e-2;
      |              ^~~
./Main.cpp:102:14: error: redefinition of ‘const double PI’
  102 | const double PI  = 3.14159265358979;
      |              ^~
./Main.cpp:27:14: note: ‘const double PI’ previously defined here
   27 | const double PI  = 3.14159265358979;
      |              ^~
./Main.cpp:107:24: error: redefinition of ‘template<class T> bool chmax(T&, const T&)’
  107 | template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
      |                        ^~~~~
./Main.cpp:32:24: note: ‘template<class T> bool chmax(T&, const T&)’ previously declared here
   32 | template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
      |                        ^~~~~
./Main.cpp:108:24: error: redefinition of ‘template<class T> bool chmin(T&, const T&)’
  108 | template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
      |                        ^~~~~
./Main.cpp:33:24: note: ‘template<class T> bool chmin(T&, const T&)’ previously declared here
   33 | template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
      |                        ^~~~~
./Main.cpp:109:5: error: redefinition of ‘long long int _ceil(long long int, long long int)’
  109 | int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
      |     ^~~~~
./Main.cpp:34:5: note: ‘long long int _ceil(long long int, long long int)’ previously defined here
   34 | in...