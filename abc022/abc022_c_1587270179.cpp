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
void dfs(int now, int cost, vector<vector<pair<int, int>>> &roads, vector<int> &came) {
  int memo;
  for (auto &i : roads[now]) {
    if (now == 0) {
      for (auto &j : roads[i.first])
        if (j.first == 0) {
          memo     = j.second;
          j.second = INF;
        }
    }

    if (came[i.first] > cost + i.second) {
      came[i.first] = cost + i.second;
      if (i.first != 0) {
        dfs(i.first, cost + i.second, roads, came);
      }
    }
    if (now == 0) {
      for (auto &j : roads[i.first])
        if (j.first == 0) {
          j.second = memo;
        }
    }
  }
}

signed main() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> roads(N);
  rep(i, M) {
    int u, v, l;
    cin >> u >> v >> l;
    roads[u - 1].emplace_back(v - 1, l);
    roads[v - 1].emplace_back(u - 1, l);
  }
  vector<int> came(N, INF);
  dfs(0, 0, roads, came);
  ans = came[0];
  if (ans >= INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}