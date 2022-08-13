/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
const int INF = (int)(1e13);

class L {
public:
  static void solve(istream &cin, ostream &cout) {
    int N;
    cin >> N;
    vector<deque<int>> T(N);
    rep(i, N) {
      int K;
      cin >> K;
      T[i].assign(K, 0);
      rep(j, K) cin >> T[i][j];
    }
    map<int, int> one;
    map<int, int> two;
    map<int, int> ones;
    map<int, int> twos;
    rep(i, N) {
      one[T[i][0]] = i;
      ones[i]      = T[i][0];
      T[i].pop_front();
      if (T[i].size()) {
        two[T[i][0]] = i;
        twos[i]      = T[i][0];
        T[i].pop_front();
      }
    }
    int M;
    cin >> M;
    rep(_, M) {
      int a;
      cin >> a;
      int maxi1     = one.rbegin()->first;
      int maxi1_ind = one.rbegin()->second;
      int maxi2     = -INF;
      int maxi2_ind = 0;
      if (two.size()) {
        maxi2     = two.rbegin()->first;
        maxi2_ind = two.rbegin()->second;
      }
      if (a == 2 and maxi2 > maxi1) {
        cout << maxi2 << endl;
        two.erase(maxi2);
        twos.erase(maxi2_ind);
        if (T[maxi2_ind].size()) {
          two[T[maxi2_ind][0]] = maxi2_ind;
          twos[maxi2_ind]      = T[maxi2_ind][0];
          T[maxi2_ind].pop_front();
        }
      } else {
        cout << maxi1 << endl;
        one.erase(maxi1);
        ones.erase(maxi1_ind);
        if (twos.count(maxi1_ind)) {
          one[twos[maxi1_ind]] = maxi1_ind;
          ones[maxi1_ind]      = twos[maxi1_ind];
          two.erase(twos[maxi1_ind]);
          twos.erase(maxi1_ind);
          if (T[maxi1_ind].size()) {
            two[T[maxi1_ind][0]] = maxi1_ind;
            twos[maxi1_ind]      = T[maxi1_ind][0];
            T[maxi1_ind].pop_front();
          }
        }
      }
    }
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  L solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}