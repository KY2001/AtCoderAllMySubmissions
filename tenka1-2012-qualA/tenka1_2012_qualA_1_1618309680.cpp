#include <bits/stdc++.h>
using namespace std;

int main(){
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  int zero = 1;
  int one = 0;
  int two_or_more = 0;
  for (int i = 0;i < n;i++){
    two_or_more += one;
    one = zero;
    zero = two_or_more;
  }
  cout << zero + one + two_or_more << endl;
}