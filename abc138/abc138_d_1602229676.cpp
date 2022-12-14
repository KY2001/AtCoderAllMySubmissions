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
#define SUM(x)              accumulate(ALL(x), 0LL)
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
vector<int> already(1000000, 0);
void cum_sum(vector<vector<int>> &graph, vector<int> &score, int now) {
  already[now]++;
  FOR(i, graph[now]) {
    if (not already[i]) {
      score[i] += score[now];
      cum_sum(graph, score, i);
    }
  }
}

class DKi {
public:
  static void solve(istream &cin, ostream &cout) {
    already.assign(1000000, 0);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> graph(N);
    rep(i, N - 1) {
      int a, b;
      cin >> a >> b;
      graph[a - 1].emplace_back(b - 1);
      graph[b - 1].emplace_back(a - 1);
    }
    vector<int> score(N, 0);
    rep(i, Q) {
      int p, x;
      cin >> p >> x;
      score[p - 1] += x;
    }
    cum_sum(graph, score, 0);
    rep(i, N) {
      cout << score[i] << " ";
    }
    cout << endl;
  }
};


signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
  DKi solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
