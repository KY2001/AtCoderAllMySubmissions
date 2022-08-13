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
int ans;
void dfs(int now, int cost, vector<vector<int>> &roads, vector<int> &came) {
  int memo;
  rep(i, roads.size()) {
    if (now == 0) {
      memo          = roads[i][now];
      roads[i][now] = 0;
    }
    if (roads[now][i]) {
      if (came[i] > cost + roads[now][i]) {
        came[i] = cost + roads[now][i];
        if (i != 0) {
          dfs(i, cost + roads[now][i], roads, came);
        }
      }
    }
    if (now == 0) {
      roads[i][now] = memo;
    }
  }
}

signed main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> roads(N, vector<int>(N, 0));
  rep(i, M) {
    int u, v, l;
    cin >> u >> v >> l;
    roads[u - 1][v - 1] = l;
    roads[v - 1][u - 1] = l;
  }
  vector<int> came(N, INF);
  dfs(0, 0, roads, came);
  ans = came[0];
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}