#include <bits/stdc++.h>
#define int long long
#define stoi                stoll
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)         // [0, b)
#define rep2(i, a, b)       for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b)       for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define SUM(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 998244353;
const int MOD2   = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}
template <class T>
struct BIT {
private:
  vector<T> data;
  int n;
  int s = 1;

public:
  BIT(int n) : n(n) {
    data.assign(n, 0);
    while (s * 2 <= n) { s *= 2; };
  }
  T sum(int R) { // return sum of [0, R);
    int ret = 0;
    for (--R; R >= 0; R = (R & (R + 1)) - 1) ret += data[R];
    return ret;
  }
  T sum(int L, int R) { return sum(R) - sum(L); } //return sum of [L, R);
  void add(int ind, T val) {
    for (; ind < n; ind |= ind + 1) data[ind] += val;
  }
  T at(int ind) { return sum(ind, ind + 1); }
  T operator[](const int ind) { return at(ind); }
  int LOWER_BOUND_(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = s; k > 0; k /= 2)
      if (x + k - 1 <= n - 1 && data[x + k - 1] < w) {
        w -= data[x + k - 1];
        x += k;
      }
    return x;
  }
};

class CRobots {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> cum_sum(N + 2, 0);
    vector<bool> ok(N, false);
    map<int, int> where;
    map<int, int> where2;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) where[A[i]] = B[i];
    BIT<int> bit(N + 10);
    int ans = INF;
    rep(i, N) {
      where[A[i]]++;
      where[A[i] - B[i]]++;
    }
    rep(i, N) {
      if (A[i] > B[i]) {
        int ind = where.lower_bound(A[i] - B[i])->first;
        cum_sum[ind]++;
        cum_sum[i + 2]--;
      }
    }
    where[INF]++;
    where2[INF]++;
    rep(i, N + 1) cum_sum[i + 1] += cum_sum[i];
    rep(i, N) if (cum_sum[i + 1] > 0) ok[i] = true;
    rep(i, N) {
      if (ok[i]) {
        where2[A[i]]++;
        where2[A[i] - B[i]]++;
      }
    }
    rep(i, N - 1) {
      if (not ok[i]) {
        bit.add(where2.lower_bound(A[i])->first - A[i], i);
      }
    }
    rep(i, N) {
      if (A[i] <= B[i]) {
        ans = min(ans, B[i] - A[i] + 1 + bit.sum(i + 1, N + 2));
      } else {
        ans = min(ans, A[i] - A[0] - B[i] + bit.sum(i + 1, N + 2));
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
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-15 00:16:18+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/agc049/tasks/agc049_c">C - Robots</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/agc049/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
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
					<td class="text-center">3630 Byte</td>
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
