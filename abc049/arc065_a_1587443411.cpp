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

int judge(int now, string temp, string S) {
  rep(i, temp.size()) {
    if (temp[i] != S[now + i]) {
      return 0;
    }
  }
  now += temp.size();
  if (now == S.size()) {
    return 1;
  } else {
    return max(judge(now, "dream", S), max(judge(now, "dreamer", S), max(judge(now, "erase", S), judge(now, "eraser", S))));
  }
}

signed main() {
  string S;
  cin >> S;
  int now = 0;
  if (max(judge(now, "dream", S), max(judge(now, "dreamer", S), max(judge(now, "erase", S), judge(now, "eraser", S))))) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
