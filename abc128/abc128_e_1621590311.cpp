//@Author: KeinYukiyoshi

// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#define int long long
//#define double __float80
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

template <class T> int Lower_bound(vector<T> &A, T key) { //key以上の最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(ALL(A), key));
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Lower_bound_reverse(vector<T> &A, T key) { //key以下の最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Upper_bound(vector<T> &A, T key) { //keyより大きい最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), upper_bound(ALL(A), key));
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template <class T> int Upper_bound_reverse(vector<T> &A, T key) { //keyより小さい最大のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(ALL(A), key)) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

class ERoadwork {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, Q;
    cin >> N >> Q;
    V<int> S(N);
    V<int> T(N);
    V<int> X(N);
    V<int> D(Q);
    rep(i, N) cin >> S[i] >> T[i] >> X[i];
    rep(i, Q) cin >> D[i];
    V<int> ans(Q, -1);
    VV<int> XST(N);
    rep(i, N) XST[i] = {X[i], S[i] - X[i], T[i] - X[i] - 1};
    BIT<int> check(Q);
    rep(i, Q) check.add(i, 1);
    sort(ALL(XST));
    sort(ALL(D));
    rep(i, N) {
      int L = Lower_bound(D, XST[i][1]);
      int R = Lower_bound_reverse(D, XST[i][2]);
      if (check.sum(L, R + 1) == 0) continue;
      rep2(j, L, R + 1) if (check.at(j) == 1) {
        check.add(j, -1);
        ans[j] = XST[i][0];
      }
    }
    FOR(i, ans)
    cout << i << endl;
  }
};


signed main() {
  ERoadwork solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-05-21 18:45:11+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc128/tasks/abc128_e">E - Roadwork</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc128/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">500</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">5603 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">456 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">23476 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘long long int Lower_bound(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:120:39:   required from here
./Main.cpp:78:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   78 |   if (0 <= ind and ind < A.size()) return ind;
./Main.cpp: In instantiation of ‘long long int Lower_bound_reverse(std::vector<_Tp>&, T) [with T = long long int]’:
./Main.cpp:121:47:   required from here
./Main.cpp:83:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   83 |   if (0 <= ind and ind < A.size()) return ind;
