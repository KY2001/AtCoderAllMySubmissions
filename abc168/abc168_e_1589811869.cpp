#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define inv(i, a, b)        for (int i = (int)(a); i >= (int)(b); i--)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define Endl                endl

using namespace std;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int x, unsigned int y) {                                                    //return x^y in order(log(y))
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}
template <class T>
void cumulative_sum(T &container) {
  for (int i = 0; i < container.size() - 1; i++) container[i + 1] += container[i];
}
template <class T>
struct reduction { //reduction: 約分, O(log n)
private:
  int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
  int lcm(int a, int b) { return a * b / gcd(a, b); }

public:
  T first;
  T second;
  reduction(int a, int b) : first(a), second(b) { //符号は変わらない
    if (a == 0 or b == 0) {
      first = second = 0;
    } else {
      int GCD = gcd(abs(first), abs(second));
      first /= GCD;
      second /= GCD;
    }
  }
};

class EBullet {
public:
  static void solve(std::istream &cin, std::ostream &cout) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    map<pair<int, int>, int> counter;
    rep(i, N) {
      int A, B;
      cin >> A >> B;
      reduction<int> rd(A, B);
      if (A * B < 0)
        counter[{-abs(rd.first), -abs(rd.second)}]++;
      else
        counter[{rd.first, rd.second}]++;
    }
    int ans = 1;
    for (auto &i : counter) {
      if (i.first.first == 0) {
        ans *= i.second + 1;
      } else {
        if (counter.count({-i.first.second, -i.first.first})) {
          ans *= (bpm(2, i.second) + bpm(2, counter[{-i.first.second, -i.first.first}]) - 1);
          counter[{-i.first.second, -i.first.first}] = 0;
          i.second = 0;
        } else {
          ans *= bpm(2, i.second);
        }
      }
      ans %= MOD;
    }
    cout << mod(ans - 1, MOD) << endl;
  }
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-05-18 23:24:29+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc168/tasks/abc168_e">E - ∙ (Bullet)</a></td>
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
					<td class="text-center">0</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">2879 Byte</td>
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
