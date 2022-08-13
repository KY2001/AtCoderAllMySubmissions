#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;

int gcd1(int A, int B) {
  if (B == 0) {
    return A;
  } else {
    return gcd(B, A % B);
  }
}
int gcd2(int A, int B) { return (B == 0) ? A : gcd(B, A % B); }

int gcd3(int A, int B) {
  while (B) swap(B, A %= B);
  return A;
}
int LCM(int A, int B) { return A * B / gcd1(A, B); }

signed main() {
  int N, X, x, ans;
  cin >> N >> X;
  cin >> x;
  ans = abs(X - x);
  rep(i, N - 1) {
    cin >> x;
    ans = gcd2(ans, abs(X - x));
  }
  cout << ans << endl;
}