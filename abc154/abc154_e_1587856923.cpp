#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

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

#define MAX_ 500000
int inv_list[MAX_]; //inv_list[i-1] = inverse of i
int fac[MAX_];
int finv[MAX_];
void nCk_init() {
  inv_list[0] = fac[0] = finv[0] = 1;
  for (int i = 0; i < MAX_ - 1; i++) {
    inv_list[i + 1] = MOD - ((inv_list[(MOD % (i + 2)) - 1] * (MOD / (i + 2))) % MOD);
    fac[i + 1]      = (fac[i] * (i + 2)) % MOD;
    finv[i + 1]     = (finv[i] * inv_list[i + 1]) % MOD;
  }
}
int nCk(int n, int k) {
  if (n <= k || k <= 0) {
    return 1;
  }
  return (fac[n - 1] * ((finv[k - 1] * finv[n - k - 1]) % MOD)) % MOD;
}

class EAlmostEverywhereZero {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    nCk_init();
    string S;
    int K;
    cin >> S >> K;
    int ans = 0;
    FOR(i, 1, S.size()) {
      if (i >= K)
        ans += nCk(i - 1, K - 1) * bpm(9, K);
    }
    vector<int> product(S.size());
    vector<int> cum_sum(S.size(), 0);
    rep(i, S.size()) {
      product[i] = stoi(string(1, S[i]));
    }
    rep(i, S.size() - 1) {
      cum_sum[i + 1] = product[i + 1];
      cum_sum[i + 1] += cum_sum[i];
    }
    if (K == 1) {
      ans += product[0];
    } else if (K == 2) {
      int i = 0;
      FOR(j, i + 1, S.size()) {
        if (cum_sum[i] != 0 || j == i + 1) {
          ans += 9 * (product[i] - 1) + product[j];
        } else {
          ans += 9 * product[i];
        }
      }
    } else {
      int i = 0;
      FOR(j, i + 1, S.size() - 1) {
        FOR(k, j + 1, S.size()) {
          if (cum_sum[j] != 0 && j != i + 1 && k != j + 1) {
            ans += 81* product[i];
          } else if (cum_sum[j] == 0 && cum_sum[k] != 0 && j != i + 1) {
            ans += (product[i] - 1) * 81 + product[j] * 9;
          } else {
            ans += (product[i] - 1) * 81 + (product[j] - 1) * 9 + product[k];
          }
        }
      }
    }
    cout << ans << endl;
  }
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-04-26 08:22:03+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc154/tasks/abc154_e">E - Almost Everywhere Zero</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc154/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">2890 Byte</td>
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