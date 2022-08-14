#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int bpm(int x, int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
  }
  return ans;
}

class CMinimization {
public:
  int solve(std::istream &cin, std::ostream &cout) {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
      cin >> A[i];
    }
    int mini = MIN(A);
    int ans  = 0;
    int num  = 0;
    rep(i, N) {
      if (A[i] != mini) {
        num += 1;
      } else {
        if (num >= 1){
          ans += ceil((double)(num) / (double)(K - 1));
          if (num % (K - 1) != 0) {
            num = min(0LL, -((K - 1) - ((num % (K - 1)) + 1)));
          } else {
            num = 0;
          }
        }
      }
    }
    if (A[N - 1] != mini) {
      ans += ceil((double)(num) / (double)(K - 1));
    }
    cout << ans << endl;
  }
};
