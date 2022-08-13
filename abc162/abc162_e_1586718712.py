#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <vector>
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define SQR(x) (x) * (x)
#define itn int

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
    if (((y >> i) & 1) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = SQR(x);
    x %= MOD;
  }
  return ans;
};
int LIST[100000 + 10]{};
signed main() {
  int N, K;
  cin >> N >> K;
  for (int i = 100000; i >= 1; i--) {
    LIST[i] = bpm(K / i, N) * i;
    for (int j = 2; i * j <= K; j++) {
      LIST[i] -= LIST[i * j] / (i * j) * i;
    }
  }
  int ans = accumulate(ALL(LIST), 0LL) % MOD;
  cout << ans << endl;
}