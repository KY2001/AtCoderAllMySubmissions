#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define sqr(x) (x) * (x)
#define cube(x) (z) * (z) * (x)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
}

signed main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  string S__  = "";
  S__ += S;
  string S_ = "";
  S_ += S;
  sort(ALL(S_));
  string ans = "";
  int p      = 0;
  rep(i, N) {
    int num = 0;
    rep(j, N) {
      if (S[j] != S__[j]) {
        num += 1;
      }
    }
    if (num >= K) {
      for (int j = i; j < N; j++) {
        string temp{S[j]};
        ans += temp;
      }
      break;
    }
    if (S[i] != S_[i]) {
      num += (p ? 1 : 2);
      p = 1;
      for (int j = N - 1; j >= 0; j--) {
        if (S[j] == S_[i]) {
          S[j] = S[i];
          S[i] = S_[i];
          break;
        }
      }
    } else {
      p = 0;
    }
    string temp{S_[i]};
    ans += temp;
  }
  cout << ans << endl;
}
