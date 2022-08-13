#include "bits/stdc++.h"
#define int long long
#define rep(i, n)           for (int i = 0; i < (int)(n); i++)         // [0, b)
#define rep2(i, a, b)       for (int i = (int)(a); i < (int)(b); i++)  // [a, b)
#define rep3(i, a, b)       for (int i = (int)(a); i >= (int)(b); i--) // reversed [b, a] so [a, a-1, a-2, ..., b]
#define FOR(i, a)           for (auto &i : a)
#define ALL(obj)            begin(obj), end(obj)
#define MAX(x)              *max_element(ALL(x))
#define MIN(x)              *min_element(ALL(x))
#define SUM(x)              accumulate(ALL(x), 0LL)
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
const int MOD    = 998244353;
const int MOD2   = 1000000007;
const int INF    = (int)(1e13 + 7);
const double EPS = 1e-8;
const double PI  = acos(-1);

int CEIL(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); } //ceil() for int
int mod(int a, int b) { return a >= 0 ? a % b : a - (b * CEIL(a, b)); }             //always return positive num
int pow_mod(int a, int b) {                                                         //return x^y in order(log(y))
  int res = 1;
  for (a %= MOD; b; a = a * a % MOD, b >>= 1)
    if (b & 1) res = res * a % MOD;
  return res;
}

struct mint {
  long long x;
  mint(long long x = 0) : x(mod(x, MOD)) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(MOD - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

struct UnionFind {
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {} //0からn-1
  int find(int x) { return (d[x] < 0 ? x : d[x] = find(d[x])); }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};
int N;
bool possible(vector<pair<double, double>> &xy, double r) {
  UnionFind uf(xy.size());
  rep(i, N) {
    rep2(j, i + 1, xy.size()) {
      rep(k, xy.size()) {
        if (k != i and k != j) {
          if ((xy[i].first - xy[k].first) * (xy[i].first - xy[k].first) + (xy[i].second - xy[k].second) * (xy[i].second - xy[k].second) < r * r and (xy[j].first - xy[k].first) * (xy[j].first - xy[k].first) + (xy[j].second - xy[k].second) * (xy[j].second - xy[k].second) < r * r) {
            uf.unite(i, j);
            break;
          }
        }
      }
    }
  }
  rep2(i, N, N + 201) {
    rep2(j, N + 201, xy.size()) {
      if (uf.same(i, j)) {
        return false;
      }
    }
  }
  return true;
}

class FSilverWoods {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cin >> N;
    vector<pair<double, double>> xy(N);
    rep(i, N) cin >> xy[i].first >> xy[i].second;
    for (double i = -100; i < 101 - EPS; i += 1.0) {
      xy.emplace_back(i, 100);
    }
    for (double i = -100; i < 101 - EPS; i += 1.0) {
      xy.emplace_back(i, -100);
    }
    double R = 200;
    double L = 0;
    while (true) {
      double mid = (R + L) / 2;
      bool one   = possible(xy, mid);
      bool two   = possible(xy, mid + EPS);
      if (one and !two or R == 0 or L == 100) {
        cout << mid / 2 << endl;
        return;
      } else if (!one and !two) {
        R = mid;
      } else {
        L = mid;
      }
    }
  }
};
</pre>

			<h4>
				Submission Info
				
			</h4>
			
			<div class="panel panel-default"><table class="table table-bordered table-striped">
				<tr>
					<th class="col-sm-4">Submission Time</th>
					<td class="text-center"><time class='fixtime fixtime-second'>2020-11-01 22:48:00+0900</time></td>
				</tr>
				<tr>
					<th>Task</th>
					<td class="text-center"><a href="/contests/abc181/tasks/abc181_f">F - Silver Woods</a></td>
				</tr>
				<tr>
					<th>User</th>
					<td class="text-center"><a href="/users/KY2001">KY2001</a> <a href='/contests/abc181/submissions?f.User=KY2001'><span class='glyphicon glyphicon-search black' aria-hidden='true' data-toggle='tooltip' title='view KY2001's submissions'></span></a></td>
				</tr>
				<tr>
					<th>Language</th>
					<td class="text-center">C++ (GCC 9.2.1)</td>
				</tr>
				<tr>
					<th>Score</th>
					<td class="text-center">0</td>
				</tr>
				<tr>
					<th>Code Size</th>
					<td class="text-center">4516 Byte</td>
				</tr>
				<tr>
					<th>Status</th>
					<td id="judge-status" class="text-center"><span class='label label-warning' data-toggle='tooltip' data-placement='top' title="Compilation Error">CE</span></td>
				</tr>
				
			</table></div>

			
				<h4>Compile Error</h4>
				<pre>./Main.cpp: In static member function ‘static void FSilverWoods::solve(std::istream&, std::ostream&)’:
./Main.cpp:127:15: warning: suggest parentheses around ‘&&’ within ‘||’ [-Wparentheses]
  127 |       if (one and !two or R == 0 or L == 100) {
      |           ~~~~^~~~~~~~
/usr/lib/gcc/x86_64-linux-gnu/9/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status
