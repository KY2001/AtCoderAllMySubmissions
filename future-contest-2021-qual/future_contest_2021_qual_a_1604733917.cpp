#pragma GCC optimize("Ofast")
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
  rep(i, n) {
    take(i);
  }
  score              = cost();
  int num            = 1;
  vector<int> x_copy = x;
  vector<int> y_copy = y;
  int neo            = start;
  while (((clock()) - start) / CLOCKS_PER_SEC < 2.8) {
    if ((clock() - neo) / CLOCKS_PER_SEC > 0.1 and num < 10) {
      num++;
      neo = clock();
    }
    X = 0;
    Y = 0;
    x = x_copy, y = y_copy;
    already.assign(20, vector<bool>(20, false));
    rep(i, n) already[x[i]][y[i]] = true;
    temp_ans                      = {};
    vector<bool> when(n, false);
    rep(i, num) when[dist_i(mt)] = true;
    rep(i, n) {
      if (when[i] and i != n - 1) {
        std::uniform_int_distribution<int> dist_ii(i + 1, 99);
        int which                   = dist_ii(mt);
        already[x[which]][y[which]] = false;
        take_temp(which);
        pair<int, int> where;
        while (1) {
          if (!already[where.first][where.second]) break;
          where = {dist_xy(mt), dist_xy(mt)};
        }
        put_temp(where.first, where.second);
        already[x[which]][y[which]] = false;
        x[which] = where.first, y[which] = where.second;
        already[x[which]][y[which]] = true;
      }
      take_temp(i);
      already[x[i]][y[i]] = false;
    }
    int temp = cost_temp();
    if (temp > score) {
      ans   = temp_ans;
      score = temp;
      neo   = clock();
    }
  }
  cout << ans << endl;
}