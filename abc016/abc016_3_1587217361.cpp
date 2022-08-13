#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}

signed main() {
  int N = in();
  int M = in();
  vector<vector<int>> LIST(N, vector<int>(N, 0));
  rep(i, M) {
    int A, B;
    cin >> A >> B;
    LIST[A - 1][B - 1] = 1;
    LIST[B - 1][A - 1] = 1;
  }
  rep(i, N) {
    int num = 0;
    vector<int> friends(N, 0);
    friends[i] = 1;
    rep(j, N) {
      if (LIST[i][j]) {
        rep(k, N) {
          if (LIST[j][k] && !friends[k] && !LIST[i][k]) {
            friends[k] = 1;
            num += 1;
          }
        }
      }
    }
    cout << num << endl;
  }
}
