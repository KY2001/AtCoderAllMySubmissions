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
const int INF    = 1e18;
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

template<class T> int Lower_bound_reverse(vector<T> &A, T key) { //key以下の最大値の最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(all(A), key)) - 1;
  return (0 <= ind and ind < A.size()) ? ind : -1;
}

template<class T> int Lower_bound_reverse2(vector<T> &A, T key) { //key以下の最大値の最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(all(A), key)) - 1;
  if (not(0 <= ind and ind < A.size())) return -1;
  return distance(begin(A), lower_bound(all(A), A[ind]));
}

class E {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, L, Q, a, b;
    cin >> N;
    V<int> x(N);
    rfor(i, x) cin >> i;
    x.emplace_back(x.back() + 1);
    cin >> L >> Q;
    VV<int> next(N + 1, V<int>(20));
    rep(i, N + 1) next[i][0]                                                = Lower_bound_reverse(x, x[i] + L) == -1 ? N - 1 : Lower_bound_reverse(x, x[i] + L);
    rep2(j, 1, 20) rep(i, N + 1) next[i][j]                                 = next[next[i][j - 1]][j - 1];
    rep2(j, 1, 20) rep(i, N + 1) if (next[i][j] == x.size() - 1) next[i][j] = INF;
    rep(i, Q) {
      cin >> a >> b;
      a--, b--;
      if (a > b) swap(a, b);
      int ret = 0;
      while (a != b) {
        int s = Lower_bound_reverse2(next[a], b);
        if (s == -1) {
          ret++;
          break;
        }
        ret += _pow(2, s);
        a = next[a][s];
      }
      cout << ret << endl;
    }
  }
};


signed main() {
  E solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-10-06 23:54:30+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/arc060/tasks/arc060_c">E - Tak and Hotels</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/arc060/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">700</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4643 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">139 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">23668 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void E::solve(std::istream&, std::ostream&)’:
./Main.cpp:61:49: warning: comparison of integer expressions of different signedness: ‘__gnu_cxx::__alloc_traits<std::allocator<long long int>, long long int>::value_type’ {aka ‘long long int’} and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   61 |     rep2(j, 1, 20) rep(i, N + 1) if (next[i][j] == x.size() - 1) next[i][j] = INF;
./Main.cpp: In instantiation of ‘long long int Lower_bound_reverse(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:59:110:   required from here
./Main.cpp:36:28: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   36 |   return (0 <= ind and ind < A.size()) ? ind : -1;
./Main.cpp: In instantiation of ‘long long int Lower_bound_reverse2(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:68:48:   required from here
./Main.cpp:41:28: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   41 |   if (not(0 <= ind and ind < A.size())) return -1;