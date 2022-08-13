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
  int N, D, K;
  cin >> N >> D >> K;
  vector<pair<int, int>> LR_K(K);
  vector<pair<int, int>> LR(D);
  vector<int> dist(K);
  int L, R;
  rep(i, D) {
    cin >> L >> R;
    LR[i] = {L, R};
  }
  int S, T;
  rep(i, K) {
    cin >> S >> T;
    LR_K[i] = {S, S};
    dist[i] = T;
  }
  vector<int> ans(K, 0);
  rep(i, D) {
    rep(j, K) {
      if (!ans[j]) {
        if (LR[i].first <= LR_K[j].first && LR_K[j].second <= LR[i].second) {
          LR_K[j].first  = LR[i].first;
          LR_K[j].second = LR[i].second;
        } else if (LR_K[j].first <= LR[i].first && LR_K[j].second >= LR[i].first && LR_K[j].second < LR[i].second) {
          LR_K[j].second = LR[i].second;
        } else if (LR_K[j].first >= LR[i].first && LR_K[j].first <= LR[i].second) {
          LR_K[j].first = LR[i].first;
        }
        if (LR_K[j].first <= dist[j] && dist[j] <= LR_K[j].second) {
          ans[j] = i + 1;
        }
      }
    }
  }
  for (auto &i : ans) {
    cout << i << endl;
  }
}
