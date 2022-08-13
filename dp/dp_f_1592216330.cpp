#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sum(x) accumulate(ALL(x), 0LL)
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

struct LCS {
private:
  vector<vector<int>> dp;
  string one, two;
  int n1, n2;

public:
  LCS(string &temp1, string &temp2): n1(temp1.size()), n2(temp2.size()) {
    one = temp1;
    two = temp2;
    dp.assign(n1 + 1, vector<int>(n2 + 1, 0));
  }
  int lcs() {
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        if (one[i] == two[j]) {
          dp[i + 1][j + 1] = max({dp[i][j] + 1, dp[i + 1][j], dp[i][j + 1]});
        } else {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
    return dp[n1][n2];
  }
  string restoration() { // do after lcs
    string ret{};
    int i = n1, j = n2;
    while (i != 0 and j != 0) {
      if (dp[i][j] == dp[i - 1][j]) {
        i--;
      } else if (dp[i][j] == dp[i][j - 1]) {
        j--;
      } else {
        i--;
        j--;
        ret += one[i];
      }
    }
    reverse(ALL(ret));
    return ret;
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  LCS lcs(s, t);
  lcs.lcs();
  cout << lcs.restoration() << endl;
}