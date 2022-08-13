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

int main() {
  string O, E, ans;
  cin >> O >> E;
  int o_ = 0;
  int e_ = 0;
  ans = "";
  for (int i = 0; i < INF; i++) {
    if (o_ != 1) {
      ans += O[i];
      if (i == O.size() - 1) {
        o_ = 1;
      }
    }
    if (e_ != 1) {
      ans += E[i];
      if (i == E.size() - 1) {
        e_ = 1;
      }
    }
    if (o_ == 1 && e_ == 1) {
      break;
    }
  }
  cout << ans << endl;
}