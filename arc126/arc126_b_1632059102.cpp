// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("unroll-loops")
#define int long long
#define endl '\n'
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
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

//最小値のquery
template<class T>
struct SegmentTree {
private:
  int n    = 1;
  int init = 0;
  vector<T> data;

public:
  SegmentTree(vector<T> &v) {
    while (n < v.size()) n *= 2;
    data.assign(2 * n - 1, init);
    for (int i = 0; i < v.size(); i++) data[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) data[i] = max(data[2 * i + 1], data[2 * i + 2]);
  }
  SegmentTree(int N) { // 全て0で初期化
    while (n < N) n *= 2;
    data.assign(2 * n - 1, init);
    for (int i = 0; i < N; i++) data[i + n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) data[i] = max(data[2 * i + 1], data[2 * i + 2]);
  }
  T at(int ind) { return data[n - 1 + ind]; }
  T operator[](int ind) { return data[n - 1 + ind]; }
  void update(int ind, T val) {
    ind += n - 1;
    data[ind] = val;
    while (ind > 0) {
      ind       = (ind - 1) / 2;
      data[ind] = max(data[2 * ind + 1], data[2 * ind + 2]);
    }
  }
  T get_max(int L, int R, int k = 0, int l = 0, int r = -1) { //[L, R)
    if (r < 0) r = n;
    if (r <= L || R <= l) return init;
    if (L <= l and r <= R) return data[k];
    return max(get_max(L, R, 2 * k + 1, l, (l + r) / 2), get_max(L, R, 2 * k + 2, (l + r) / 2, r));
  }
};

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, M;
  cin >> N >> M;
  V<int> a(M), b(M);
  rep(i, M) cin >> a[i] >> b[i];
  deque<V<int>> ab(M);
  rep(i, M) ab[i] = {a[i], b[i]};
  sort(all(ab));
  SegmentTree<int> seg(N + 1);
  rep(i, N + 1) {
    if (ab.empty()) break;
    V<int> temp;
    int ret = 0;
    while (ab[0][0] == i) {
      temp.emplace_back(ab[0][1]);
      ab.pop_front();
      if (ab.empty()) break;
    }
    VV<int> memo;
    rfor(j, temp) {
      memo.push_back({j, seg.get_max(0, j) + 1});
    }
    rfor(j, memo) {
      seg.update(j[0], max(seg.at(j[0]), j[1]));
    }
  }
  cout << seg.get_max(0, N + 1) << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-09-19 22:45:02+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/arc126/tasks/arc126_b">B - Cross-free Matching</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/arc126/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">400</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4760 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">154 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">21696 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:96:9: warning: unused variable ‘ret’ [-Wunused-variable]
   96 |     int ret = 0;
      |         ^~~
