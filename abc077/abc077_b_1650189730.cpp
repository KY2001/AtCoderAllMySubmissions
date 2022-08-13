#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed << setprecision(15);
  // 次の行からコードを書く。
  int N;
  cin >> N;
  for (int k = 0; k < 100000; k++){
    if (k * k > N){
      cout << (k-1)*(k-1) << endl;
      break;
    }
  }
}