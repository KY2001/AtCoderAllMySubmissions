/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define SUM(x)              accumulate(ALL(x), 0LL)
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

class AIntegerProduct {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
      string temp;
      cin >> temp;
      rep(j, temp.size()) {
        if (temp[j] == '.') {
          temp = temp.substr(0, j) + temp.substr(j + 1, temp.size() - j);
          temp += string(9 - (temp.size() - j), '0');
          break;
        } else if (j == (int)temp.size() - 1) {
          temp += string(9, '0');
          break;
        }
      }
      while (temp[0] == '0' and temp.size()) {
        temp = temp.substr(1, temp.size() - 1);
      }
      A[i] = stoll(temp);
    }
    vector<vector<int>> dp(100, vector<int>(100));
    FOR(i, A) {
      int temp = i;
      int two = 0, five = 0;
      while (temp % 2 == 0) {
        two++;
        temp /= 2;
      }
      while (temp % 5 == 0) {
        five++;
        temp /= 5;
      }
      dp[two][five]++;
    }
    rep(i, 99) {
      rep(j, 99) {
        dp[98 - i][98 - j] += dp[99 - i][99 - j] + (-dp[99 - i][99 - j] + dp[98 - i][99 - j]) + (-dp[99 - i][99 - j] + dp[99 - i][98 - j]);
      }
    }
    int ans = 0;
    FOR(i, A) {
      int temp = i;
      int two = 0, five = 0;
      while (temp % 2 == 0) {
        two++;
        temp /= 2;
      }
      while (temp % 5 == 0) {
        five++;
        temp /= 5;
      }
      ans += dp[max(18 - two, 0LL)][max(0LL, 18 - five)];
      if (two >= 9 and five >= 9) ans--;
    }
    cout << ans / 2 << endl;
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  AIntegerProduct solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
