#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed << setprecision(15);
  // 次の行からコードを書く。
  int A, B, C, S;
  cin >> A >> B >> C >> S;
  if (A + B + C <= S and S <= A + B + C + 3){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}