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

int ceil_(int a, int b) { return (a + (b - 1)) / b; }
int positive_surplus(int &a) { return (a + MOD) % MOD; }
int bpm(int x, unsigned int y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (unsigned int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}

template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last) {
  if ((first == last) || (first == k) || (last == k))
    return false;
  Iterator itr1 = first;
  Iterator itr2 = last;
  ++itr1;
  if (last == itr1)
    return false;
  itr1 = last;
  --itr1;
  itr1 = k;
  --itr2;
  while (first != itr1) {
    if (*--itr1 < *itr2) {
      Iterator j = k;
      while (!(*itr1 < *j)) ++j;
      std::iter_swap(itr1, j);
      ++itr1;
      ++j;
      itr2 = k;
      std::rotate(itr1, j, last);
      while (last != j) {
        ++j;
        ++itr2;
      }
      std::rotate(k, itr2, last);
      return true;
    }
  }
  std::rotate(first, k, last);
  return false;
}

int a[50];
int b[50];
int c[50];
int d[50];
int maxi = 0;
signed main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  rep(i, Q) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
    cin >> d[i];
  }
  vector<int> A(M + N - 1);
  FOR(i, 1, M + N)
  A[i - 1] = i;
  do {
    int ret = 0;
    rep(i, Q) if ((A[b[i] - 1] - (b[i] - 1)) - (A[a[i] - 1] - (a[i] - 1)) == c[i]) ret += d[i];
    maxi = max(maxi, ret);
  } while (next_combination(A.begin(), A.begin() + N, A.end()));
  cout << maxi << endl;
}
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-05-03 17:29:42+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc165/tasks/abc165_c">C - Many Requirements</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc165/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">2410 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">21 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3688 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘long long int bpm(long long int, long long unsigned int)’:
./Main.cpp:24:30: warning: comparison of integer expressions of different signedness: ‘long long unsigned int’ and ‘long long int’ [-Wsign-compare]
   24 |   for (unsigned int i = 0; i < digit; i++) {
      |                            ~~^~~~~~~
