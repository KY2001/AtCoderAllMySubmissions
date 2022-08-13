// clang-format off
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
//#define double __float80
using namespace std;
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)
#define _max(x) *max_element(ALL(x))
#define _min(x) *min_element(ALL(x))
#define _sum(x) accumulate(ALL(x), 0LL)

const int INF   = 1000000007;
// const int INF    = 1e13 + 7;
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-20;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
// clang-format on

void dijkstra(int x, int y, int dis, V<string> &c, VV<int> &distance, VV<int> &shortest_path, priority_queue<V<int>, VV<int>, greater<>> &pos) {
  if (c[x][y] != '#' and shortest_path[x][y] > dis + (c[x][y] - '0')) {
    shortest_path[x][y] = dis + (c[x][y] - '0');
    pos.push({shortest_path[x][y], x, y});
  }
}

bool task1(int x, int y, int &X, int &Y, int &now, VV<int> &shortest_path, V<string> &c) {
  if (now - (c[X][Y] - '0') == shortest_path[x][y]) {
    now -= (c[X][Y] - '0');
    X = x, Y = y;
    return true;
  }
  return false;
}

int calc_score(V<int> &p, VV<int> &distance) {
  int ret = 0;
  rep(i, p.size()) ret += distance[p[i]][p[(i + 1) % p.size()]];
  return ret;
}

string get_ans(V<int> &p, VV<string> &path) {
  string temp;
  int s                             = 0;
  rep(i, p.size()) if (p[i] == 0) s = i;
  rep(i, p.size()) temp += path[p[(s + i) % p.size()]][p[(s + i + 1) % p.size()]];
  return temp;
}

