#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, A, B;
  cin>>N>>A>>B;
  if (B < A){
    cout<<0<<endl;
  }else{
      cout<< max(0, (N-2)*(B-A)+1)<<endl; 
  }
}
