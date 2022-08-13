#include <bits/stdc++.h>
using namespace std;

int main(){
  double Sx, Sy, Gx, Gy;
  cin >> Sx >> Sy >> Gx >> Gy;
  cout << Sx + (Gx - Sx) * Sy/(Sy + Gy) << endl;
}