#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<vector<int>> JOI(N + 1, vector<int>(3));
  for (int i = 0; i < N; i++) {
    JOI[i + 1] = JOI[i];
    if (S[i] == 'J') JOI[i + 1][0]++;
    if (S[i] == 'O') JOI[i + 1][1]++;
    if (S[i] == 'I') JOI[i + 1][2]++;
  }
  map<vector<int>, vector<int>> calc;
  for (int i = 0; i < N + 1; i++) {
    int MIN = min({JOI[i][0], JOI[i][1], JOI[i][2]});
    for (int j = 0; j < 3; j++) JOI[i][j] -= MIN;
    calc[JOI[i]].emplace_back(i);
  }
  int ans = 0;
  for (auto &i: calc) {
    int val = max_element(begin(i.second), end(i.second)).operator*() - min_element(begin(i.second), end(i.second)).operator*();
    if (val > ans) ans = val;
  }
  cout << ans << endl;
}