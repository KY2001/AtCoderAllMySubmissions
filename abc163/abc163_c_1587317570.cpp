#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}
unordered_map<int, int> element_num; //change type if you need
template <class T>
void counter(T container) {
  for (int i = 0; i < container.size(); i++) {
    element_num[container[i]] += 1;
  }
}
signed main() {
  int N = in();
  vector<int> A(N - 1);
  rep(i, N - 1) {
    cin >> A[i];
  }
  counter(A);
  rep(i, N) {
    cout << element_num[i + 1] << endl;
  }
}
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-04-20 02:32:50+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc163/tasks/abc163_c">C - management</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc163/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">1088 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">362 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">14536 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In instantiation of ‘void counter(T) [with T = std::vector<long long int>]’:
./Main.cpp:38:12:   required from here
./Main.cpp:28:21: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<long long int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
   28 |   for (int i = 0; i < container.size(); i++) {
