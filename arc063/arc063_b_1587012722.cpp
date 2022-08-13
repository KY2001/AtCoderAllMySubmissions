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
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  vector<int> MAX_A(N);
  REP(i, N) {
    MAX_A[i] = A[i];
  }
  for (int i = N - 2; i >= 0; i--) {
    MAX_A[i] = max(MAX_A[i], MAX_A[i + 1]);
  }
  int MAX = 0;
  int num = 0;
  REP(i, N - 1) {
    MAX = max(MAX, MAX_A[i + 1] - A[i]);
  }
  REP(i, N - 1) {
    if (MAX_A[i + 1] - A[i] == MAX) {
      num += 1;
    }
  }
  cout << num << endl;
}
