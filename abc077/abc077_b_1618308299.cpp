#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  for (int k = 0;k < 1000000;k++){
    if (k * k > N){
      cout << (k-1)*(k-1) << endl;
      break;
    }
  }
}