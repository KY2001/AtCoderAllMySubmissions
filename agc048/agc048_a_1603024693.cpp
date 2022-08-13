/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define SUM(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int a, int b) {                                                             //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

class AAtcoderS {
public:
  static void solve(istream &cin, ostream &cout) {
    int t;
    cin >> t;
    rep(_, t) {
      string S;
      cin >> S;
      int place = -1;
      string s  = "atcoder";
      if (S.size() <= s.size()) {
        map<int, int> check;
        rep(i, S.size()) {
          check[s[i]] = 0;
        }
        FOR(i, S) {
          check[i]++;
        }
        FOR(i, check) {
          if (i.second == 0) {
            goto label;
          }
        }
        cout << -1 << endl;
        goto label2;
      }
    label:;
      rep(i, min(7LL, (int)S.size())) {
        if (S[i] == s[i]) {
          continue;
        } else if (S[i] > s[i]) {
          break;
        } else {
          place = i;
          break;
        }
      }
      if (place < 0) {
        cout << 0 << endl;
      } else {
        REP(i, place + 1, S.size()) {
          if (S[i] >= s[place]) {
            cout << i - place << endl;
          } else if (i == S.size() - 1) {
            cout << -1 << endl;
          }
        }
        if (place == S.size()-1) {
          cout << -1 << endl;
        }
      }
    label2:;
    }
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  AAtcoderS solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-10-18 21:38:13+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/agc048/tasks/agc048_a">A - atcoder < S</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/agc048/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">2765 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">21 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3648 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void AAtcoderS::solve(std::istream&, std::ostream&)’:
./Main.cpp:77:24: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   77 |           } else if (i == S.size() - 1) {
      |                      ~~^~~~~~~~~~~~~~~
./Main.cpp:81:19: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   81 |         if (place == S.size()-1) {
      |             ~~~~~~^~~~~~~~~~~~~