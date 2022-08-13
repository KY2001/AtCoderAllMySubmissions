#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)             // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b) for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SUM(x) accumulate(ALL(x), 0LL)
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
int n = 100;
int X = 0, Y = 0; //now
int score = 0;
vector<int> x;
vector<int> y;
vector<vector<bool>> already;
string ans{};
string temp_ans{};

inline int cost() {
  int ret = ans.size();
  FOR(i, ans)
  if (i == 'I' or i == 'O') ret--;
  return 4000 - ret;
}

inline int cost_temp() {
  int ret = temp_ans.size();
  FOR(i, temp_ans)
  if (i == 'I' or i == 'O') ret--;
  return 4000 - ret;
}

inline void take(int i) {
  if (x[i] >= X) {
    ans += string(x[i] - X, 'D');
  } else {
    ans += string(X - x[i], 'U');
  }
  if (y[i] >= Y) {
    ans += string(y[i] - Y, 'R');
  } else {
    ans += string(Y - y[i], 'L');
  }
  ans += 'I';
  X = x[i], Y = y[i];
}

inline void take_temp(int i) {
  if (x[i] >= X) {
    temp_ans += string(x[i] - X, 'D');
  } else {
    temp_ans += string(X - x[i], 'U');
  }
  if (y[i] >= Y) {
    temp_ans += string(y[i] - Y, 'R');
  } else {
    temp_ans += string(Y - y[i], 'L');
  }
  temp_ans += 'I';
  X = x[i], Y = y[i];
}

inline void put(int xx, int yy) {
  if (xx >= X) {
    ans += string(xx - X, 'D');
  } else {
    ans += string(X - xx, 'U');
  }
  if (yy >= Y) {
    ans += string(yy - Y, 'R');
  } else {
    ans += string(Y - yy, 'L');
  }
  ans += 'O';
  X = xx, Y = yy;
}

inline void put_temp(int xx, int yy) {
  if (xx >= X) {
    temp_ans += string(xx - X, 'D');
  } else {
    temp_ans += string(X - xx, 'U');
  }
  if (yy >= Y) {
    temp_ans += string(yy - Y, 'R');
  } else {
    temp_ans += string(Y - yy, 'L');
  }
  temp_ans += 'O';
  X = xx, Y = yy;
}
bool in_x(int i) {
  return (X <= x[i + 1] and x[i + 1] <= x[i]) or (x[i] <= x[i + 1] and x[i + 1] <= X);
}

bool in_y(int i) {
  return (Y <= y[i + 1] and y[i + 1] <= y[i]) or (y[i] <= y[i + 1] and y[i + 1] <= Y);
}

pair<int, int> search_near(int i) {
  rep2(j, 0, 10) {
    rep2(k, 0, 10) {
      if (0 <= x[i] + j and x[i] + j <= 19 and 0 <= y[i] + k and y[i] + k <= 19) {
        if (!already[x[i] + j][y[i] + k]) {
          return {x[i] + j, y[i] + k};
        }
      }
      if (0 <= x[i] - j and x[i] - j <= 19 and 0 <= y[i] + k and y[i] + k <= 19) {
        if (!already[x[i] - j][y[i] + k]) {
          return {x[i] - j, y[i] + k};
        }
      }
      if (0 <= x[i] + j and x[i] + j <= 19 and 0 <= y[i] - k and y[i] - k <= 19) {
        if (!already[x[i] + j][y[i] - k]) {
          return {x[i] + j, y[i] - k};
        }
      }
      if (0 <= x[i] - j and x[i] - j <= 19 and 0 <= y[i] - k and y[i] - k <= 19) {
        if (!already[x[i] - j][y[i] - k]) {
          return {x[i] - j, y[i] - k};
        }
      }
    }
  }
  return pair<int, int>();
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  double start = clock();
  std::mt19937 mt{std::random_device{}()};
  std::uniform_int_distribution<int> dist_i(0, 99);
  std::uniform_int_distribution<int> dist_xy(0, 19);
  x.assign(n, 0);
  y.assign(n, 0);
  rep(i, n) cin >> x[i] >> y[i];
  already.assign(20, vector<bool>(20, false));
  rep(i, n) already[x[i]][y[i]] = true;
  rep(i, n - 1) {
    if (in_x(i) and in_y(i)) {
      take(i + 1);
      pair<int, int> place = search_near(i);
      put(place.first, place.second);
      already[x[i + 1]][y[i + 1]] = false;
      x[i + 1] = place.first, y[i + 1] = place.second;
      already[x[i + 1]][y[i + 1]] = true;
    }
    take(i);
    already[x[i]][y[i]] = false;
  }
  take(n - 1);
  score = cost();
  cout << ans << endl;
  int num            = 1;
  vector<int> x_copy = x;
  vector<int> y_copy = y;
  int neo            = start;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-07 16:54:53+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/future-contest-2021-qual/tasks/future_contest_2021_qual_a">A - カードの回収</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/future-contest-2021-qual/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">137571</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4923 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">7 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">3644 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘int main()’:
./Main.cpp:174:7: warning: unused variable ‘num’ [-Wunused-variable]
  174 |   int num            = 1;
      |       ^~~
./Main.cpp:177:7: warning: unused variable ‘neo’ [-Wunused-variable]
  177 |   int neo            = start;
      |       ^~~
