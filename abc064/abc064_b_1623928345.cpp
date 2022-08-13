#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  cout << max_element(begin(a), end(a)).operator*() - min_element(begin(a), end(a)).operator*() << endl;
}
