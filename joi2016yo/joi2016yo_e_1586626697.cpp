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

#define MOD (int)1e9 + 7
#define INF (int)1e15
using namespace std;
typedef long long ll;

struct _edge {
  ll to, cost;
};
typedef pair<ll, ll> _P;
ll _V;                  //do assign num of nodes
#define MAX_V 100000    //do change MAX_V if necessary
vector<_edge> G[MAX_V]; // do G[from] = {to, cost}
ll shortest_path[MAX_V];
void dijkstra(ll s) {
  priority_queue<_P, vector<_P>, greater<_P>> que;
  fill(shortest_path, shortest_path + _V, INF);
  shortest_path[s] = 0;
  que.push(_P(0, s));

  while (!que.empty()) {
    _P p = que.top();
    que.pop();
    ll v = p.second;
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
ll check[100000]{};
int main() {
  ll N, M, K, S, P, Q;
  cin >> N >> M >> K >> S >> P >> Q;
  _V = N;
  vector<ll> C(K);
  for (ll i = 0; i < K; i++) {
    cin >> C[i];
    check[C[i] - 1] = 2;
  }
  ll A, B;
  for (ll i = 0; i < M; i++) {
    cin >> A >> B;
    G[A - 1].push_back({B - 1, P});
    G[B - 1].push_back({A - 1, P});
  }
  deque<_P> pos;
  ll check2[100000]{};
  for (ll i = 0; i < K; i++) {
    pos.emplace_back(C[i] - 1, 0);
    check2[C[i] - 1] = 1;
  }
  ll now, dis;
  while (!pos.empty()) {
    now = pos[0].first;
    dis = pos[0].second;
    pos.pop_front();
    for (auto &i : G[now]) {
      if (!check2[i.to]) {
        if (dis + 2 <= S) {
          pos.emplace_back(i.to, dis + 1);
          check[i.to]  = 1;
          check2[i.to] = 1;
        } else if (dis + 1 <= S) {
          check[i.to]  = 1;
          check2[i.to] = 1;
        }
      }
    }
  }
  for (ll i = 0; i < N; i++) {
    for (auto &j : G[i]) {
      if (j.to == N - 1) {
        j.cost = 0;
      } else {
        if (check[j.to] == 2) {
          j.cost = INF;
        } else if (check[j.to] == 1) {
          j.cost = Q;
        }
      }
    }
  }
  dijkstra(0);
  cout << shortest_path[N - 1] << endl;
}
