#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len = (b); i < i##_len; i++)

template<class T> using V  = vector<T>;
template<class T> using VV = vector<vector<T>>;
template<class T> struct two_dim_cum_sum {
  int H, W;
  vector<vector<T>> cum_sum;
  two_dim_cum_sum(vector<vector<T>> &data): H(data.size()), W(data[0].size()) { // dataはH+1, W+1の大きさ
    cum_sum = data;
    for (int i = 1; i < H; i++)
      for (int j = 1; j < W - 1; j++) cum_sum[i][j + 1] += cum_sum[i][j];
    for (int i = 1; i < H - 1; i++)
      for (int j = 1; j < W; j++) cum_sum[i + 1][j] += cum_sum[i][j];
  }
  T get(int x1, int y1, int x2, int y2) { return cum_sum[x2][y2] - cum_sum[x2][y1 - 1] - cum_sum[x1 - 1][y2] + cum_sum[x1 - 1][y1 - 1]; } //引数は全て+1された状態で, (x2, y2)を含む
};

signed main() {
  int H, W;
  cin >> H >> W;
  VV<int> C1(H + 1, V<int>(W + 1));
  VV<int> C2(H + 1, V<int>(W + 1));
  rep(i, H) rep(j, W) {
    if ((i + j) % 2) {
      cin >> C1[i + 1][j + 1];
    } else {
      cin >> C2[i + 1][j + 1];
    }
  }
  int ans = 0;
  two_dim_cum_sum<int> White(C1);
  two_dim_cum_sum<int> Black(C2);
  rep2(y1, 1, H + 1) rep2(x1, 1, W + 1) rep2(y2, 1, H + 1) rep2(x2, 1, W + 1) {
    if (not(y2 >= y1 and x2 >= x1)) continue;
    if (White.get(y1, x1, y2, x2) == Black.get(y1, x1, y2, x2)) {
      ans = max(ans, (y2 - y1 + 1) * (x2 - x1 + 1));
    }
  }
  cout << ans << endl;
}