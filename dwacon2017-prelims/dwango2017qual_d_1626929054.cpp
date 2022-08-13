#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];
  priority_queue<vector<int>, vector<vector<int>>, greater<>> pos;
  int ans   = 0;
  int sum_X = 0;
  int sum_Y = 0;
  rep(i, N) {
    if (Y[i] >= X[i]) {
      sum_Y += Y[i];
      ans = max(ans, sum_X + sum_Y);
      continue;
    }
    pos.push({X[i], i});
    sum_X += X[i];
    ans = max(ans, sum_X + sum_Y);
    if (pos.size() == M) {
      sum_X -= pos.top()[0];
      sum_Y += Y[pos.top()[1]];
      pos.pop();
    }
  }
  cout << ans << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-07-22 13:44:14+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/dwacon2017-prelims/tasks/dwango2017qual_d">D - ネタだけ食べたい寿司</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/dwacon2017-prelims/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
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
					<td class="text-center">724 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">53 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">10184 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:24:20: warning: comparison of integer expressions of different signedness: ‘std::priority_queue<std::vector<long long int>, std::vector<std::vector<long long int> >, std::greater<void> >::size_type’ {aka ‘long unsigned int’} and ‘long long int’ [-Wsign-compare]
   24 |     if (pos.size() == M) {
      |         ~~~~~~~~~~~^~~~
