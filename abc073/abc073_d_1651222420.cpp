// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("unroll-loops")
#define int long long
#define endl '\n'
//#define double __float80
using namespace std;
#define fi first
#define se second
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; i++)
#define rep2(i, a, b) for (int i = (int)(a), i##_len=(b); i < i##_len; i++)
#define rep3(i, a, b) for (int i = (int)(a), i##_len=(b); i >= i##_len; i--)
#define rfor(i, a) for (auto &i: a)
#define all(obj) begin(obj), end(obj)
#define _max(x) *max_element(all(x))
#define _min(x) *min_element(all(x))
#define _sum(x) accumulate(all(x), 0LL)

const int MOD   = 1000000007;
// const int MOD    = 998244353;
const int INF    = 1e18;
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
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
double _mod(double a, int mod = MOD) { return fmod(a, mod) >= 0 ? fmod(a, mod) : fmod(a, mod) + mod; }
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};
// clang-format on

#define MAX_V 300                // change if you need
int shortest_path[MAX_V][MAX_V]; // shortest_path[i][j] = cost(i→j) or INF
int _V;                          // num of nodes
void warshall_floyd() {
    for (int k = 0; k < _V; k++) shortest_path[k][k] = 0;
    for (int k = 0; k < _V; k++)
        for (int i = 0; i < _V; i++)
            for (int j = 0; j < _V; j++)
                shortest_path[i][j] = min(shortest_path[i][j], shortest_path[i][k] + shortest_path[k][j]);
};

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int N, M, R;
    cin >> N >> M >> R;
    _V = N;
    V<int> r(R), A(M), B(M), C(M);
    rfor(i, r) cin >> i;
    rep(i, MAX_V) rep(j, MAX_V) shortest_path[i][j] = INF;
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        shortest_path[A[i] - 1][B[i] - 1] = C[i];
        shortest_path[B[i] - 1][A[i] - 1] = C[i];
    }
    warshall_floyd();
    VV<int> dp(R, V<int>(1 << R, INF));
    rep(i, R) dp[i][(1 << i)] = 0;
    rep2(i, 1, (1 << R) - 1) rep(j, R) {
        if (not((i >> j) & 1)) continue;
        rep(k, R) if (not((i << k) & 1)) {
            chmin(dp[k][i ^ (1 << k)], dp[j][i] + shortest_path[r[j] - 1][r[k] - 1]);
        }
    }
    int ans = INF;
    rep(i, R) chmin(ans, dp[i][(1 << R) - 1]);
    cout << ans << endl;
}