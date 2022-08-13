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
  int N, a, b, M;
  cin >> N >> a >> b >> M;
  vector<vector<int>> roads(N, vector<int>(N, 0));
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    roads[x - 1][y - 1] = 1;
    roads[y - 1][x - 1] = 1;
  }
  vector<pair<int, int>> shortest_path(N, pair<int, int>{INF, 0});
  shortest_path[a - 1] = {0, 1};
  deque<int> pos       = {a - 1};
  while (!pos.empty()) {
    rep(i, N) {
      if (roads[pos[0]][i]) {
        if (shortest_path[i].first > shortest_path[pos[0]].first + 1) {
          shortest_path[i] = shortest_path[pos[0]];
          shortest_path[i].first += 1;
          pos.emplace_back(i);
        } else if (shortest_path[i].first == shortest_path[pos[0]].first + 1) {
          shortest_path[i].second += shortest_path[pos[0]].second;
          shortest_path[i].second %= MOD;
        }
      }
    }
    pos.pop_front();
  }
  cout << shortest_path[b - 1].second << endl;
}
