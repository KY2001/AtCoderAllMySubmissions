#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> a(N + 1);
  for (int i = 0; i < N; i++) cin >> a[i + 1];
  for (int i = 0; i < N; i++) a[i + 1] += a[i];
  long long ans = 0;
  for (int i = 0; i < N - K + 1; i++) ans += a[i + K] - a[i];
  cout << ans << endl;
}