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

int edges[8][8]{};
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    edges[a - 1][b - 1] = 1;
    edges[b - 1][a - 1] = 1;
  }
  vector<int> list;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    list.push_back(i);
  }
  do {
    list.insert(list.begin(), 0);
    for (int i = 0; i < N - 1; i++) {
      if (edges[list[i]][list[i + 1]] == 0) {
        break;
      } else if (i == N - 2) {
        ans += 1;
      }
    }
    list.erase(list.begin());
  } while (next_permutation(list.begin(), list.end()));
  cout << ans << endl;
}
