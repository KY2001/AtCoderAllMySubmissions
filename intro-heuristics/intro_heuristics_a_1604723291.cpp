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
int D;
vector<int> t;
vector<int> c;
vector<vector<int>> s;

int calc_score() {
  vector<int> last(26, 0);
  int ret = 0;
  rep(i, D) {
    ret += s[i][t[i]];
    last[t[i]] = i + 1;
    rep(j, 26) {
      ret -= c[j] * (i + 1 - last[j]);
    }
  }
  return ret;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  double start = clock();
  cin >> D;
  int ans = 0;
  s.assign(D, vector<int>(26));
  t.assign(D, 0);
  c.assign(26, 0);
  rep(i, 26) cin >> c[i];
  rep(i, D) rep(j, 26) cin >> s[i][j];
  vector<int> last(26, 0);
  rep(i, D) {
    vector<int> temp_ans(26);
    rep(j, 26) {
      temp_ans[j] += s[i][j];
      int memo = last[j];
      last[j]  = i + 1;
      rep(k, 26) {
        temp_ans[j] -= c[k] * (i + 1 - last[k]);
      }
      last[j] = memo;
    }
    int maxi = MAX(temp_ans);
    ans += maxi;
    rep(j, 26) {
      if (temp_ans[j] == maxi) {
        last[j] = i + 1;
        t[i]    = j;
        break;
      }
    }
  }
  mt19937 mt{std::random_device{}()};
  uniform_int_distribution<int> dist(0, D - 1);
  uniform_int_distribution<int> dist2(0, 25);
  double neo = start;
  int num    = min(1, D);
  while ((clock() - start) / CLOCKS_PER_SEC < 1.98) {
    if ((clock() - neo) / CLOCKS_PER_SEC > 0.01) {
      num++;
      neo = clock();
    }
    vector<int> day(num);
    vector<int> which(num);
    vector<int> memo(num);
    rep(i, num) {
      day[i]   = dist(mt);
      which[i] = dist2(mt);
    }
    rep(i, num) {
      memo[i]   = t[day[i]];
      t[day[i]] = which[i];
    }
    int score = calc_score();
    if (score > ans) {
      ans = score;
      num = min(1, D);
      neo = clock();
    } else {
      rep3(i, num - 1, 0) {
        swap(t[day[i]], memo[i]);
      }
    }
  }
  FOR(i, t)
  cout << i + 1 << endl;
}