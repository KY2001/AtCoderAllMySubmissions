#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;

signed main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];
  priority_queue<vector<int>, vector<vector<int>>, greater<>> pos;
  int ans     = 0;
  int sum_gap = 0;
  int sum_Y   = 0;
  rep(i, N) {
    pos.push({X[i] - Y[i], X[i]});
    sum_gap += X[i] - Y[i];
    sum_Y += Y[i];
    ans = max(ans, sum_gap + sum_Y);
    if (pos.size() == M) {
      sum_gap -= pos.top()[0];
      pos.pop();
    }
  }
  cout << ans << endl;
}