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
  vector<string> LIST;
  int before = -1;
  rep(i, S.size()) {
    if (S[i] == '+') {
      string temp = "";
      FOR(j, before + 1, i) {
        temp += S[j];
      }
      before = i;
      LIST.emplace_back(temp);
    } else if (i == S.size() - 1) {
      string temp = "";
      FOR(j, before + 1, S.size()) {
        temp += S[j];
      }
      LIST.emplace_back(temp);
    }
  }
  int num = LIST.size();
  for (auto &i : LIST) {
    if (i[0] == '0' || i[i.size() - 1] == '0') {
      num -= 1;
    } else {
      FOR(j, 1, i.size() - 1) {
        if (i[j] == '0' && i[j - 1] == '*' && i[j + 1] == '*') {
          num -= 1;
          break;
        }
      }
    }
  }
  cout << num << endl;
}
