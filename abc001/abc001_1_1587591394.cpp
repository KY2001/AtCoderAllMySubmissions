#include "bits/stdc++.h"
#define int long long
#define For(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define Max(x) *max_element(ALL(x))
#define Min(x) *min_element(ALL(x))
#define Lower_bound(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define Upper_bound(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int bpm(int x, int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
  }
  return ans;
}


class A {
public:
	void solve(std::istream& cin, std::ostream& cout) {
          int H1, H2;
          cin>>H1>>H2;
          cout<<H1-H2<<endl;
	}
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-04-23 06:36:34+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc001/tasks/abc001_1">A - 積雪深差</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc001/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view ky's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++14 (GCC 5.4.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">0</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">1072 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 0 has invalid symbol index 11
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 1 has invalid symbol index 12
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 2 has invalid symbol index 2
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 3 has invalid symbol index 2
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 4 has invalid symbol index 11
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 5 has invalid symbol index 13
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 6 has invalid symbol index 13
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 7 has invalid symbol index 13
/usr/bin/ld: /usr/lib/debug/usr/lib/x86_64-linux-gnu/crt1.o(.debug_info): relocation 8 has invalid symbol ...