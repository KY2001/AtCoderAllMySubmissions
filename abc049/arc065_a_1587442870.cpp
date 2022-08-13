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

int judge(string temp, string S) {
  rep(i, temp.size()) {
    if (temp[i] != S[i]) {
      return 0;
    } else if (i == S.size() - 1 && S.size() == temp.size()) {
      return 1;
    }
  }
  return max(judge(temp + "dream", S), max(judge(temp + "dreamer", S), max(judge(temp + "erase", S), judge(temp + "eraser", S))));
}

signed main() {
  string S;
  cin >> S;
  if (judge("", S)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
