#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)             // [0, b)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b) for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a) for (auto &i: a)
#define ALL(obj) begin(obj), end(obj)

using namespace std;

int n = 100;
int X = 0, Y = 0; //now
int score = 0;
vector<int> x;
vector<int> y;
vector<vector<bool>> already;
string ans{};
string temp_ans{};

inline int cost() {
  int ret = ans.size();
  FOR(i, ans)
  if (i == 'I' or i == 'O') ret--;
  return 4000 - ret;
}

inline int cost_temp() {
  int ret = temp_ans.size();
  FOR(i, temp_ans)
  if (i == 'I' or i == 'O') ret--;
  return 4000 - ret;
}

inline void take(int i) {
  if (x[i] >= X) {
    ans += string(x[i] - X, 'D');
  } else {
    ans += string(X - x[i], 'U');
  }
  if (y[i] >= Y) {
    ans += string(y[i] - Y, 'R');
  } else {
    ans += string(Y - y[i], 'L');
  }
  ans += 'I';
  X = x[i], Y = y[i];
}

inline void take_temp(int i) {
  if (x[i] >= X) {
    temp_ans += string(x[i] - X, 'D');
  } else {
    temp_ans += string(X - x[i], 'U');
  }
  if (y[i] >= Y) {
    temp_ans += string(y[i] - Y, 'R');
  } else {
    temp_ans += string(Y - y[i], 'L');
  }
  temp_ans += 'I';
  X = x[i], Y = y[i];
}

inline void put(int xx, int yy) {
  if (xx >= X) {
    ans += string(xx - X, 'D');
  } else {
    ans += string(X - xx, 'U');
  }
  if (yy >= Y) {
    ans += string(yy - Y, 'R');
  } else {
    ans += string(Y - yy, 'L');
  }
  ans += 'O';
  X = xx, Y = yy;
}

inline void put_temp(int xx, int yy) {
  if (xx >= X) {
    temp_ans += string(xx - X, 'D');
  } else {
    temp_ans += string(X - xx, 'U');
  }
  if (yy >= Y) {
    temp_ans += string(yy - Y, 'R');
  } else {
    temp_ans += string(Y - yy, 'L');
  }
  temp_ans += 'O';
  X = xx, Y = yy;
}
bool in_x(int i, int j) {
  return (X <= x[j] and x[j] <= x[i]) or (x[i] <= x[j] and x[j] <= X);
}

bool in_y(int i, int j) {
  return (Y <= y[j] and y[j] <= y[i]) or (y[i] <= y[j] and y[j] <= Y);
}
int dis(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
signed main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  double start = clock();
  std::mt19937 mt{std::random_device{}()};
  std::uniform_int_distribution<int> dist_i(0, 99);
  std::uniform_int_distribution<int> dist_xy(0, 19);
  x.assign(n, 0);
  y.assign(n, 0);
  rep(i, n) cin >> x[i] >> y[i];
  already.assign(20, vector<bool>(20, false));
  rep(i, n) already[x[i]][y[i]] = true;
  rep(i, n - 1) {
    vector<int> info{};
    int score_max = 0;
    rep2(j, i + 2, n - 2) {
      if (in_x(i, j) and in_y(i, j)) {
        rep2(k, min(x[j], x[i]), max(x[j], x[i])) {
          rep2(l, min(y[j], y[i]), max(y[j], y[i])) {
            if (!already[k][l])
              score_max = max(score_max, dis(j, j + 1) + dis(j, j - 1) - abs(x[j + 1] - k) - abs(y[j + 1] - l) - abs(x[j - 1] - k) - abs(y[j - 1] - l));
          }
        }
      }
    }
    if (score_max >= 1) {
      rep2(j, i + 2, n - 2) {
        if (in_x(i, j) and in_y(i, j)) {
          rep2(k, min(x[j], x[i]), max(x[j], x[i])) {
            rep2(l, min(y[j], y[i]), max(y[j], y[i])) {
              if (!already[k][l])
                if (dis(j, j + 1) + dis(j, j - 1) - abs(x[j + 1] - k) - abs(y[j + 1] - l) - abs(x[j - 1] - k) - abs(y[j - 1] - l) == score_max) {
                  info = {j, k, l};
                }
            }
          }
        }
      }
    }
    if (info.size()) {
      take(info[0]);
      already[x[info[0]]][y[info[0]]] = false;
      put(info[1], info[2]);
      x[info[0]]                      = info[1];
      y[info[0]]                      = info[2];
      already[x[info[0]]][y[info[0]]] = true;
    }
    take(i);
    already[x[i]][y[i]] = false;
  }
  take(n - 1);
  score = cost();
  cout << ans << endl;
}