#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N, M, A, B, L, R;
  cin >> N >> M >> A >> B;
  vector<int> is_A(N + 1);
  for (int i = 0; i < M; i++) {
    cin >> L >> R;
    for (int j = L; j <= R; j++) is_A[j] = 1;
  }
  if (A >= B) {
    cout << A * N << endl;
  } else {
    int sum = accumulate(begin(is_A), end(is_A), 0LL);
    cout << A * sum + B * (N - sum) << endl;
  }
}