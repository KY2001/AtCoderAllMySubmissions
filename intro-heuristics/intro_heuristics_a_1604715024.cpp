#include <bits/stdc++.h>
#define int long long
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

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int D;
  cin >> D;
  vector<int> c(26);
  vector<vector<int>> s(D, vector<int>(26));
  rep(i, 26) cin >> c[i];
  rep(i, D) rep(j, 26) cin >> s[i][j];
  int ans = 0;
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
        cout << j + 1 << endl;
        break;
      }
    }
  }
  cout << ans << endl;
}