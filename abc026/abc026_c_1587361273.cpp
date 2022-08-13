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
  vector<vector<int>> sub(N);
  vector<int> salary(N, -1);
  rep(i, N - 1) {
    int temp = in();
    sub[temp - 1].emplace_back(i + 1);
  }
  while (true) {
    rep(i, N) {
      if (salary[i] == -1) {
        if (sub[i].empty()) {
          salary[i] = 1;
        } else {
          vector<int> temp;
          rep(j, sub[i].size()) {
            temp.emplace_back(salary[sub[i][j]]);
            if (salary[sub[i][j]] == -1) {
              break;
            } else if (j == sub[i].size() - 1) {
              salary[i] = 1 + MAX(temp) + MIN(temp);
            }
          }
        }
      }
    }
    rep(i, N) {
      if (salary[i] == -1) {
        break;
      } else if (i == N - 1) {
        goto endloop;
      }
    }
  }
endloop:
  cout << salary[0] << endl;
}
