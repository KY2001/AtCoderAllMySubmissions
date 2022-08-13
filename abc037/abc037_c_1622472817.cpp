#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> a(N);
  vector<long long> b(N + 1);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++) b[i + 1] = b[i] + a[i];
  long long ans = 0;
  for (int i = 0; i < N - K + 1; i++) ans += b[i + K] - b[i];
  cout << ans << endl;
}