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
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};

template<class T> int Lower_bound(vector<T> &A, T key) { //key以上の最小のindex, 存在しない場合-1を返す。
  int ind = distance(begin(A), lower_bound(all(A), key));
  return (0 <= ind and ind < A.size()) ? ind : -1;
}

int N, u, v;
VVV<int> graph;
V<bool> already;
V<int> ans;
vector<int> dfs(int now) {
  already[now] = true;
  int num      = 1;
  int cost     = 0;
  rfor(i, graph[now]) {
    if (already[i[0]]) continue;
    i = dfs(i[0]);
    num += i[1];
    cost += i[1] + i[2];
  }
  already[now] = false;
  return {now, num, cost};
}

void dfs2(int now, vector<int> &prev) {
  already[now] = true;
  int cost     = 1;
  int cost2     = 0;
  if (now != 0) {
    V<int> temp    = {prev[0], -2, -2};
    int ss         = Lower_bound(graph[now], temp);
    graph[now][ss] = prev;
  }
  prev[1] = 1;
  rfor(i, graph[now]) {
    cost += i[1] * 2 + i[2];
    cost2 += i[1] + i[2];
    prev[1] += i[1];
  }
  rfor(i, graph[now]) {
    if (already[i[0]]) continue;
    prev[0]   = now;
    ans[i[0]] = cost - (i[1] * 2);
    prev[1] -= i[1];
    prev[2] = cost2 - (i[1] + i[2]);
    dfs2(i[0], prev);
  }
}

class FDistanceSums2 {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cin >> N;
    graph.resize(N);
    ans.resize(N);
    already.resize(N);
    rep(i, N - 1) {
      cin >> u >> v;
      graph[u - 1].push_back({v - 1, 0, 0});
      graph[v - 1].push_back({u - 1, 0, 0});
    }
    rep(i, N) sort(all(graph[i]));
    ans[0]      = dfs(0)[2];
    V<int> temp = {0, 0, 0};
    dfs2(0, temp);
    rfor(i, ans) cout << i << endl;
  }
};


signed main() {
  FDistanceSums2 solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-09-26 22:51:21+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc220/tasks/abc220_f">F - Distance Sums 2</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc220/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">4619 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">416 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">51344 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘long long int Lower_bound(std::vector<_Tp>&, T) [with T = std::vector<long long int>]’:
./Main.cpp:61:50:   required from here
./Main.cpp:34:28: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<std::vector<long long int>, std::allocator<std::vector<long long int> > >::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   34 |   return (0 <= ind and ind < A.size()) ? ind : -1;
