/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define inv(i, a, b)        for (int i = (int)(a); i >= (int)(b); i--)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl                endl

using namespace std;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int x, unsigned int y) {                                                    //return x^y in order(log(y))
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

class BTripleDots {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    int K;
    string S;
    cin >> K >> S;
    if (S.size() <= K) {
      cout << S << endl;
    } else {
      cout << S.substr(0, K) + string(3, '.') << endl;
    }
  }
};


signed main() {
  BTripleDots solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-05-17 21:03:50+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc168/tasks/abc168_b">B - ... (Triple Dots)</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc168/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">200</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">1993 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">4 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3728 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void BTripleDots::solve(std::istream&, std::ostream&)’:
./Main.cpp:48:18: warning: comparison of integer expressions of different signedness: ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} and ‘long long int’ [-Wsign-compare]
   48 |     if (S.size() <= K) {
      |         ~~~~~~~~~^~~~