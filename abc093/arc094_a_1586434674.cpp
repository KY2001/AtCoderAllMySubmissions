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
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> ABC = {A, B, C};
  sort(ABC.begin(), ABC.end());
  int ans = (ABC[1] - ABC[0]) / 2;
  ABC[0] += 2 * ans;
  if (ABC[0] == ABC[1]) {
    ans += ABC[2] - ABC[0];
  } else {
    ans += ABC[2] - ABC[1];
    ans += 2;
  }
  cout << ans << endl;
}