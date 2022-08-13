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
// const int INF    = 1e18;
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

// ax+by=gcd(a,b) の解 (x,y) を計算
// ついでに gcd(a,b) を返す
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x2, y2;
    long long d = ext_gcd(b, a % b, x2, y2);
    x           = y2;
    y           = x2 - (a / b) * y2;
    return d;
}

// m を法としたときの a のモジュラ逆数を計算
long long mod_inv(long long a, long long m) {
    long long x, y;
    long long d = ext_gcd(a, m, x, y);
    if (d != 1) {
        // モジュラ逆数が存在しない
        return -1;
    }
    x %= m;
    if (x < 0) x += m; // 負の数の剰余を考慮
    return x;
}
// x % m[i] = r[i] % m[i] を満たす正で最小の x を返す
// i!=j に対して gcd(m[i], m[j])=1 であると仮定
// とりあえず解の存在判定は保留
long long garner(vector<long long> r, vector<long long> m) {
    int n            = r.size();
    long long m_prod = 1;           // m_prod には m[i] の積を入れていく
    long long x      = r[0] % m[0]; // 最初の条件を満たすような x の初期値
    for (int i = 1; i < n; i++) {
        m_prod *= m[i - 1]; // m の累積積を更新
        long long t = ((r[i] - x) * mod_inv(m_prod, m[i])) % m[i];
        if (t < 0) t += m[i]; // 負の数の剰余の対策
        x += t * m_prod;      // x を更新
    }
    return x;
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int T;
    cin >> T;
    rep(_, T) {
        int N, S, K;
        cin >> N >> S >> K;
        int x   = -1;
        int y   = -1;
        int GCD = ext_gcd(N, K, x, y);
        if (S % GCD) {
            cout << -1 << endl;
        } else {
            y *= -S / GCD;
            int a = N / gcd(N, K);
            if (y < 0) y += _ceil(abs(y), a) * a;
            if (y > 0) y -= (y / a) * a;
            cout << y << endl;
        }
    }
}