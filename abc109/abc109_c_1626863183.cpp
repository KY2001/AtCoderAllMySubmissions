#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;
const int MOD = (1e9 + 7);
const int INF = 1e18;

signed main() {
  int N, X, x, ans;
  cin >> N >> X;
  cin >> x;
  ans = abs(X - x);
  rep(i, N - 1) {
    cin >> x;
    ans = gcd(ans, abs(X - x));
  }
  cout << ans << endl;
}