signed main() {
  random_device rnd;
  mt19937 mt(rnd());
  auto time_start = chrono::system_clock::now();
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int N, si, sj;
  cin >> N >> si >> sj;
  V<string> c(N + 2);
  c[0]     = string(N + 2, '#');
  c[N + 1] = string(N + 2, '#');
  rep(i, N) {
    cin >> c[i + 1];
    c[i + 1] = '#' + c[i + 1] + '#';
  }
  VVV<int> cross_point = {{{si + 1, sj + 1}}};
  rep2(i, 1, N + 1) {
    rep2(j, 1, N + 1) {
      if (c[i][j] != '#' and c[i][j + 1] != '#') {
        cross_point.emplace_back();
        while (1) {
          if (c[i + 1][j] != '#' or c[i - 1][j] != '#') {
            cross_point[cross_point.size() - 1].push_back({i, j});
          }
          if (c[i][j + 1] == '#') break;
          j++;
        }
      }
    }
  }
  rep2(i, 1, N + 1) {
    rep2(j, 1, N + 1) {
      if (c[j][i] != '#' and c[j + 1][i] != '#') {
        cross_point.emplace_back();
        while (1) {
          if (c[j][i + 1] != '#' or c[j][i - 1] != '#') {
            cross_point[cross_point.size() - 1].push_back({j, i});
          }
          if (c[j + 1][i] == '#') break;
          j++;
        }
      }
    }
  }
  map<V<int>, int> check;
  V<int> ok(cross_point.size());
  ok[0] = 1;
  VV<int> to_go;
  FOR(i, cross_point)
  FOR(j, i)
  check[j]++;
  to_go.emplace_back(cross_point[0][0]);
  check[cross_point[0][0]] = 0;
  rep(j, cross_point.size()) {
    FOR(k, cross_point[j]) {
      if (k == cross_point[0][0]) {
        ok[j] = true;
      }
    }
  }
  while (1) {
    if (_sum(ok) == ok.size()) break;
    map<V<int>, int> now;
    rep(i, cross_point.size()) if (not ok[i]) {
      FOR(j, cross_point[i])
      now[j]++;
    }
    int maxi = 0;
    FOR(i, now)
    chmax(maxi, i.se);
    FOR(i, now)
    if (i.se == maxi) {
      to_go.emplace_back(i.fi);
      rep(j, cross_point.size()) {
        FOR(k, cross_point[j])
        if (k == i.fi) ok[j] = 1;
      }
      break;
    }
  }
  int n                     = to_go.size();
  check                     = {};
  rep(i, n) check[to_go[i]] = i;
  VV<int> distance(n, V<int>(n, INF));
  VV<string> path(n, V<string>(n));
  rep(i, n) {
    priority_queue<V<int>, VV<int>, greater<>> pos;
    pos.push({0, to_go[i][0], to_go[i][1]});
    VV<int> shortest_path(N + 2, V<int>(N + 2, INF));
    shortest_path[to_go[i][0]][to_go[i][1]] = 0;
    while (pos.size()) {
      int x = pos.top()[1], y = pos.top()[2], dis = pos.top()[0];
      if (check.count({x, y})) chmin(distance[i][check[{x, y}]], dis);
      pos.pop();
      dijkstra(x + 1, y, dis, c, distance, shortest_path, pos);
      dijkstra(x - 1, y, dis, c, distance, shortest_path, pos);
      dijkstra(x, y + 1, dis, c, distance, shortest_path, pos);
      dijkstra(x, y - 1, dis, c, distance, shortest_path, pos);
    }
    rep(j, n) {
      if (i == j) continue;
      int x = to_go[j][0], y = to_go[j][1], now = distance[i][j];
      while (now) {
        if (task1(x + 1, y, x, y, now, shortest_path, c)) {
          path[i][j] += 'U';
          continue;
        }
        if (task1(x - 1, y, x, y, now, shortest_path, c)) {
          path[i][j] += 'D';
          continue;
        }
        if (task1(x, y + 1, x, y, now, shortest_path, c)) {
          path[i][j] += 'L';
          continue;
        }
        if (task1(x, y - 1, x, y, now, shortest_path, c)) {
          path[i][j] += 'R';
          continue;
        }
      }
      reverse(ALL(path[i][j]));
    }
  }
  string ret;
  int score = INF;
  V<int> p;
  rep(i, n) p.emplace_back(i);
  uniform_int_distribution<> rand1(0, n - 2);
  while (1) {
    int l = rand1(mt);
    int r = rand1(mt);
    while (l == r) r = rand1(mt);
    int prev = calc_score(p, distance);
    swap(p[l], p[r]);
    if (calc_score(p, distance) >= prev) {
      swap(p[l], p[r]);
    } else {
      chmin(score, calc_score(p, distance));
      ret = get_ans(p, path);
    }
    chrono::duration<float> time_duration = chrono::system_clock::now() - time_start;
    if (time_duration.count() > 2.99) break;
  }
  cout << ret << endl;
  // cout << score << endl;
}</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2021-08-07 18:56:06+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/ahc005/tasks/ahc005_a">A - Patrolling</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/ahc005/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">12602379</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">6509 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-success' data-toggle='tooltip' data-placement='top' title="Accepted">AC</span></td>
				</tr>
				
					<tr>
						<th>Exec Time</th>
						<td class="text-center">2997 ms</td>
					</tr>
					<tr>
						<th>Memory</th>
						<td class="text-center">4484 KB</td>
					</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In function ‘void dijkstra(int, int, int, V<std::__cxx11::basic_string<char> >&, VV<int>&, VV<int>&, std::priority_queue<std::vector<int>, std::vector<std::vector<int>, std::allocator<std::vector<int> > >, std::greater<void> >&)’:
./Main.cpp:32:61: warning: unused parameter ‘distance’ [-Wunused-parameter]
   32 | void dijkstra(int x, int y, int dis, V<string> &c, VV<int> &distance, VV<int> &shortest_path, priority_queue<V<int>, VV<int>, greater<>> &pos) {
      |                                                    ~~~~~~~~~^~~~~~~~
./Main.cpp: In function ‘int main()’:
./Main.cpp:125:18: warning: comparison of integer expressions of different signedness: ‘long long int’ and ‘std::vector<int>::size_type’ {aka ‘long unsigned int’} [-Wsign-compare]
  125 |     if (_sum(ok) == ok.size()) break;
      |                  ^
