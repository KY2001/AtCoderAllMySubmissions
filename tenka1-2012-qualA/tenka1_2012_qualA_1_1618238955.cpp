#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int soon = 1;
  int one = 0;
  int two_or_more = 0;
  for (int i = 0; i < n; i++){
    two_or_more += one;
    one = soon;
    soon = two_or_more;
  }
  cout << soon + one + two_or_more << endl;
}
