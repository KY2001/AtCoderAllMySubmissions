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
template<class T>
int Lower_bound(vector<T> A, T key) {
  int ind = LOWER_BOUND(A, key);
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template<class T>
int Lower_bound_reverse(vector<T> A, T key) {
  int ind = UPPER_BOUND(A, key) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template<class T>
int Upper_bound(vector<T> A, T key) {
  int ind = UPPER_BOUND(A, key);
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}
template<class T>
int Upper_bound_reverse(vector<T> A, T key) {
  int ind = UPPER_BOUND(A, key) - 1;
  if (0 <= ind and ind < A.size()) return ind;
  return -1;
}

signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  vector<vector<int>> row(H, vector<int>(0));
  vector<vector<int>> row2(H, vector<int>(0));
  vector<vector<int>> column(W, vector<int>(0));
  vector<vector<int>> column2(W, vector<int>(0));
  vector<vector<int>> grid(H, vector<int>(W, 0));
  rep(i, N) {
    int A, B;
    cin >> A >> B;
    row[A - 1].emplace_back(B - 1);
    column[B - 1].emplace_back(A - 1);
    grid[A - 1][B - 1]++;
  }
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    row2[A - 1].emplace_back(B - 1);
    column2[B - 1].emplace_back(A - 1);
    grid[A - 1][B - 1]--;
  }
  rep(i, H) {
    sort(ALL(row[i]));
    sort(ALL(row2[i]));
  }
  rep(i, W) {
    sort(ALL(column[i]));
    sort(ALL(column2[i]));
  }
  int ans = 0;
  rep(i, H) {
    rep(j, W) {
      if (grid[i][j] == 1) {
        ans++;
      } else if (grid[i][j] == 0) {
        int right  = Lower_bound(row[i], j);
        int right2 = Lower_bound(row2[i], j);
        int left   = Lower_bound_reverse(row[i], j);
        int left2  = Lower_bound_reverse(row2[i], j);
        int down   = Lower_bound(column[j], i);
        int down2  = Lower_bound(column2[j], i);
        int up     = Lower_bound_reverse(column[j], i);
        int up2    = Lower_bound_reverse(column2[j], i);
        if (right >= 0 and right2 >= 0) {
          if (row[i][right] < row2[i][right2]) {
            ans++;
            continue;
          }
        } else if (right >= 0) {
          ans++;
          continue;
        }
        if ((0 <= left and 0 <= left2)) {
          if (row[i][left] > row2[i][left2]) {
            ans++;
            continue;
          }
        } else if ((0 <= left)) {
          ans++;
          continue;
        }
        if (0 <= up and 0 <= up2) {
          if (column[j][up] > column2[j][up2]) {
            ans++;
            continue;
          }
        } else if (0 <= up) {
          ans++;
          continue;
        }
        if (0 <= down and 0 <= down2) {
          if (column[j][down] < column2[j][down2]) {
            ans++;
            continue;
          }
        } else if (0 <= down) {
          ans++;
          continue;
        }
      }
    }
  }
  cout << ans << endl;
}