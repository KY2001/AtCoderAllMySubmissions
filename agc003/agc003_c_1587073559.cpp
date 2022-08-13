#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define SQR(x) (x) * (x)
#define itn int

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);
template <typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val) {
  std::fill((T *)array, (T *)(array + N), val);
}

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> A_(N);
  REP(i, N) {
    cin >> A[i];
    A_[i] = A[i];
  }
  sort(ALL(A_));
  double ans = 0;
  REP(i, N) {
    auto iter = lower_bound(ALL(A_), A[i]);
    int ind   = distance(A_.begin(), iter);
    if ((i - ind) % 2)
      ans += 0.5;
  }
  cout << (int)ans << endl;
}
