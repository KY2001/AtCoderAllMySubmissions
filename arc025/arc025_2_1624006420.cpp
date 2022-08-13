#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> w_cum(H + 1, vector<int>(W + 1));
  vector<vector<int>> b_cum(H + 1, vector<int>(W + 1));
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      if ((i + j) % 2) {
        cin >> w_cum[i + 1][j + 1];
      } else {
        cin >> b_cum[i + 1][j + 1];
      }
  for (int i = 0; i < H; i++)
    for (int j = 1; j < W + 1; j++) {
      w_cum[i + 1][j] += w_cum[i][j];
      b_cum[i + 1][j] += b_cum[i][j];
    }
  for (int i = 1; i < H + 1; i++)
    for (int j = 0; j < W; j++) {
      w_cum[i][j + 1] += w_cum[i][j];
      b_cum[i][j + 1] += b_cum[i][j];
    }
  int ans = 0;
  for (int x1 = 0; x1 < H; x1++)
    for (int y1 = 0; y1 < W; y1++)
      for (int x2 = 0; x2 < H; x2++)
        for (int y2 = 0; y2 < W; y2++) {
          if (not(x2 >= x1 and y2 >= y1)) continue;
          int num_b = b_cum[x2 + 1][y2 + 1] - b_cum[x2 + 1][y1] - b_cum[x1][y2 + 1] + b_cum[x1][y1];
          int num_w = w_cum[x2 + 1][y2 + 1] - w_cum[x2 + 1][y1] - w_cum[x1][y2 + 1] + w_cum[x1][y1];
          if (num_b == num_w and (x2 - x1 + 1) * (y2 - y1 + 1) > ans) {
            ans = (x2 - x1 + 1) * (y2 - y1 + 1);
          }
        }
  cout << ans << endl;
}
