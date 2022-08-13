#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SQR(x) (x) * (x)
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);
template <typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}

signed main() {
  int H, W, N;
  cin >> H >> W >> N;
  deque<int> a(N);
  REP(i, N) {
    cin >> a[i];
  }
  vector<vector<int>> ans(H, vector<int>(W));
  int current = 1;
  REP(i, H) {
    if (i % 2) {
      REP(j, W) {
        ans[i][j] = current;
        if (!--a[0]) {
          a.pop_front();
          current++;
        }
      }
    } else {
      for (int j = W - 1; j >= 0; j--) {
        ans[i][j] = current;
        if (!--a[0]) {
          a.pop_front();
          current++;
        }
      }
    }
  }
  REP(i, H) {
    REP(j, W) {
      cout << ans[i][j];
      if (j != W - 1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
}
