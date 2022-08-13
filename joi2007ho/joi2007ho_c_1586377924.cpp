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
    check[(x[i]) * (y[i])] = 1;
  }
  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (check[(x[j] + y[i] - y[j]) * (y[j] + x[j] - x[i])]) {
        if (check[(x[i] + y[i] - y[j]) * (y[i] + x[j] - x[i])]) {
          ans = max(ans, pow((double)(x[i] - x[j]), 2.0) +
                             pow((double)(y[i] - y[j]), 2.0));
        }
      }
      if (check[(x[j] - y[i] + y[j]) * (y[j] - x[j] + x[i])]) {
        if (check[(x[i] - y[i] + y[j]) * (y[i] - x[j] + x[i])]) {
          ans = max(ans, pow((double)(x[i] - x[j]), 2.0) +
                             pow((double)(y[i] - y[j]), 2.0));
        }
      }
    }
  }
  cout << (int)ans << endl;
}