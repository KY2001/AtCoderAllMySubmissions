#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"

using namespace std; // std::を省略して書くことができる

int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  unordered_map<double, int> check;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    check[pow((double)x[i], 0.3) * y[i]] = 1;
  }
  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int x1 = x[i];
      int x2 = x[j];
      int y1 = y[i];
      int y2 = y[j];
      if (check[pow((double)x2 + y1 - y2, 0.3) * (double)(y2 + x2 - x1)]) {
        if (check[pow((double)x1 + y1 - y2, 0.3) * (double)(y1 + x2 - x1)]) {
          ans = max(ans,
                    pow((double)(x1 - x2), 2.0) + pow((double)(y1 - y2), 2.0));
        }
      }
      if (check[pow((double)x2 - y1 + y2, 0.3) * (double)(y2 - x2 + x1)]) {
        if (check[pow((double)x1 - y1 + y2, 0.3) * (double)(y1 - x2 + x1)]) {
          ans = max(ans,
                    pow((double)(x1 - x2), 2.0) + pow((double)(y1 - y2), 2.0));
        }
      }
    }
  }
  cout << (int)ans << endl;
}