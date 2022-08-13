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
  string S;
  cin >> S;
  S += "aaaaaaa";
  int now = 0;
  while (now < S.size() - 9) {
    string temp = "";
    rep(i, 7) {
      temp += S[now + i];
      if (i == 4) {
        if (temp == "dream" && (S[now + 7] == 'a' || S[now + 7] == 'e')) {
          now += 5;
          break;
        } else if (temp == "erase" && S[now + 5] != 'r') {
          now += 5;
          break;
        }
      } else if (i == 5) {
        if (temp == "eraser") {
          now += 6;
          break;
        }
      } else if (i == 6) {
        if (temp == "dreamer") {
          now += 7;
          break;
        } else {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
}
