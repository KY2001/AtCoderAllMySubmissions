#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;

signed main() {
  int N, ans = 1e9;
  cin >> N;
  for (int i = 1; i <= (int)sqrt(N); i++) {
    if (N % i == 0) {
      ans = min(ans, (int)max(to_string(i).size(), to_string(N / i).size()));
    }
  }
  cout << ans << endl;
}