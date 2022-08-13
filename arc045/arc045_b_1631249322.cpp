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
const int INF    = 1e18;
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

//最小値のquery
template<class T>
struct SegmentTree {
private:
  int n    = 1;
  int init = INF;
  vector<T> data;

public:
  SegmentTree(vector<T> &v) {
    while (n < v.size()) n *= 2;
    data.assign(2 * n - 1, init);
    for (int i = 0; i < v.size(); i++) data[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) data[i] = min(data[2 * i + 1], data[2 * i + 2]);
  }
  T at(int ind) { return data[n - 1 + ind]; }
  T operator[](int ind) { return data[n - 1 + ind]; }
  void update(int ind, T val) {
    ind += n - 1;
    data[ind] = val;
    while (ind > 0) {
      ind       = (ind - 1) / 2;
      data[ind] = min(data[2 * ind + 1], data[2 * ind + 2]);
    }
  }
  T get_min(int L, int R, int k = 0, int l = 0, int r = -1) { //[L, R)
    if (r < 0) r = n;
    if (r <= L || R <= l) return init;
    if (L <= l and r <= R) return data[k];
    return min(get_min(L, R, 2 * k + 1, l, (l + r) / 2), get_min(L, R, 2 * k + 2, (l + r) / 2, r));
  }
};

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, M;
  cin >> N >> M;
  V<int> cum_sum(N + 1);
  VV<int> st(M, V<int>(2));
  rep(i, M) {
    cin >> st[i][0] >> st[i][1];
    cum_sum[st[i][0] - 1]++;
    cum_sum[st[i][1]]--;
  }
  rep(i, N) cum_sum[i + 1] += cum_sum[i];
  SegmentTree<int> seg(cum_sum);
  rep(i, N) if (cum_sum[i] == 1) seg.update(i, -INF);
  V<int> ans;
  rep(i, M) if (seg.get_min(st[i][0] - 1, st[i][1]) >= 0) { ans.emplace_back(i + 1); }
  cout << ans.size() << endl;
  FOR(i, ans)
  cout << i << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-09-10 13:48:42+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/arc045/tasks/arc045_b">B - ドキドキデート大作戦高橋君</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/arc045/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
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
					<td class="text-center">4270 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">224 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">20236 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘SegmentTree<T>::SegmentTree(std::vector<_Tp>&) [with T = long long int]’:
./Main.cpp:87:31:   required from here
./Main.cpp:49:14: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   49 |     while (n < v.size()) n *= 2;
./Main.cpp:51:23: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   51 |     for (int i = 0; i < v.size(); i++) data[i + n - 1] = v[i];
