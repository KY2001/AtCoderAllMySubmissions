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

double start = clock();
V<node> abcd(2002);
int m = 50, n = 102;
int best_T = INF;
V<int> best_xy(n);
V<int> best_choice(m);
int change_num = 1;
int prev_update = 0;
int cnt = 0;

bool time_end() {
    if ((clock() - start) / CLOCKS_PER_SEC > 1.98) return true;
    return false;
}

int calc_dis(int a, int b) {
    return abs(abcd[a].x - abcd[b].x) + abs(abcd[a].y - abcd[b].y);
}

void task(V<int>& choice) {
    int T = 0;
    V<int> xy(102);
    xy[0] = 1000, xy[101] = 2001;
    unordered_set<int> remain;
    rfor(i, choice) remain.insert(i);
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
                break;
            }
        }
        T += MIN;
        remain.erase(remain.find(erase));
    }
    T += calc_dis(prev, 2001);
    if (T < best_T) {
        best_choice = choice;
        best_xy = xy;
        best_T = T;
        prev_update = cnt;
        // cout << change_num << " " << cnt << " " << best_T << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    std::random_device seed_gen;
    std::mt19937 mt(seed_gen());
    std::uniform_int_distribution<> rand1000(0, 999);
    std::uniform_int_distribution<> rand50(0, 49);
    rep(i, 1000) cin >> abcd[i].x >> abcd[i].y >> abcd[1001 + i].x >> abcd[1001 + i].y;
    abcd[1000] = {400, 400}, abcd[2001] = {400, 400};
    V<int> choice(50);
    rep(i, 50) best_choice[i] = i;
    while (!time_end()) {
        if (cnt - prev_update > 5000) change_num = 2;
        if (cnt - prev_update <= 5000) change_num = 1;
        cnt++;
        V<bool> contain(1000);
        rfor(i, best_choice) contain[i] = true;
        choice = best_choice;
        rep(__, change_num) {
            int a = rand50(mt);
            int b = rand1000(mt);
            if (!contain[b]) {
                contain[choice[a]] = false;
                contain[b] = true;
                choice[a] = b;
            }
        }
        task(choice);
    }
    cout << m << " ";
    rfor(i, best_choice) cout << i + 1 << " ";
    cout << endl;
    cout << n << " ";
    rfor(i, best_xy) cout << abcd[i].x << " " << abcd[i].y << " ";
    cout << endl;
    // cout << cnt << " " << prev_update << endl;
    // cout << _pow(10, 8) / (1000 + best_T) << endl;
}