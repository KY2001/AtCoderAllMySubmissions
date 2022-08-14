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
  string piano = "WBWBWWBWBWBW";
  int loc;
  for (unsigned int i = 0; i < 12; i++) {
    FOR(j, i, min(i + 12, S.size())) {
      if (piano[j - i] != S[j]) {
        break;
      } else if (j == min(i + 12, S.size()) - 1) {
        loc = i;
        goto go;
      }
    }
  }
go:
  loc = (12 - loc) % 12;
  if (loc <= 1) {
    cout << "Do" << endl;
  } else if (loc <= 3) {
    cout << "Re" << endl;
  } else if (loc <= 4) {
    cout << "Mi" << endl;
  } else if (loc <= 6) {
    cout << "Fa" << endl;
  } else if (loc <= 8) {
    cout << "So" << endl;
  } else if (loc <= 10) {
    cout << "La" << endl;
  } else {
    cout << "Si" << endl;
  }
}
