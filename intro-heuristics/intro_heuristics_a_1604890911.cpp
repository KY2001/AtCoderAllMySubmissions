#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)             // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b) for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 998244353;
const int MOD2   = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}
int D;
vector<int> t;
vector<int> c;
vector<vector<int>> s;

int calc_score() {
  vector<int> last(26, 0);
  int ret = 0;
  rep(i, D) {
    ret += s[i][t[i]];
    last[t[i]] = i + 1;
    rep(j, 26) {
      ret -= c[j] * (i + 1 - last[j]);
    }
  }
  return ret;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  double start = clock();
  cin >> D;
  int ans = 0;
  s.assign(D, vector<int>(26));
  t.assign(D, 0);
  c.assign(26, 0);
  rep(i, 26) cin >> c[i];
  rep(i, D) rep(j, 26) cin >> s[i][j];
  vector<int> last(26, 0);
  rep(i, D) {
    vector<int> temp_ans(26);
    rep(j, 26) {
      temp_ans[j] += s[i][j];
      int memo = last[j];
      last[j]  = i + 1;
      rep(k, 26) {
        temp_ans[j] -= c[k] * (i + 1 - last[k]);
      }
      last[j] = memo;
    }
    int maxi = MAX(temp_ans);
    ans += maxi;
    rep(j, 26) {
      if (temp_ans[j] == maxi) {
        last[j] = i + 1;
        t[i]    = j;
        break;
      }
    }
  }
  mt19937 mt{std::random_device{}()};
  uniform_int_distribution<int> dist(0, 25);
  vector<int> t_new(D);
  while ((clock() - start) / CLOCKS_PER_SEC < 1.96) {
    int maxi           = -1;
    rep(i, D) t_new[i] = dist(mt);
    rep(i, D) {
      swap(t[i], t_new[i]);
      int score = calc_score();
      if (score > ans) {
        ans  = score;
        maxi = i;
      }
      swap(t[i], t_new[i]);
    }
    if (maxi != -1)
      t[maxi] = t_new[maxi];
  }
  FOR(i, t)
  cout << i + 1 << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-09 12:01:51+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/intro-heuristics/tasks/intro_heuristics_a">A - AtCoder Contest Scheduling</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/intro-heuristics/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (Clang 10.0.0)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">111964068</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">3347 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">1981 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3280 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp:41:11: warning: unused variable 'MOD2' [-Wunused-const-variable]
const int MOD2   = 1000000007;
          ^
./Main.cpp:42:11: warning: unused variable 'INF' [-Wunused-const-variable]
const int INF    = (int)(1e13 + 7);
          ^
./Main.cpp:43:14: warning: unused variable 'EPS' [-Wunused-const-variable]
const double EPS = 1e-14;
             ^
3 warnings generated.
