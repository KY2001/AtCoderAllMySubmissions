#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  string S;
  cin >> K >> S;
  if (S.size() <= K) {
    cout << S << endl;
  } else {
    cout << S.substr(0, K) + "..." << endl;
  }
}
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-06-17 19:47:38+0900</time></td>
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
					<td class="text-center">218 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">9 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3604 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:8:16: warning: comparison of integer expressions of different signedness: ‘std::__cxx11::basic_string<char>::size_type’ {aka ‘long unsigned int’} and ‘int’ [-Wsign-compare]
    8 |   if (S.size() <= K) {
      |       ~~~~~~~~~^~~~
