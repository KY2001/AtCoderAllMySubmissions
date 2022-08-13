#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, A, B;
  cin >> N >> A>> B;
  if (B < A or (A == B and N <= 1)){
    cout << 0 << endl;
  }else{
      cout << (N - 2) * (B - A) + 1 << endl;
  }
}
