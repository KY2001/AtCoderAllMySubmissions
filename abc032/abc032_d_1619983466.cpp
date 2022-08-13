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
const int INF    = LLONG_MAX; // 9.2e18
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

template <class T> int Lower_bound_reverse(vector<T> &A, T key) { //key以下の最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

class D {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, W;
    cin >> N >> W;
    V<int> v(N);
    V<int> w(N);
    rep(i, N) cin >> v[i] >> w[i];
    if (N == 1) {
      cout << ((w[0] <= W) ? v[0] : 0) << endl;
    } else {
      int n1 = N / 2, n2 = _ceil(N, 2);
      V<P<int, int>> wv1(1 << n1);
      V<P<int, int>> wv2(1 << n2);
      rep(i, 1 << n1) {
        rep(j, n1) if ((i >> j) & 1) {
          wv1[i].fi += w[j];
          wv1[i].se += v[j];
        }
      }
      rep(i, 1 << n2) {
        rep(j, n2) if ((i >> j) & 1) {
          wv2[i].fi += w[n1 + j];
          wv2[i].se += v[n1 + j];
        }
      }
      sort(ALL(wv2));
      V<int> wv2_vmax(1 << n2);
      wv2_vmax[0] = wv2[0].se;
      rep(i, (1 << n2) - 1) chmax(wv2_vmax[i + 1], max(wv2_vmax[i], wv2[i + 1].se));
      int ans = 0;
      FOR(i, wv1) {
        int w1 = i.fi, v1 = i.se;
        int temp = Lower_bound_reverse(wv2, {W - w1, INF});
        if (temp == -1) continue;
        chmax(ans, v1 + wv2_vmax[temp]);
      }
      cout << ans << endl;
    }
  }
};


signed main() {
  D solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-05-03 04:24:26+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc032/tasks/abc032_d">D - ナップサック問題</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc032/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">34</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4219 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">19 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">4500 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘long long int Lower_bound_reverse(std::vector<_Tp>&, T) [with T = std::pair<long long int, long long int>]’:
./Main.cpp:82:58:   required from here
./Main.cpp:41:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<std::pair<long long int, long long int>, std::allocator<std::pair<long long int, long long int> > >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   41 |   if (0 <= ind and ind < A.size()) return ind;
