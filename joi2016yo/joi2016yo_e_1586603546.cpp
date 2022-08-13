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

#define MOD 1000000007
#define INF 1000000007

using namespace std;
struct _edge {
  int to, cost;
};
typedef pair<int, int> _P;
int _V;                 //do assign num of nodes
#define MAX_V 100010    //do change MAX_V if necessary
vector<_edge> G[MAX_V]; // do G[from] = {{to, cost}, ...}
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
bool check[100001]{};
int C[100001]{};
int main() {
  int N, M, K, S, P, Q, temp;
  cin >> N >> M >> K >> S >> P >> Q;
  for (int i = 0; i < K; i++) {
    cin >> temp;
    C[temp - 1] = 1;
  }
  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    if (!C[B - 1]) {
      G[A - 1].push_back({B - 1, P});
    } else {
      G[A - 1].push_back({B - 1, INF});
    }

    if (!C[A - 1]) {
      G[B - 1].push_back({A - 1, P});
    } else {
      G[B - 1].push_back({A - 1, INF});
    }
  }

  deque<vector<int>> pos;
  for (int i = 0; i < N; i++) {
    if (C[i]) {
      pos.push_back({i, 0});
      check[i] = true;
    }
  }
  while (!pos.empty()) {
    int now    = pos[0][0];
    int dis    = pos[0][1];
    check[now] = true;
    pos.pop_front();
    for (auto &i : G[now]) {
      for (auto &j : G[i.to]) {
        if (j.to == now && j.cost != INF) {
          j.cost = Q;
        }
        if (!check[i.to] && dis + 1 <= S) {
          pos.push_back({i.to, dis + 1});
        }
      }
    }
  }
  _V = N;
  for (auto &i : G[N - 1]) {
    for (int j = 0; j < G[i.to].size(); j++) {
      if (G[i.to][j].to == N - 1) {
        G[i.to][j].cost = 0;
      }
    }
  }
  dijkstra(0);
  cout << shortest_path[N - 1] << endl;
}
