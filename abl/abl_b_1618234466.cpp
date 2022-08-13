#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A, B, C, D;
  cin>>A>>B>>C>>D;
  if (C <= B and A <= D){
    cout<<"Yes"<<endl;
  }else if (D <= A and C <= B){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
