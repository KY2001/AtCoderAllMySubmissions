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
  int ans   = 0;
  int sum_X = 0;
  int sum_Y = 0;
  rep(i, N) {
    if (Y[i] >= X[i]) {
      sum_Y += Y[i];
      ans = max(ans, sum_X + sum_Y);
      continue;
    }
    pos.push({X[i], -Y[i]});
    sum_X += X[i];
    ans = max(ans, sum_X + sum_Y);
    if (pos.size() == M) {
      sum_X -= pos.top()[0];
      sum_Y += -pos.top()[1];
      pos.pop();
    }
  }
  cout << ans << endl;
}