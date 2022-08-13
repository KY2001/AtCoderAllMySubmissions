#include "algorithm"
#include "cmath"
#include "iostream"
#include "map"
#include "string"
#include "unordered_map"
#include "vector"
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
using namespace std; // std::を省略して書くことができる

int ans[100000]{};
int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> cum_sum;
  vector<int> cum_sum_R;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'L') {
      cum_sum.push_back(1);
      cum_sum_R.push_back(0);
    } else {
      cum_sum.push_back(0);
      cum_sum_R.push_back(1);
    }
  }
  for (int i = 0; i < N - 1; i++) {
    cum_sum[i + 1] = cum_sum[i] + cum_sum[i + 1];
    cum_sum_R[i + 1] = cum_sum_R[i] + cum_sum_R[i + 1];
  }
  for (int i = 0; i < N; i++) {
    if (S[i] == 'R') {
      auto iter = lower_bound(cum_sum.begin(), cum_sum.end(), cum_sum[i] + 1);
      int ind = distance(cum_sum.begin(), iter);
      if ((ind - i) % 2 == 0) {
        ans[ind] += 1;
      } else {
        ans[ind - 1] += 1;
      }
    } else {
      auto iter =
          lower_bound(cum_sum_R.begin(), cum_sum_R.end(), cum_sum_R[i]);
      int ind = distance(cum_sum_R.begin(), iter);
      if ((i - ind) % 2 == 0) {
        ans[ind] += 1;
      } else {
        ans[ind + 1] += 1;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}