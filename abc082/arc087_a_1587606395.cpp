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
unordered_map<int, int> element_num; //change type if you need
template <class T>
void counter(T container) {
  for (int i = 0; i < container.size(); i++) {
    element_num[container[i]] += 1;
  }
}

class CGoodSequence {
public:
  int solve(std::istream &cin, std::ostream &cout) {
    element_num = {};
    int N;
    cin >> N;
    vector<int> a(N);
    int ans = 0;
    rep(i, N) {
      cin >> a[i];
      if (a[i] > 100000) {
        ans += 1;
      }
    }
    counter(a);
    rep(i, 100001) {
      if (element_num[i]) {
        if (element_num[i] >= i) {
          ans += element_num[i] - i;
        } else {
          ans += element_num[i];
        }
      }
    }
    cout << ans << endl;
  }
};
