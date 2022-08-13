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
  const int num = 100000;
  cin >> N >> K;
  vector<int> nums(num, 0);
  rep(i, N) {
    int temp_a, temp_b;
    cin >> temp_a >> temp_b;
    nums[temp_a - 1] += temp_b;
  }
  int now = 0;
  rep(i, num) {
    if (now + nums[i] >= K) {
      cout << i + 1 << endl;
      return 0;
    }
    now += nums[i];
  }
}
