#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
using namespace std;

signed main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  deque<int> slide_min;
  int L   = 0;
  int ans = 0;
  for (int R = 0; R < N; R++) {
    while (slide_min.size()) {
      if (A[*rbegin(slide_min)] >= A[R]) {
        slide_min.pop_back();
      } else {
        break;
      }
    }
    slide_min.push_back(R);
    if (R - L + 1 > K) {
      if (slide_min[0] == L) slide_min.pop_front();
      L++;
    }
    ans += A[slide_min[0]];
  }
  cout << ans << endl;
}