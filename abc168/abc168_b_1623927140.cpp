#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  string S;
  cin >> K >> S;
  if (sizeof(S) / sizeof(S[0]) <= K) {
    cout << S << endl;
  } else {
    string ans;
    for (int i = 0; i < K; i++) ans += S[i];
    cout << ans + "..." << endl;
  }
}
