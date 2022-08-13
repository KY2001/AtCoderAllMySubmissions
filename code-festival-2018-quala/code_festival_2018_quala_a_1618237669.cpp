#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, S;
  cin >> A>> B>>C>>S;
  if (A + B + C <= S and A + B + C + 3 <= S){
    cout<< "Yes"<<endl;
  }else{
    cout<< "No"<<endl;
  }
}
