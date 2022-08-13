#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define sum(x)              accumulate(ALL(x), 0LL)
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

class N {
public:
  static void solve(istream &cin, ostream &cout) {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    rep(i, N) a[i] = i + 1;
    map<int, int> check;
    rep(i, Q) {
      int t, x, y;
      cin >> t >> x >> y;
      if (t == 1) {
        check[x - 1]++;
        check[x]++;
        swap(a[x - 1], a[x]);
      } else {
        auto L = check.lower_bound(x - 1);
        auto R = check.lower_bound(y - 1);
        vector<int> del;
        for (auto j = L; true; j = next(j, 1)) {
          if (j->first >= x - 1 and j->first <= y - 1) del.emplace_back(j->first);
          if (j == R) break;
        }
        int p = 1;
        while (p) {
          p = 0;
          for (auto j = L; true; j = next(j, 1)) {
            int tmp = j->first;
            if (a[tmp - 1] > a[tmp] and tmp >= x and tmp <= y - 1) {
              swap(a[tmp - 1], a[tmp]);
              p++;
            }
            if (a[tmp] > a[tmp + 1] and tmp >= x - 1 and tmp + 1 <= y - 1) {
              swap(a[tmp], a[tmp + 1]);
              p++;
            }
            if (j == R) break;
          }
        }
        FOR(j, del) {
          check.erase(j);
        }
      }
    }
    FOR(i, a) {
      cout << i << " ";
    }
    cout << endl;
  }
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-06-07 23:26:04+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/past202005-open/tasks/past202005_n">N - Swap and Sort</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/past202005-open/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">2497 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>/usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status
