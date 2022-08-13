#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  int zero = 1;
  int one = 0;
  int two = 0;
  for (int k = 0; k < n; k++){
    two += one;
    one = zero;
    zero = two;
  }
  cout << zero + one + two << endl;
}
