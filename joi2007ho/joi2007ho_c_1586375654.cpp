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
    check[pow((double)x[i], 0.3) * pow((double)y[i], 0.4)] = 1;
  }
  double ans = 0;
  int x1, y1, x2, y2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {

        x1 = x[i];
        y1 = y[i];
        x2 = x[j];
        y2 = y[j];
        if (0 <= y1 - y2 + x1 && y1 - y2 + x1 <= 5000 && 0 <= x2 - x1 + y1 &&
            x2 - x1 + y1 <= 5000) {
          if (check[pow((double)y1 - y2 + x1, 0.3) *
                    pow((double)x2 - x1 + y1, 0.4)] == 1) {
            int temp_x1 = x1;
            int temp_y1 = y1;
            x1 = temp_y1 - y2 + temp_x1;
            y1 = x2 - temp_x1 + temp_y1;
            x2 = temp_x1;
            y2 = temp_y1;
            if (0 <= y1 - y2 + x1 && y1 - y2 + x1 <= 5000 &&
                0 <= x2 - x1 + y1 && x2 - x1 + y1 <= 5000) {
              if (check[pow((double)y1 - y2 + x1, 0.3) *
                        pow((double)x2 - x1 + y1, 0.4)] == 1) {
                ans = max((double)ans, pow(double(x1 - x2), 2.0) +
                                           pow(double(y1 - y2), 2.0));
              }
            }
          }
        }
        x1 = x[i];
        y1 = y[i];
        x2 = x[j];
        y2 = y[j];
        if (0 <= x1 - y1 + y2 && x1 - y1 + y2 <= 5000 && 0 <= y1 - x2 + x1 &&
            y1 - x2 + x1 <= 5000) {
          if (check[pow((double)x1 - y1 + y2, 0.3) *
                    pow((double)y1 - x2 + x1, 0.4)] == 1) {
            int temp_x1 = x1;
            int temp_y1 = y1;
            x1 = -temp_y1 + y2 + temp_x1;
            y1 = -x2 + temp_x1 + temp_y1;
            x2 = temp_x1;
            y2 = temp_y1;
            if (0 <= x1 - y1 + y2 && x1 - y1 + y2 <= 5000 &&
                0 <= y1 - x2 + x1 && y1 - x2 + x1 <= 5000) {
              if (check[pow((double)x1 - y1 + y2, 0.3) *
                        pow((double)y1 - x2 + x1, 0.4)] == 1) {
                ans = max((double)ans, pow(double(x1 - x2), 2.0) +
                                           pow(double(y1 - y2), 2.0));
              }
            }
          }
        }
      }
    }
  }
  cout << (int)ans << endl;
}