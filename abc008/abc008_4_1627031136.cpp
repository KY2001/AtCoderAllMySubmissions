#include <bits/stdc++.h>
using namespace  std;

class D {
public:
  static void solve(istream &cin, ostream &cout) {
    cout << "wa" << endl;
  }
};


signed main() {
  D solver;
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
					<td class="text-center"><time class='fixtime fixtime-second'>2021-07-23 18:05:36+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc008/tasks/abc008_4">D - 金塊ゲーム</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc008/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
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
					<td class="text-center">301 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Wrong Answer">WA</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">9 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3596 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void D::solve(std::istream&, std::ostream&)’:
./Main.cpp:6:30: warning: unused parameter ‘cin’ [-Wunused-parameter]
    6 |   static void solve(istream &cin, ostream &cout) {
      |                     ~~~~~~~~~^~~
