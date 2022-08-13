#include <bits/stdc++.h>
#define int long long
#define endl '\n'
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

class DPairOfBalls {
  public:
    static void solve(istream &cin, ostream &cout) {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        int N, M, k, cnt = 0;
        cin >> N >> M;
        VV<int> a(M);
        map<int, V<int>> where;
        deque<int> possible;
        V<int> check(N);
        rep(i, M) {
            cin >> k;
            a[i].resize(k);
            rep(j, k) cin >> a[i][j], a[i][j]--;
            rep(j, k) where[a[i][j]].emplace_back(i);
        }
        rep(i, M) check[a[i].back()]++;
        rep(i, N) if (check[i] == 2) possible.emplace_back(i);
        if (possible.empty()) {
            cout << "No" << endl;
        } else {
            while (possible.size()) {
                int now = possible[0];
                cnt++;
                possible.pop_front();
                int c = where[now][0], d = where[now][1];
                a[c].pop_back();
                a[d].pop_back();
                if (a[c].size()) {
                    check[a[c].back()]++;
                    if (check[a[c].back()] == 2) {
                        possible.emplace_back(a[c].back());
                    }
                }
                if (a[d].size()) {
                    check[a[d].back()]++;
                    if (check[a[d].back()] == 2) {
                        possible.emplace_back(a[d].back());
                    }
                }
            }
            if (cnt == N) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
};


signed main() {
  DPairOfBalls solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
