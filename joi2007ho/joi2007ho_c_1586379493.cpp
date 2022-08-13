#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"

using namespace std; // std::を省略して書くことができる
unordered_map<double, int> check;
double x[3000], y[3000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    check[pow(x[i], 0.2) * pow(y[i], 0.3)] = 1;
  }
  double ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (check.count(pow((x[j] + y[i] - y[j]), 0.2) *
                      pow(y[j] + x[j] - x[i], 0.3))) {
        if (check.count(pow((x[i] + y[i] - y[j]), 0.2) *
                        pow(y[i] + x[j] - x[i], 0.3))) {
          ans = max(ans, pow((double)(x[i] - x[j]), 2.0) +
                             pow((double)(y[i] - y[j]), 2.0));
        }
      }
    }
  }
  cout << (int)ans << endl;
}