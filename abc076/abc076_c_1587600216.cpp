/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author KY2001
 */


#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int bpm(int x, int y) {
  if (x == 0)
    return 0;
  else if (y == 0) {
    return 1;
  }
  int ans = 1;
  x %= MOD;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  for (int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
  }
  return ans;
}


class CDubiousDocument2 {
public:
	int solve(std::istream& cin, std::ostream& cout) {
          string S;
          string T;
          cin>>S>>T;
          int ind = -1;
          rep(i, S.size()-T.size()+1){
            rep(j, T.size()){
              if (S[i+j] != T[j] && S[i+j] != '?'){
                break;
              }else if (j == T.size()-1){
                ind = i;
              }
            }
          }
          if(ind == -1){
            cout<<"UNRESTORABLE"<<endl;
          }else{
            rep(i, T.size()){
              S[i+ind] = T[i];
            }
            rep(i, S.size()){
              if (S[i] == '?'){
                S[i] = 'a';
              }
            }
            cout<<S<<endl;
          }
	}
};


signed main() {
	CDubiousDocument2 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}