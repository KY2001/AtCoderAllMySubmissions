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

template <class T = int>
int in() {
  T x;
  cin >> x;
  return x;
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

typedef unsigned int ull;
const ull B_ = 100000007;
bool contain(string a_, string b_) {
  int al = a_.length(), bl = b_.length();
  if (al > bl) return false;
  ull t = 1;
  for (int i = 0; i < al; i++) t *= B_;
  ull ah = 0, bh = 0;
  for (int i = 0; i < al; i++) ah = ah * B_ + a_[i];
  for (int i = 0; i < al; i++) bh = bh * B_ + b_[i];
  for (int i = 0; i + al <= bl; i++) {
    if (ah == bh) return true;
    if (i + al < bl) bh = bh * B_ + b_[i + al] - b_[i] * t;
  }
  return false;
}

signed main() {
  int N;
  string S;
  cin >> N >> S;
  int len = 0;
  string tempL, tempR;
  rep(i, N - 1) {
    tempL = tempR = "";
    rep(j, i + 1) {
      tempL += S[j];
    }
    rep(j, N - (i + 1)) {
      tempR += S[i + 1 + j];
    }
    if (contain(tempR, tempL)) {
      len = max(len, (int)tempR.size());
    }
  }
  cout << len << endl;
}