#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
using namespace std; // std::を省略して書くことができる

int c[10][10];
int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> c[i][j];
    }
  }
  for (int m = 0; m < 1000; m++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++)
        if (i != j) {
          for (int k = 0; k < 10; k++) {
            if (i != k && j != k) {
              c[i][k] = min(c[i][k], c[i][j] + c[j][k]);
            }
          }
        }
    }
  }
  int ans = 0;
  for (int i = 0; i < H * W; i++) {
    int num;
    cin >> num;
    if (num != -1) {
      ans += c[num][1];
    }
  }
  cout << ans << endl;
}
