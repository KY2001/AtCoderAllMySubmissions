#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  int max = a[0];
  int min = a[0];
  for (int i = 0; i < N; i++) {
    if (a[i] > max) max = a[i];
    if (a[i] < min) min = a[i];
  }
  cout << max - min << endl;
}
