//@Author: KeinYukiyoshi

#define int long long
using namespace std;
#define stoi stoll
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

const int MOD   = 1000000007;
// const int MOD    = 998244353;
// const int INF    = (int)1e18;
// const int INF    = 10000000000007; // 1e13 + 7
// const int INF    = LLONG_MAX; // 9.2e18
const double EPS = 1e-8;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
int _pow(int a, int b) {int res = 1;for (a %= MOD; b; a = a * a % MOD, b >>= 1)if (b & 1) res = res * a % MOD;return res;}
struct mint {long long x;mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) { (x *= a.x) %= MOD;return *this; }mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; } mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long t) const {if (!t) return 1;mint a = pow(t >> 1);a *= a;if (t & 1) a *= *this;return a;}mint inv() const { return pow(MOD - 2); }mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }};istream &operator>>(istream &is, mint &a) { return is >> a.x; }ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }
// clang-format on

class GMixtureDrug {
public:
  static void solve(istream &cin, ostream &cout) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, M;
    cin >> N >> M;
    VV<int> graph(N);
    rep(i, M) {
      int a, b;
      cin >> a >> b;
      graph[a - 1].emplace_back(b - 1);
      graph[b - 1].emplace_back(a - 1);
    }
    if (N == 1) {
      cout << 1 << endl;
    } else {
      int n1 = N / 2, n2 = _ceil(N, 2);
      V<int> dp(1 << n2);
      rep(i, (1 << n2)) {
        int num = 0;
        rep(j, n2) {
          if ((i >> j) & 1) {
            num++;
            FOR(k, graph[n1 + j]) {
              if ((i >> (k - n1)) & 1 and k >= n1) {
                goto label;
              }
            }
          }
        }
        dp[i] = num;
        continue;
      label:;
        rep(j, n2) {
          if ((i >> j) & 1) {
            chmax(dp[i], dp[i ^ (1 << j)]);
          }
        }
      }
      int ans = 0;
      rep(i, (1 << n1)) {
        int num   = 0;
        int check = (1 << n2)-1;
        rep(j, n1) if ((i >> j) & 1) {
          num++;
          FOR(k, graph[j]) {
            if (k < n1) {
              if ((i >> k) & 1) goto label2;
            } else {
              if ((check >> (k - n1)) & 1) check -= (1 << (k - n1));
            }
          }
        }
        chmax(ans, num + dp[check]);
        continue;
      label2:;
      }
      cout << ans << endl;
    }
  }
};


signed main() {
  GMixtureDrug solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}


