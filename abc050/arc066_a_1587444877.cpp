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
unordered_map<int, int> element_num; //change type if you need
template <class T>
void counter(T container) {
  for (int i = 0; i < container.size(); i++) {
    element_num[container[i]] += 1;
  }
}
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
signed main() {
  int N = in();
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
  }
  sort(ALL(A));
  counter(A);
  if (element_num[0] == 1) {
    int num = 0;
    rep(i, 100000) {
      if (element_num[2 * (i + 1)] == 2) {
        num += 1;
      } else if (element_num[2 * (i + 1)] == 0) {
        if (A.size() == 2 * num + 1) {
          cout << bpm(2, num) << endl;
          return 0;
        } else {
          break;
        }
      } else {
        break;
      }
    }
  } else if (element_num[1] == 2) {
    int num = 0;
    FOR(i, 1, 100000) {
      if (element_num[2 * i + 1] == 2) {
        num += 1;
      } else if (element_num[2 * i + 1] == 0) {
        if (A.size() == 2 * num + 2) {
          cout << bpm(2, num + 1) << endl;
          return 0;
        }
      } else {
        break;
      }
    }
  }
  cout << 0 << endl;
}
