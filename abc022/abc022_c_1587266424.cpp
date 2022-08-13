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

int dfs(int now, int cost, vector<vector<int>> &roads) {
  int ans = INF;
  rep(i, roads.size()) {
    if (roads[now][i]) {
      if (i == 0) {
        ans = min(ans, cost + roads[now][0]);
      } else {
        int temp      = roads[now][i];
        roads[now][i] = 0;
        roads[i][now] = 0;
        ans           = min(ans, dfs(i, cost + temp, roads));
        roads[now][i] = temp;
        roads[i][now] = temp;
      }
    }
  }
  return ans;
}

signed main() {
  int N, M;
  cin >> N >> M;
  int ans = INF;
  vector<vector<int>> roads(N, vector<int>(N, 0));
  rep(i, M) {
    int u, v, l;
    cin >> u >> v >> l;
    roads[u - 1][v - 1] = l;
    roads[v - 1][u - 1] = l;
  }
  ans = dfs(0, 0, roads);
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
