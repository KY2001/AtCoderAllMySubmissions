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

class AAKIBA {
  public:
    static void solve(istream &cin, ostream &cout) {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        string S, to = "AKIHABARA";
        cin >> S;
        rep(i, (1 << to.size())) {
            string check;
            rep(j, to.size()) if ((i >> j) & 1) check += to[j];
            int cnt = 0;
            rfor(j, check) if (j != 'A') cnt++;
            if (cnt != to.size() - 4) continue;
            if (check == S) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
};


signed main() {
  AAKIBA solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-12-10 17:08:32+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/cf17-final/tasks/cf17_final_a">A - AKIBA</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/cf17-final/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">300</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">3643 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">6 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3644 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void AAKIBA::solve(std::istream&, std::ostream&)’:
./Main.cpp:47:21: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   47 |             if (cnt != to.size() - 4) continue;
      |                 ~~~~^~~~~~~~~~~~~~~~
