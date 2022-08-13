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
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

bool is_prime(int n) {
  if ((n % 2 == 0 && n != 2) || n == 1) return false;
  for (int k = 3; k < (int)sqrt((double(n))) + 2; k += 2)
    if (n % k == 0) return false;
  return true;
}

template <typename Iterator>
inline bool next_combination(const Iterator first, const Iterator last, int num) {
  Iterator k = first + num;
  if ((first == last) || (first == k) || (last == k))
    return false;
  Iterator itr1 = first;
  Iterator itr2 = last;
  ++itr1;
  if (last == itr1)
    return false;
  itr1 = last;
  --itr1;
  itr1 = k;
  --itr2;
  while (first != itr1) {
    if (*--itr1 < *itr2) {
      Iterator j = k;
      while (!(*itr1 < *j)) ++j;
      std::iter_swap(itr1, j);
      ++itr1;
      ++j;
      itr2 = k;
      std::rotate(itr1, j, last);
      while (last != j) {
        ++j;
        ++itr2;
      }
      std::rotate(k, itr2, last);
      return true;
    }
  }
  std::rotate(first, k, last);
  return false;
}

class DFiveFiveEverywhere {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    V<int> primes;
    rep(i, 55555 + 1) if (is_prime(i)) primes.emplace_back(i);
    reverse(ALL(primes));
    V<int> ans;
    FOR(i, primes) {
      if (ans.size() == N) break;
      if (ans.size() < 4) {
        ans.emplace_back(i);
      } else {
        bool yes = true;
        do {
          if (is_prime(ans[0] + ans[1] + ans[2] + ans[3] + i)) {
            yes = false;
            break;
          }
        } while (next_combination(ALL(ans), 4));
        if (yes) ans.emplace_back(i);
      }
      sort(ALL(ans));
    }
    FOR(i, ans)
    cout << i << " ";
    cout << endl;
  }
};


signed main() {
  DFiveFiveEverywhere solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-07-02 18:10:16+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc096/tasks/abc096_d">D - Five, Five Everywhere</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc096/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">4679 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">38 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3676 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void DFiveFiveEverywhere::solve(std::istream&, std::ostream&)’:
./Main.cpp:98:22: warning: comparison of integer expressions of different signedness: ‘std::vector<long long int, std::allocator<long long int> >::size_type’ {aka ‘long unsigned int’} and ‘long long int’ [-Wsign-compare]
   98 |       if (ans.size() == N) break;
      |           ~~~~~~~~~~~^~~~
