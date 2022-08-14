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

class AThreeCellsPerRowAndColumn {
  public:
    static void solve(istream &cin, ostream &cout) {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
        int N;
        cin >> N;
        VV<string> lookup(10);
        lookup[6].resize(6);
        lookup[7].resize(7);
        lookup[8].resize(8);
        lookup[9].resize(9);
        rep(i, 6) lookup[6][i]                            = string(6, '.');
        rep(i, 7) lookup[7][i]                            = string(7, '.');
        rep(i, 8) lookup[8][i]                            = string(8, '.');
        rep(i, 9) lookup[9][i]                            = string(9, '.');
        rep(i, 6) rep(j, 3) lookup[6][i][(3 * i + j) % 6] = '#';
        rep(i, 9) rep(j, 3) lookup[9][i][(3 * i + j) % 9] = '#';
        lookup[7][0]                                      = "###....";
        lookup[7][1]                                      = "...###.";
        lookup[7][2]                                      = "###....";
        lookup[7][3]                                      = "...###.";
        lookup[7][4]                                      = "##....#";
        lookup[7][5]                                      = "..##..#";
        lookup[7][6]                                      = "....###";
        lookup[8][0]                                      = "###.....";
        lookup[8][1]                                      = "...###..";
        lookup[8][2]                                      = "#.....##";
        lookup[8][3]                                      = "##.....#";
        lookup[8][4]                                      = "..###...";
        lookup[8][5]                                      = ".....###";
        lookup[8][6]                                      = ".###....";
        lookup[8][7]                                      = "....###.";
        V<string> ans(N);
        rep(i, N) ans[i] = string(N, '.');
        if (N % 3 == 0) {
            rep(i, N) rep(j, 3) ans[i][(3 * i + j) % N] = '#';
        } else {
            int num;
            if (N % 4 == 0) num = (N - 8) / 4;
            if (N % 4 == 1) num = (N - 9) / 4;
            if (N % 4 == 2) num = (N - 6) / 4;
            if (N % 4 == 3) num = (N - 7) / 4;
            int plus = 0;
            rep(i, num) {
                ans[plus][plus]                 = '#';
                ans[plus][plus + 1]             = '#';
                ans[plus + 1][plus]             = '#';
                ans[plus][N - 1 - plus]         = '#';
                ans[plus + 1][N - 1 - plus]     = '#';
                ans[plus + 1][N - 1 - plus - 1] = '#';
                ans[N - 1 - plus][plus + 1]     = '#';
                ans[N - 1 - plus - 1][plus]     = '#';
                ans[N - 1 - plus - 1][plus + 1] = '#';
                ans[N - 1 - plus][N - 1 - plus] = '#';
                ans[N - 1 - plus][N - 2 - plus] = '#';
                ans[N - 2 - plus][N - 2 - plus] = '#';
                plus += 2;
            }
            int num2;
            if (N % 4 == 0) num2 = 8;
            if (N % 4 == 1) num2 = 9;
            if (N % 4 == 2) num2 = 6;
            if (N % 4 == 3) num2 = 7;
            rep(i, num2) rep(j, num2) ans[plus + i][plus + j] = lookup[num2][i][j];
        }
        rfor(i, ans) cout << i << endl;
        /*
        V<int> X(N);
        V<int> Y(N);
        rep(i, N) rep(j, N) if (ans[i][j] == '#') X[i]++, Y[j]++;
        rep(i, N) if (X[i] != 3 or Y[i] != 3) {
            cout << "no!" << endl;
            return;
        }
         */
    }
};


signed main() {
  AThreeCellsPerRowAndColumn solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
