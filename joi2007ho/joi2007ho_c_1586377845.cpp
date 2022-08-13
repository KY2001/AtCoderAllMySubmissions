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
  double x[n], y[n];
  unordered_map<double, int> check;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    check[sqrt(x[i]) * sqrt(y[i])] = 1;
  }
  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (check[sqrt(x[j] + y[i] - y[j]) * sqrt(y[j] + x[j] - x[i])]) {
        if (check[sqrt(x[i] + y[i] - y[j]) * sqrt(y[i] + x[j] - x[i])]) {
          ans = max(ans, pow((double)(x[i] - x[j]), 2.0) +
                             pow((double)(y[i] - y[j]), 2.0));
        }
      }
      if (check[sqrt(x[j] - y[i] + y[j]) * sqrt(y[j] - x[j] + x[i])]) {
        if (check[sqrt(x[i] - y[i] + y[j]) * sqrt(y[i] - x[j] + x[i])]) {
          ans = max(ans, pow((double)(x[i] - x[j]), 2.0) +
                             pow((double)(y[i] - y[j]), 2.0));
        }
      }
    }
  }
  cout << (int)ans << endl;
}