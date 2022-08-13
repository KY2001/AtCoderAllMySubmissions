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
bool out_of_border(int a, int b) { return a < 0 or a > 10000 or b < 0 or b > 10000; }
bool in(int a, int b, int c, int d, int x, int y) { // (x, y) in (a, b)×(c, d)
  return a < x and x < c and b < y and y < d;
}
bool duplicate(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2) { return in(a1, b1, c1, d1, a2, b2) or in(a1, b1, c1, d1, c2, d2) or in(a1, b1, c1, d1, a2, d2) or in(a1, b1, c1, d1, c2, b2); }

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  double start_time = clock();
  int n;
  cin >> n;
  V<int> x(n);
  V<int> y(n);
  V<int> r(n);
  V<V<int>> ans(n, V<int>(4));
  rep(i, n) cin >> x[i] >> y[i] >> r[i];
  V<P<int, int>> r_num(n);
  rep(i, n) r_num[i] = {r[i], i};
  sort(ALL(r_num));
  rep(i, n) {
    int now    = r_num[i].se;
    int length = sqrt(r[now]);
    ans[now]   = {x[now], y[now], x[now] + length, y[now] + length};
    rep(j, n) if (now != j and duplicate(x[now], y[now], x[now] + length, y[now] + length, ans[j][0], ans[j][1], ans[j][2], ans[j][3]) or out_of_border(ans[now][2], ans[now][3])) {
      ans[now] = {j, 0, j + 1, 1};
      break;
    }
  }
  FOR(i, ans) {
    cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << endl;
  }
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-03-06 18:03:09+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/ahc001/tasks/ahc001_a">A - AtCoder Ad</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/ahc001/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">3904 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">6 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3656 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:63:28: warning: suggest parentheses around ‘&&’ within ‘||’ [-Wparentheses]
   63 |     rep(j, n) if (now != j and duplicate(x[now], y[now], x[now] + length, y[now] + length, ans[j][0], ans[j][1], ans[j][2], ans[j][3]) or out_of_border(ans[now][2], ans[now][3])) {
      |                   ~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
./Main.cpp:48:10: warning: unused variable ‘start_time’ [-Wunused-variable]
   48 |   double start_time = clock();
      |          ^~~~~~~~~~
