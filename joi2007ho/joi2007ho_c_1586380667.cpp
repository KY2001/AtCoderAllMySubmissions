#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"
#define rand 100007
using namespace std; // std::を省略して書くことができる

int main() {
  unordered_map<double, int> check{};
  int n;
  cin >> n;
  double x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += rand;
    y[i] += rand;
    check[pow(x[i], 0.27) * pow(y[i], 0.14)] = 1;
  }
  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      if (check.count(pow((x[j] + y[i] - y[j]), 0.27) *
                      pow(y[j] + x[j] - x[i], 0.14))) {
        if (check.count(pow((x[i] + y[i] - y[j]), 0.27) *
                        pow(y[i] + x[j] - x[i], 0.14))) {
          ans = max(ans, pow((x[i] - x[j]), 2.0) + pow((y[i] - y[j]), 2.0));
        }
      }
    }
  }
  cout << (int)ans << endl;
}