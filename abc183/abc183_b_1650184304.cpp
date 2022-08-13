#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed << setprecision(15);
  // 次の行からコードを書く。
  double Sx, Sy, Gx, Gy;
  cin >> Sx >> Sy >> Gx >> Gy;
  cout << Sx + (Gx - Sx) * Sy/(Gy + Sy);
}