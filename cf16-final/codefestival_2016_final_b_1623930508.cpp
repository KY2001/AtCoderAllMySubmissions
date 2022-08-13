#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int INF = (int)1000000000;
  for (int i = 1; i < INF; i++) {
    if (i * (i + 1) / 2 >= N) {
      for (int j = 1; j <= i; j++) {
        if (i * (i + 1) / 2 - j == N) continue;
        cout << j << endl;
      }
      break;
    }
  }
}
