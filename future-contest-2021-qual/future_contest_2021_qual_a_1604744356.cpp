#pragma GCC optimize("Ofast")
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
bool in_x(int i) {
  return (X <= x[i + 1] and x[i + 1] <= x[i]) or (x[i] <= x[i + 1] and x[i + 1] <= X);
}

bool in_y(int i) {
  return (Y <= y[i + 1] and y[i + 1] <= y[i]) or (y[i] <= y[i + 1] and y[i + 1] <= Y);
}

pair<int, int> search_near(int i) {
  rep2(j, 0, 10) {
    rep2(k, 0, 10) {
      if (0 <= x[i] + j and x[i] + j <= 19 and 0 <= y[i] + k and y[i] + k <= 19) {
        if (!already[x[i] + j][y[i] + k]) {
          return {x[i] + j, y[i] + k};
        }
      }
      if (0 <= x[i] - j and x[i] - j <= 19 and 0 <= y[i] + k and y[i] + k <= 19) {
        if (!already[x[i] - j][y[i] + k]) {
          return {x[i] - j, y[i] + k};
        }
      }
      if (0 <= x[i] + j and x[i] + j <= 19 and 0 <= y[i] - k and y[i] - k <= 19) {
        if (!already[x[i] + j][y[i] - k]) {
          return {x[i] + j, y[i] - k};
        }
      }
      if (0 <= x[i] - j and x[i] - j <= 19 and 0 <= y[i] - k and y[i] - k <= 19) {
        if (!already[x[i] - j][y[i] - k]) {
          return {x[i] - j, y[i] - k};
        }
      }
    }
  }
  return pair<int, int>();
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
  vector<int> x_copy = x;
  vector<int> y_copy = y;
  already.assign(20, vector<bool>(20, false));
  rep(i, n) already[x[i]][y[i]] = true;
  rep(i, n - 1) {
    if (in_x(i) and in_y(i)) {
      take(i + 1);
      pair<int, int> place = search_near(i);
      put(place.first, place.second);
      already[x[i + 1]][y[i + 1]] = false;
      x[i + 1] = place.first, y[i + 1] = place.second;
      already[x[i + 1]][y[i + 1]] = true;
    }
    take(i);
    already[x[i]][y[i]] = false;
  }
  take(n - 1);
  score      = cost();
  int num    = 1;
  double neo = clock();
  int pp = 0, qq = 0;
  vector<int> now(12, 0);
  while (((clock()) - start) / CLOCKS_PER_SEC < 2.985) {
    pp++;
    now[num]++;
    if ((clock() - neo) / CLOCKS_PER_SEC > 0.5 and num < 10) {
      num++;
      neo = clock();
    }
    X = 0;
    Y = 0;
    x = x_copy, y = y_copy;
    already.assign(20, vector<bool>(20, false));
    rep(i, n) already[x[i]][y[i]] = true;
    temp_ans                      = {};
    vector<bool> when(n, false);
    rep(i, num) when[dist_i(mt)] = true;
    rep(i, n - 1) {
      if (in_x(i) and in_y(i)) {
        take_temp(i + 1);
        pair<int, int> place = search_near(i);
        put_temp(place.first, place.second);
        already[x[i + 1]][y[i + 1]] = false;
        x[i + 1] = place.first, y[i + 1] = place.second;
        already[x[i + 1]][y[i + 1]] = true;
      } else if (when[i]) {
        std::uniform_int_distribution<int> dist_ii(i + 1, n - 1);
        int which = dist_ii(mt);
        take_temp(which);
        pair<int, int> where;
        while (1) {
          if (!already[where.first][where.second]) break;
          where = {dist_xy(mt), dist_xy(mt)};
        }
        put_temp(where.first, where.second);
        already[x[which]][y[which]] = false;
        x[which] = where.first, y[which] = where.second;
        already[x[which]][y[which]] = true;
      }
      take_temp(i);
      already[x[i]][y[i]] = false;
    }
    take_temp(n - 1);
    int temp = cost_temp();
    if (temp > score and temp_ans.size() < 10000) {
      ans   = temp_ans;
      score = temp;
      neo   = clock();
      num   = 1;
      qq++;
    }
  }
  cout << ans << endl;
}