#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <vector>
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define SQR(x) (x) * (x)
#define itn int

using namespace std;
using ll                = long long;
const int MOD           = (int)(1e9 + 7);
const int long long INF = (int long long)(1e13 + 7);

struct _edge {
  int to, cost;
};
typedef pair<int, int> _P;
int _V;                     //do assign num of nodes
const int MAX_V = (int)1e5; //do change MAX_V if necessary
vector<_edge> G[MAX_V];     // do G[from] = {to, cost}
int shortest_path[MAX_V];
void dijkstra(int s) {
  priority_queue<_P, vector<_P>, greater<_P>> que;
  fill(shortest_path, shortest_path + _V, INF);
  shortest_path[s] = 0;
  que.push(_P(0, s));

  while (!que.empty()) {
    _P p = que.top();
    que.pop();
    int v = p.second;
    if (shortest_path[v] < p.first) continue;
    for (auto &G_v_i : G[v]) {
      _edge e = G_v_i;
      if (shortest_path[e.to] > shortest_path[v] + e.cost) {
        shortest_path[e.to] = shortest_path[v] + e.cost;
        que.push(_P(shortest_path[e.to], e.to));
      }
    }
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  _V = N;
  vector<int> C(N);
  vector<int> R(N);
  REP(i, N) {
    cin >> C[i] >> R[i];
  }
  int A, B;
  vector<vector<int>> road(N);
  REP(i, K) {
    cin >> A >> B;
    road[A - 1].push_back(B - 1);
    road[B - 1].push_back(A - 1);
  }
  deque<_P> pos;
  int now, dis;
  vector<int> check(N);
  REP(i, N) {
    fill(ALL(check), 1);
    pos.emplace_back(i, 0);
    check[i] = 0;
    while (!pos.empty()) {
      now = pos[0].first;
      dis = pos[0].second;
      for (auto &j : road[now]) {
        if (check[j]) {
          if (dis + 1 <= R[i]) {
            pos.emplace_back(j, dis + 1);
            G[i].push_back({j, C[i]});
            check[j] = 0;
          }
        }
      }
      pos.pop_front();
    }
  }
  dijkstra(0);
  cout << shortest_path[N - 1] << endl;
}
