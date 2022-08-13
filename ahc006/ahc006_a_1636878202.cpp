// clang-format off
#include <bits/stdc++.h>
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("unroll-loops")
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
const int INF    = INT_MAX; // 9.2e18
const double EPS = 1e-20;
const double PI  = 3.14159265358979;
template <class T> using V = vector<T>;
template <class T> using VV = vector<vector<T>>;
template <class T> using VVV = vector<vector<vector<T>>>;
template <class T, class S>  using P = pair<T, S>;
template<class T> bool chmax(T &a, const T b) {if (a < b) {a = b;return true;}return false;}
template<class T> bool chmin(T &a, const T b) {if (b < a) {a = b;return true;}return false;}
int _ceil(int a, int b) { return (a >= 0 ? (a + (b - 1)) / b : (a - (b - 1)) / b); }
template<class T> T chmod(T &a, T mod=MOD) {a =  a >= 0 ? a % mod : a - (mod * _ceil(a, mod)); return a;};
int _mod(int a, int mod=MOD) {return a >= 0 ? a % mod : a - (mod * _ceil(a, mod));}
double _mod(double a, int mod = MOD) { return fmod(a, mod) >= 0 ? fmod(a, mod) : fmod(a, mod) + mod; }
int _pow(int a, int b, int mod=MOD) {int res = 1;for (a %= mod; b; a = a * a % mod, b >>= 1)if (b & 1) res = res * a % mod;return res;}
vector<int> iota(int n){vector<int> ret(n); iota(begin(ret), end(ret), 0); return ret;}
struct mint {long long x;mint(long long x = 0): x((x % MOD + MOD) % MOD) {}mint operator-() const { return mint(-x); }mint &operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}mint &operator-=(const mint a) {if ((x += MOD - a.x) >= MOD) x -= MOD;return *this;}mint &operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}mint operator+(const mint a) const { return mint(*this) += a; }mint operator-(const mint a) const { return mint(*this) -= a; }mint operator*(const mint a) const { return mint(*this) *= a; }mint pow(long long n) const {mint ret(1), mul(x);while (n > 0) {if (n & 1) ret *= mul;mul *= mul;n >>= 1;}return ret;}mint inv() const {int a = x, b = MOD, u = 1, v = 0, t;while (b > 0) {t = a / b;swap(a -= t * b, b);swap(u -= t * v, v);}return mint(u);}mint &operator/=(const mint a) { return *this *= a.inv(); }mint operator/(const mint a) const { return mint(*this) /= a; }bool operator==(const mint a) const { return x == a.x; }bool operator!=(const mint a) const { return x != a.x; }friend istream &operator>>(istream &is, mint &a) { return is >> a.x; }friend ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }};
// clang-format on

struct node {
    int x;
    int y;
};

V<node> abcd(2002);

int calc_dis(int a, int b) {
    return abs(abcd[a].x - abcd[b].x) + abs(abcd[a].y - abcd[b].y);
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    V<int> xy(102);
    rep(i, 1000) cin >> abcd[i].x >> abcd[i].y >> abcd[1001 + i].x >> abcd[1001 + i].y;
    abcd[1000] = {400, 400}, abcd[2001] = {400, 400};
    xy[0] = 1000, xy[101] = 2001;
    unordered_multiset<int> remain;
    rep(i, 50) remain.insert(i);
    int now = 0;
    int prev = 1000;
    while (now++ < 100) {
        int MIN = INF, erase;
        rfor(i, remain) chmin(MIN, calc_dis(i, prev));
        rfor(i, remain) {
            if (calc_dis(i, prev) == MIN) {
                xy[now] = i;
                prev = i;
                if (i < 1001) remain.insert(i + 1001);
                erase = i;
                goto label;
            }
        }
    label:;
        remain.erase(remain.find(erase));
    }
    int m = 50, n = 102;
    cout << m << " ";
    rep(i, m) cout << i + 1 << " ";
    cout << endl;
    cout << n << " ";
    rfor(i, xy) cout << abcd[i].x << " " << abcd[i].y << " ";
    cout << endl;
}