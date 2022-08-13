#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;

bool is_prime(int n) {
  if ((n % 2 == 0 and n != 2) or n == 1) return false;
  for (int k = 3; k < (int)sqrt((double(n))) + 2; k += 2)
    if (n % k == 0) return false;
  return true;
}

signed main() {
  int X;
  cin >> X;
  for (int i = X; i < 1000000; i++) {
    if (is_prime(i)) {
      cout << i << endl;
      break;
    }
  }
}