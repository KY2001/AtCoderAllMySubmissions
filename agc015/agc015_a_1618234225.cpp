#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N, A, B;
  cin>>N>>A>>B;
  if (B < A){
    cout<<0<<endl;
  }else if (N == 1 and A != B){
    cout<<0<<endl;
  }else if (N == 1){
    cout<<1<<endl;
  }else{
      cout<< (N-2)*(B-A)+1<<endl; 
  }
}
