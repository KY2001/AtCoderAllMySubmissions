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
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define _max(x) *max_element(ALL(x))
#define _min(x) *min_element(ALL(x))
#define _sum(x) accumulate(ALL(x), 0LL)

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
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, ans = 0;
  string S;
  cin >> N >> S;
  if (S.size() % 2) {
    cout << -1 << endl;
  } else if (N < S.size() / 2) {
    rep2(i, N, S.size() / 2) {
      if (S[i] != S[i] + S.size() / 2) {
        cout << -1 << endl;
        return 0;
      }
    }
    rep(i, N) ans += (S[i] != S[i + S.size() / 2]) ? 1 : 0;
    cout << ans << endl;
  } else {
    rep(i, S.size() / 2) ans += (S[i] != S[i + S.size() / 2]) ? 1 : 0;
    cout << ans << endl;
  }
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-09-10 13:30:31+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/code-festival-2015-morning-easy/tasks/cf_2015_morning_easy_b">B - ヘイホー君と置き換え</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/code-festival-2015-morning-easy/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">100</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">3254 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">8 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3552 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:49:16: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   49 |   } else if (N < S.size() / 2) {
      |              ~~^~~~~~~~~~~~~~
./Main.cpp:51:16: warning: comparison of integer expressions of different signedness: ‘__gnu_cxx::__alloc_traits<std::allocator<char>, char>::value_type’ {aka ‘char’} and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   51 |       if (S[i] != S[i] + S.size() / 2) {
