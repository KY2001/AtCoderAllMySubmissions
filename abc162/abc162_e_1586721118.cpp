#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <vector>
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define SQR(x) (x) * (x)
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);
int bpm(int x, unsigned int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (unsigned int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = SQR(x);
    x %= MOD;
  }
  return ans;
}
int LIST[100000 + 10]{};
signed main() {
  int N, K;
  cin >> N >> K;
  for (int i = 100000; i >= 1; i--) {
    LIST[i] = bpm(K / i, N) * i;
    for (int j = 2; i * j <= K; j++) {
      LIST[i] -= LIST[i * j] / (i * j) * i;
    }
  }
  int ans = accumulate(ALL(LIST), 0LL) % MOD;
  cout << ans << endl;
}
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-04-13 04:51:58+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc162/tasks/abc162_e">E - Sum of gcd of Tuples (Hard)</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc162/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">1360 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">24 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">4604 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘long long int bpm(long long int, long long unsigned int)’:
./Main.cpp:38:30: warning: comparison of integer expressions of different signedness: ‘long long unsigned int’ and ‘long long int’ [-Wsign-compare]
   38 |   for (unsigned int i = 0; i < digit; i++) {
      |                            ~~^~~~~~~
