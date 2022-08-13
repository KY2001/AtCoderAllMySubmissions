#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n;
  vector<int> cum_sum(1000000 + 2);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    cum_sum[a]++;
    cum_sum[b + 1]--;
  }
  for (int i = 0; i < 1000000 + 1; i++) cum_sum[i + 1] += cum_sum[i];
  cout << max_element(begin(cum_sum), end(cum_sum)).operator*() << endl;
}