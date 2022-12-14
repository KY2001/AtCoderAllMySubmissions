/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Kein Yukiyoshi
 */

#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b)        for (int i = (int)(a); i < (int)(b); i++)
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define sum(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = (int)(1e9 + 7);
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-14;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int bpm(int a, int b) {                                                             //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

// 最小値のquery
template <class T>
struct SegmentTree {
private:
  int n    = 1;
  int init = INF;
  vector<T> data;

public:
  SegmentTree(vector<T> &v) {
    while (n < v.size()) n *= 2;
    data.assign(2 * n - 1, init);
    for (int i = 0; i < v.size(); i++) data[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--) data[i] = min(data[2 * i + 1], data[2 * i + 2]);
  }
  void update(int ind, T val) {
    ind += n - 1;
    data[ind] = val;
    while (ind > 0) {
      ind       = (ind - 1) / 2;
      data[ind] = min(data[2 * ind + 1], data[2 * ind + 2]);
    }
  }
  int now(int ind) {
    return data[ind + n - 1];
  }
  T query(int L, int R, int k = 0, int l = 0, int r = -1) { //[L, R)
    if (r < 0) r = n;
    if (r <= L || R <= l) return init;
    if (L <= l and r <= R) return data[k];
    return min(query(L, R, 2 * k + 1, l, (l + r) / 2), query(L, R, 2 * k + 2, (l + r) / 2, r));
  }
};

class ESmartInfants {
public:
  static void solve(istream &cin, ostream &cout) {
    int num = 200000;
    int N, Q;
    cin >> N >> Q;
    vector<int> first(num, INF);
    vector<multiset<int>> kinder(num);
    map<int, int> place;
    vector<int> rate(N);
    rep(i, N) {
      int A, B;
      cin >> A >> B;
      kinder[B - 1].insert(A);
      place[i] = B - 1;
      rate[i]  = A;
    }
    rep(i, num) {
      if (kinder[i].size()) {
        first[i] = kinder[i].rbegin().operator*();
      }
    }
    SegmentTree<int> seg(first);
    rep(_, Q) {
      int C, D;
      cin >> C >> D;
      int where = place[C - 1];
      kinder[where].erase(kinder[where].find(rate[C - 1]));
      kinder[D - 1].insert(rate[C - 1]);
      if (kinder[D - 1].size()) {
        if (kinder[D - 1].rbegin().operator*() != seg.now(D - 1)) {
          seg.update(D - 1, kinder[D - 1].rbegin().operator*());
        }
      } else {
        seg.update(D - 1, INF);
      }
      if (kinder[where].size()) {
        if (kinder[where].rbegin().operator*() != seg.now(where)) {
          seg.update(where, kinder[where].rbegin().operator*());
        }
      } else {
        seg.update(where, INF);
      }
      place[C - 1] = D - 1;
      cout << seg.query(0, num) << endl;
    }
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  ESmartInfants solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
